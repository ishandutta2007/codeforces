#include <iostream>
#include <algorithm>
using namespace std;

int nbPiles, nbLarbins;
int tailles[200 * 1000];

bool estPossible(long long temps) {
	long long curPile = 0, reste = tailles[0];
	for(int iLarbin = 0;iLarbin < nbLarbins;iLarbin++) {
		long long resteTemps = temps - curPile - 1;
		while(resteTemps >= reste) {
			resteTemps -= reste + 1;
			curPile++;
			if(curPile == nbPiles)
				return true;
			reste = tailles[curPile];
		}
		reste -= resteTemps;
	}
	return false;
}

int main() {
	cin >> nbPiles >> nbLarbins;
	
	for(int iPile = 0;iPile < nbPiles;iPile++) {
		cin >> tailles[iPile];
	}
	
	while(nbPiles != 0 && tailles[nbPiles - 1] == 0) {
		nbPiles--;
	}
	
	if(nbPiles == 0) {
		cout << 0 << endl;
		return 0;
	}
	
	long long debut = 0, fin = (long long)1000 * 1000 * 1000 * 1000 * 1000;
	while(debut + 1 < fin) {
		long long mil = (debut + fin) / 2;
		if(estPossible(mil)) {
			fin = mil;
		}
		else {
			debut = mil;
		}
	}
	
	cout << debut + 1 << endl;
	return 0;
}