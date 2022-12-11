#include <iostream>
#include <vector>
using namespace std;

int tChaine, nbCars, tPalin;

vector<int> voisins[2000];
bool estPasse[2000];

void ajoute(int deb, int fin) {
	voisins[deb].push_back(fin);
	voisins[fin].push_back(deb);
}

void colorie(int pos) {
	if(estPasse[pos])
		return;
	estPasse[pos] = true;
	
	for(int voisin : voisins[pos]) {
		colorie(voisin);
	}
}

int main() {
	cin >> tChaine >> nbCars >> tPalin;
	
	for(int iPos = 0;iPos + tPalin <= tChaine;iPos++) {
		for(int iDec = 0;iDec < tPalin;iDec++) {
			ajoute(iPos + iDec, iPos + tPalin - iDec - 1);
		}
	}
	
	long long possibles = 1;
	for(int iPos = 0;iPos < tChaine;iPos++) {
		if(!estPasse[iPos]) {
			possibles *= nbCars;
			possibles %= 1000000007;
			colorie(iPos);
		}
	}
	
	cout << possibles << endl;
	return 0;
}