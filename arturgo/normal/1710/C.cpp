#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
string chaine;

int masquesMaxs[8] = {2, 5, 1, 6, 3, 4, 0, 7};
int masquesPlaces[8] = {1, 1, 2, 2, 4, 4, 0, 0};

bool estPasse[200 * 1000 + 42][8][8];
int dyn[200 * 1000 + 42][8][8];

int nbPossibles(int iBit, int maxs, int places) {
	if(iBit >= (int)chaine.size())
		return places == 7;
	
	if(estPasse[iBit][maxs][places])
		return dyn[iBit][maxs][places];
	estPasse[iBit][maxs][places] = true;
	
	int somme = 0;
	
	for(int iMasque = 0;iMasque < 8;iMasque++) {
		if(chaine[iBit] == '0' && (masquesMaxs[iMasque] & maxs) != 0) continue;
		
		if(chaine[iBit] == '1')
			somme += nbPossibles(iBit + 1, 
			maxs & masquesMaxs[iMasque],
			places | masquesPlaces[iMasque]);
		else
			somme += nbPossibles(iBit + 1, 
			maxs,
			places | masquesPlaces[iMasque]);
		
		somme %= MOD;
	}
	
	dyn[iBit][maxs][places] = somme;
	return somme;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> chaine;
	
	cout << nbPossibles(0, 7, 0) << endl;
	return 0;
}