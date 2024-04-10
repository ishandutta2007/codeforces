#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

int derChange[2000 * 1000];
long long hashs[2000 * 1000];
long long puis[200 * 1000];
long long fact[2000 * 1000];

int main() {
	int nbArenes, nbTypes;
	cin >> nbArenes >> nbTypes;
	
	puis[0] = 1;
	for(int iFois = 1;iFois < 200 * 1000;iFois++) {
		puis[iFois] = 30001 * puis[iFois - 1];
	}
	
	fact[0] = 1;
	for(int iFois = 1;iFois < 2000 * 1000;iFois++) {
		fact[iFois] = fact[iFois - 1] * iFois;
		fact[iFois] %= MOD;
	}
	
	for(int iArene = 0;iArene < nbArenes;iArene++) {
		int nbPokemons;
		cin >> nbPokemons;
		
		for(int iPokemon = 0;iPokemon < nbPokemons;iPokemon++) {
			int type;
			cin >> type;
			
			hashs[type] *= puis[iArene - derChange[type]];
			derChange[type] = iArene;
			
			hashs[type]++;
		}
	}
	
	for(int iType = 1;iType <= nbTypes;iType++) {
		hashs[iType] *= puis[nbArenes - derChange[iType]];
	}
	
	sort(hashs + 1, hashs + nbTypes + 1);
	
	long long nbCombis = 1;
	for(int deb = 1;deb <= nbTypes;) {
		int fin = deb;
		while(fin <= nbTypes && hashs[fin] == hashs[deb]) {
			fin++;
		}
		
		nbCombis *= fact[fin - deb];
		nbCombis %= MOD;
		
		deb = fin;
	}
	
	cout << nbCombis << endl;
	return 0;
}