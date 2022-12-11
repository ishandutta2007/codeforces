#include <iostream>
#include <vector>
#include <bitset>
#include <cstdio>
using namespace std;

int nbElems, nbAuto;

bitset<2000> autos[2000];
bitset<2000> inverse[2000];
int main() {
	scanf("%d%d", &nbElems, &nbAuto);
	
	vector<pair<int, int> > paires;
	for(int iPaire = 0;iPaire < nbAuto;iPaire++) {
		int pos, elem;
		scanf("%d%d", &pos, &elem);
		autos[pos - 1][elem - 1] = true;
		paires.push_back(make_pair(pos - 1, elem - 1));
	}
	
	for(int iElem = 0;iElem < nbElems;iElem++) {
		inverse[iElem][iElem] = 1;
	}
	
	//inversion
	for(int iLigne = 0;iLigne < nbElems;iLigne++) {
		if(!autos[iLigne][iLigne]) {
			for(int iAutre = iLigne + 1;iAutre < nbElems;iAutre++) {
				if(autos[iAutre][iLigne]) {
					autos[iLigne] ^= autos[iAutre];
					inverse[iLigne] ^= inverse[iAutre];
					break;
				}
			}
		}
		
		for(int iAutre = 0;iAutre < nbElems;iAutre++) {
			if(iAutre != iLigne && autos[iAutre][iLigne]) {
				autos[iAutre] ^= autos[iLigne];
				inverse[iAutre] ^= inverse[iLigne];
			}
		}
	}
	
	for(int iPaire = 0;iPaire < nbAuto;iPaire++) {
		if(inverse[paires[iPaire].second][paires[iPaire].first]) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
	return 0;
}