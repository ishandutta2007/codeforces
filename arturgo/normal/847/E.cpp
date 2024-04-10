#include <iostream>
#include <list>
#include <vector>
using namespace std;

string terrain;

bool estPossible(int temps) {
	list<int> etoiles, hommes;
	
	for(int iCar = 0;iCar < (int)terrain.size();iCar++) {
		if(terrain[iCar] == 'P')
			hommes.push_back(iCar);
		if(terrain[iCar] == '*')
			etoiles.push_back(iCar);
	}
	
	for(int homme : hommes) {
		int deb = homme, fin = homme;
		
		while(!etoiles.empty()) {
			deb = min(etoiles.front(), deb);
			fin = max(etoiles.front(), fin);
			
			int t = fin - deb + min(fin - homme, homme - deb);
			if(t <= temps)
				etoiles.pop_front();
			else
				break;
		}
	}
	
	return etoiles.empty();
}

int main() {
	ios_base::sync_with_stdio(false);
	int nbCars;
	cin >> nbCars;
	
	cin >> terrain;
	
	int deb = 0, fin = 200000;
	while(deb + 1 < fin) {
		int mil = (deb + fin) / 2;
		
		if(estPossible(mil)) {
			fin = mil;
		}
		else {
			deb = mil;
		}
	}
	
	cout << deb + 1 << endl;
	return 0;
}