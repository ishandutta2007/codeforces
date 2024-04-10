#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int nbObjets, maxPoids;

vector<int> objets[3];
vector<long long> cumuls[3];

int main() {
	cin >> nbObjets >> maxPoids;
	
	for(int iObjet = 0;iObjet < nbObjets;iObjet++) {
		int poids, prix;
		cin >> poids >> prix;
		objets[poids - 1].push_back(prix);
	}
	
	for(int iPoids = 0;iPoids < 3;iPoids++) {
		sort(objets[iPoids].begin(), objets[iPoids].end(), greater<int>());
		
		cumuls[iPoids].push_back(0);
		for(int iObjet = 0;iObjet < (int)objets[iPoids].size();iObjet++) {
			cumuls[iPoids].push_back(cumuls[iPoids].back() + objets[iPoids][iObjet]);
		}
		
		for(int iFois = 0;iFois <= 300 * 1000;iFois++) {
			cumuls[iPoids].push_back(cumuls[iPoids].back());
		}
	}
	
	long long maxi = 0;
	for(int nbTrois = 0;nbTrois <= (int)objets[2].size();nbTrois++) {
		int restePoids = maxPoids - 3 * nbTrois;
		
		if(restePoids < 0)
			continue;
		
		int deb = 0;
		int fin = objets[1].size();
		while(deb + 1 < fin) {
			int mil = (deb + fin) / 2;
			
			if(restePoids - 2 * mil - 2 < 0) {
				fin = mil;
				continue;
			}
			
			long long scoreMil = cumuls[1][mil] + cumuls[0][restePoids - 2 * mil];
			long long scoreSuiv = cumuls[1][mil + 1] + cumuls[0][restePoids - 2 * mil - 2];
			
			if(scoreMil < scoreSuiv) {
				deb = mil;
			}
			else {
				fin = mil;
			}
		}
		
		long long res = 0;
		
		if(restePoids - 2 * deb - 2 >= 0)
			res = max(res, cumuls[1][deb + 1] + cumuls[0][restePoids - 2 * deb - 2]);
		
		if(restePoids - 2 * deb >= 0)
			res = max(res, cumuls[1][deb] + cumuls[0][restePoids - 2 * deb]);
			
		res += cumuls[2][nbTrois];
		
		maxi = max(maxi, res);
	}
	
	cout << maxi << endl;
	return 0;
}