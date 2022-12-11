#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	string nb;
	cin >> nb;
	
	int posVirg = (int)nb.size(), posPreNon = -1, posDerNon = -1;
	
	for(int iCar = 0;iCar < (int)nb.size();iCar++) {
		if(nb[iCar] == '.') {
			posVirg = iCar;
		}
		else {
			if(nb[iCar] != '0' && posPreNon == -1) {
				posPreNon = iCar;
			}
			if(nb[iCar] != '0') {
				posDerNon = iCar;
			}
		}
	}
	
	if(posPreNon == posDerNon) {
		cout << nb[posPreNon];
	}
	else {
		cout << nb[posPreNon] << ".";
		for(int iCar = posPreNon + 1;iCar <= posDerNon;iCar++) {
			if(nb[iCar] != '.') {
				cout << nb[iCar];
			}
		}
	}
	
	if(posPreNon + 1 != posVirg) {
		if(posPreNon < posVirg) {
			cout << "E" << posVirg - posPreNon - 1;
		}
		else {
			cout << "E" << posVirg - posPreNon;
		}
	}
	return 0;
}