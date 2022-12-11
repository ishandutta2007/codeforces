#include <iostream>
using namespace std;

int occs[2][1024];

int main() {
	int nbSoldats, nbEtapes, nombre;
	cin >> nbSoldats >> nbEtapes >> nombre;
	
	for(int iSoldat = 0;iSoldat < nbSoldats;iSoldat++) {
		int force;
		cin >> force;
		
		occs[0][force]++;
	}
	
	for(int iEtape = 0;iEtape < nbEtapes;iEtape++) {
		int mod = iEtape & 1;
		int aut = 1 - mod;
		
		int nbAvant = 0;
		for(int iPos = 0;iPos < 1024;iPos++) {
			int nbChange = (occs[mod][iPos] + 1 - (nbAvant % 2)) / 2;
			int nbReste = occs[mod][iPos] - nbChange;
			
			occs[aut][iPos] += nbReste;
			occs[aut][iPos ^ nombre] += nbChange;
			
			nbAvant += occs[mod][iPos];
			occs[mod][iPos] = 0;
		}
	}
	
	int mod = nbEtapes & 1;
	
	int mini = 1024;
	int maxi = 0;
	
	for(int iPos = 0;iPos < 1024;iPos++) {
		if(occs[mod][iPos] != 0) {
			mini = min(mini, iPos);
			maxi = max(maxi, iPos);
		}
	}
	
	cout << maxi << " " << mini << endl;
	return 0;
}