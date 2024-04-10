#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
 
signed main() {
	ios_base::sync_with_stdio(false);
	int nbNombres, nbBytes;
	cin >> nbNombres >> nbBytes;
 
	int nbBits = (nbBytes * 8) / nbNombres;
 
	if(nbBits >= 30) {
		cout << 0 << endl;
		return 0;
	}
 
	int taille = (1 << nbBits);
 
	vector<int> nombres;
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		int nombre;
		cin >> nombre;
		nombres.push_back(nombre);
	}
 
	sort(nombres.begin(), nombres.end());

	vector<pair<int, int>> paires;

	for(int nombre : nombres) {
		if(paires.empty() || paires.back().first != nombre) {
			paires.push_back({nombre, 1});
		}
		else {
			paires.back().second++;
		}
	}
 
	int maxDans = 0;
	int curDans = 0;
 
	int iFin = 0;
	for(int iDeb = 0;iDeb < (int)paires.size();iDeb++) {
		while(iFin != (int)paires.size() && iFin != iDeb + taille) {
			curDans += paires[iFin].second;
			iFin++;
		}
 
		maxDans = max(maxDans, curDans);

		curDans -= paires[iDeb].second;
	}
 
	cout << nbNombres - maxDans << endl;
	return 0;
}