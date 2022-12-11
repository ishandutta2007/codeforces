#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;
const int MAX_TAILLE = 2000 * 1000;

int nbLettres;
string lettres;

int hashAvant[MAX_TAILLE + 1];
int p31[MAX_TAILLE + 1];

int h(int deb, int fin) {
	return ((hashAvant[fin] - hashAvant[deb]) * (long long)p31[MAX_TAILLE - deb] % MOD + MOD) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nbLettres;
	cin >> lettres;
	
	hashAvant[0] = 0;
	p31[0] = 1;
	for(int iH = 0;iH < MAX_TAILLE;iH++) {
		p31[iH + 1] = 31ll * p31[iH] % MOD;
	}
	
	for(int iLettre = 0;iLettre < nbLettres;iLettre++) {
		hashAvant[iLettre + 1] = (hashAvant[iLettre] + p31[iLettre] * (long long)(lettres[iLettre] - 'a')) % MOD;
	}
	
	vector<int> tailles;
	
	int curTaille = -1;
	for(int iTaille = nbLettres % 2;iTaille <= nbLettres;iTaille += 2) {
		if(iTaille == 0)
			continue;
		
		curTaille += 2;
		
		int dec = (nbLettres - iTaille) / 2;
		
		if(curTaille >= iTaille) {
			curTaille -= 2;
		}
		
		while(curTaille >= 0 && h(dec, dec + curTaille) != h(nbLettres - dec - curTaille, nbLettres - dec)) {
			curTaille -= 2;
		}
		
		tailles.push_back(curTaille);
	}
	
	reverse(tailles.begin(), tailles.end());
	
	for(int taille : tailles) {
		cout << taille << " ";
	}
	cout << endl;
	return 0;
}