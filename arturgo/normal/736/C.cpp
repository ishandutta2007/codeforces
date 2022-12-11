#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int MAX_NB_NOEUDS = 100;
const int MOD = 1000 * 1000 * 1000 + 7;

struct Resultat {
	vector<vector<int> > nombre;
	Resultat() {
		nombre = vector<vector<int> >(22, vector<int>(22, 0));
	}
};

int nbNoeuds, maxDist;
vector<int> voisins[MAX_NB_NOEUDS];
vector<Resultat> dyn(MAX_NB_NOEUDS, Resultat());

void calculeDyn(int noeud, int parent) {
	dyn[noeud].nombre[1][0] = 1;
	dyn[noeud].nombre[0][maxDist] = 1;
	
	for(int voisin : voisins[noeud]) {
		if(voisin != parent) {
			calculeDyn(voisin, noeud);
			
			Resultat res;
for(int iDB1 = 0;iDB1 <= maxDist;iDB1++) {
	for(int iDB2 = 0;iDB2 <= maxDist;iDB2++) {
		for(int iDN1 = 0;iDN1 <= maxDist;iDN1++) {
			for(int iDN2 = 0;iDN2 <= maxDist;iDN2++) {
				int dB = max(iDN2 >= iDB1 ? 0 : iDB1, iDN1 >= iDB2 ? 0 : iDB2 + 1);
				int dN = max(iDN1, iDN2 - 1);
				res.nombre[dB][dN] = (res.nombre[dB][dN] + (long long)dyn[noeud].nombre[iDB1][iDN1] * dyn[voisin].nombre[iDB2][iDN2]) % MOD;
			}
		}
	}
}

			dyn[noeud] = res;
		}
	}
}

int main() {
	cin >> nbNoeuds >> maxDist;
	
	for(int iArc = 0;iArc < nbNoeuds - 1;iArc++) {
		int debut, fin;
		cin >> debut >> fin;
		voisins[debut - 1].push_back(fin - 1);
		voisins[fin - 1].push_back(debut - 1);
	}
	
	calculeDyn(0, -1);
	
	int somme = 0;
	for(int iDist = 0;iDist <= maxDist;iDist++) {
		somme = (somme + dyn[0].nombre[0][iDist]) % MOD;
	}
	
	cout << somme << endl;
	return 0;
}