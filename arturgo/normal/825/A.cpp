#include <iostream>
using namespace std;

int main() {
	int nbCars;
	cin >> nbCars;
	
	string chaine;
	cin >> chaine;
	
	int der = 0;
	for(int iCar = 0;iCar < nbCars;iCar++) {
		if(chaine[iCar] == '1')
			der++;
		else {
			cout << der;
			der = 0;
		}
	}
	
	cout << der << endl;
}