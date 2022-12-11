#include <iostream>
#include <algorithm>
using namespace std;

int forces[100];

int main() {
	int nbBoites;
	cin >> nbBoites;
	
	for(int iBoite = 0;iBoite < nbBoites;iBoite++) {
		cin >> forces[iBoite];
	}
	
	sort(forces, forces + nbBoites);
	
	for(int nbPiles = 1;nbPiles <= nbBoites;nbPiles++) {
		bool estPossible = true;
		
		for(int iBoite = 0;iBoite < nbBoites;iBoite++) {
			if(forces[iBoite] < iBoite / nbPiles) {
				estPossible = false;
			}
		}
		
		if(estPossible) {
			cout << nbPiles << endl;
			return 0;
		}
	}
	return 0;
}