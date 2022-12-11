#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

vector<vector<int>> monstres;

int curMonstre;
bitset<4096> ensembles[200 * 1000];

int main() {
	ios_base::sync_with_stdio(false);
	int nbNombres, nbMonstres, nbRequetes;
	cin >> nbNombres >> nbMonstres >> nbRequetes;
	
	for(int iMonstre = 0;iMonstre < nbMonstres;iMonstre++) {
		for(int iConfig = 0;iConfig < 4096;iConfig++) {
			ensembles[iMonstre][iConfig] = (((1 << iMonstre) & iConfig) >> iMonstre) % 2;
		}
	}
	
	curMonstre = nbMonstres;
	for(int iVecteur = 0;iVecteur < nbMonstres;iVecteur++) {
		vector<int> nombres;
		for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
			int val;
			cin >> val;
			nombres.push_back(val);
		}
		monstres.push_back(nombres);
	}
	
	for(int iRequete = 0;iRequete < nbRequetes;iRequete++) {
		int type, arg1, arg2;
		cin >> type >> arg1 >> arg2;
		arg1--;
		arg2--;
		
		if(type == 1) {
			ensembles[curMonstre] = ensembles[arg1] & ensembles[arg2];
			curMonstre++;
		}
		if(type == 2) {
			ensembles[curMonstre] = ensembles[arg1] | ensembles[arg2];
			curMonstre++;
		}
		if(type == 3) {
			vector<int> types(nbMonstres, 0);
			iota(types.begin(), types.end(), 0);
			
			sort(types.begin(), types.end(), [&](int a, int b) {
				return monstres[a][arg2] < monstres[b][arg2];
			});
			
			int ensemble = 0;
			int iVal = 0;
			for(;iVal < nbMonstres;iVal++) {
				ensemble |= 1 << types[iVal];
				if(ensembles[arg1][ensemble]) break;
			}
			
			cout << monstres[types[iVal]][arg2] << endl;
		}
	}
	
	return 0;
}