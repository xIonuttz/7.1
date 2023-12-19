#include <iostream>
#include <string>

class Wheel {
private:
    std::string model;  // Model information specific to the wheel

public:
    // Default constructor for Wheel
    Wheel() : model("Default_Wheel") {}

    // Constructor for Wheel with a specific model
    Wheel(const std::string& model) : model(model) {}

    // Getter for the wheel model
    std::string getModel() const {
        return model;
    }
};

class Vehicle {
protected:
    Wheel wheels[4];  // Array to store four wheels

public:
    // Default constructor for Vehicle
    Vehicle() : wheels{ Wheel(), Wheel(), Wheel(), Wheel() } {}

    // Display information about the vehicle
    virtual void displayInfo() const = 0;

    // Method to replace a wheel
    void replaceWheel(int wheelIndex, const Wheel& newWheel) {
        if (wheelIndex >= 0 && wheelIndex < 4) {
            std::cout << "Replacing wheel at index " << wheelIndex << " with a new wheel of model " << newWheel.getModel() << ".\n";
            wheels[wheelIndex] = newWheel;
        }
        else {
            std::cerr << "Invalid wheel index.\n";
        }
    }

    // Method to remove a wheel
    void removeWheel(int wheelIndex) {
        if (wheelIndex >= 0 && wheelIndex < 4) {
            std::cout << "Removing wheel at index " << wheelIndex << ".\n";
            // You can implement additional logic here if needed
        }
        else {
            std::cerr << "Invalid wheel index.\n";
        }
    }
};

class Hummer : public Vehicle {
public:
    // Display information about the Hummer
    void displayInfo() const override {
        std::cout << "Hummer vehicle with the following wheels:\n";
        for (int i = 0; i < 4; ++i) {
            std::cout << "Wheel " << i + 1 << ": " << wheels[i].getModel() << std::endl;
        }
    }
};

class Carriage : public Vehicle {
public:
    // Display information about the Carriage
    void displayInfo() const override {
        std::cout << "Carriage vehicle with the following wheels:\n";
        for (int i = 0; i < 4; ++i) {
            std::cout << "Wheel " << i + 1 << ": " << wheels[i].getModel() << std::endl;
        }
    }
};

int main() {
    // Creating vehicles with the default constructor
    Hummer hummer;
    Carriage carriage;

    // Displaying initial information about the vehicles
    hummer.displayInfo();
    std::cout << "---------------------\n";
    carriage.displayInfo();

    // Replace a wheel for the Hummer
    Wheel newHummerWheel("New_Hummer_Wheel");
    hummer.replaceWheel(2, newHummerWheel);

    // Remove a wheel for the Carriage
    carriage.removeWheel(3);

    // Display updated information about the vehicles
    std::cout << "\nUpdated information after wheel operations:\n";
    hummer.displayInfo();
    std::cout << "---------------------\n";
    carriage.displayInfo();

    return 0;
}
