#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

int tempsDispo[100];

int main() {
	int nbServeurs, nbTaches;
	cin >> nbServeurs >> nbTaches;
	
	for(int iTache = 0;iTache < nbTaches;iTache++) {
		int debut, nbs, duree;
		cin >> debut >> nbs >> duree;
		
		int nbLibres = count_if(tempsDispo, tempsDispo + nbServeurs, [&](int t) { return t <= debut; });
		
		if(nbLibres < nbs) {
			cout << -1 << endl;
		}
		else {
			int nbFois = 0;
			int somme = 0;
			
			for(int iPos = 0;iPos < nbServeurs && nbFois < nbs;iPos++) {
				if(tempsDispo[iPos] <= debut) {
					tempsDispo[iPos] = debut + duree;
					nbFois++;
					somme += iPos + 1;
				}
			}
			
			cout << somme << endl;
		}
	}
	
	return 0;
}