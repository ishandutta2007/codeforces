#include <iostream>
using namespace std;

const int MOD = 1e8;
const int MAX_FANTASSINS = 200, MAX_CAVALIERS = 200;

int nbManieres[MAX_FANTASSINS][MAX_CAVALIERS][2];

int maxType[2];

int main() {
	int nbFantassins, nbCavaliers;
	cin >> nbFantassins >> nbCavaliers >> maxType[0] >> maxType[1];

	nbManieres[0][0][0] = nbManieres[0][0][1] = 1;

	for(int nSoldat = 0;nSoldat <= nbFantassins + nbCavaliers;nSoldat++) {
		for(int nType0 = 0;nType0 <= nSoldat;nType0++) {
			int nType1 = nSoldat - nType0;
			for(int type = 0;type < 2;type++) {
				for(int tailleGroupe = 1;tailleGroupe <= maxType[type];tailleGroupe++) {
					nbManieres[nType1][nType0 + tailleGroupe][1 - type] 
						+= nbManieres[nType0][nType1][type];
					nbManieres[nType1][nType0 + tailleGroupe][1 - type] %= MOD;
				}
			}
		}
	}

	cout << (nbManieres[nbFantassins][nbCavaliers][0] + nbManieres[nbCavaliers][nbFantassins][1]) % MOD << endl;
	return 0;
}