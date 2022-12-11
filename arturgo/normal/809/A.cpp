#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

int nbOrdis;
int positions[300 * 1000];
long long puis2[300 * 1000 + 1];

int main() {
	cin >> nbOrdis;
	
	for(int iOrdi = 0;iOrdi < nbOrdis;iOrdi++) {
		cin >> positions[iOrdi];
	}
	
	puis2[0] = 1;
	for(int i = 1;i <= 300 * 1000;i++) {
		puis2[i] = (2* puis2[i-1]) % MOD;
	}
	
	sort(positions, positions + nbOrdis);
	
	long long total = 0;
	
	long long nbGauche = 0;
	for(int iOrdi = 0;iOrdi < nbOrdis;iOrdi++) {
		int nbDroite = nbOrdis - nbGauche - 1;
		
		total -= positions[iOrdi] * puis2[nbDroite];
		total += positions[iOrdi] * puis2[nbGauche];
		total %= MOD;
		
		nbGauche++;
	}
	
	cout << total << endl;
	return 0;
}