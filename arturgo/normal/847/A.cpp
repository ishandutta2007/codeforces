#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> paires;
vector<int> parents(1000, -1);

int Find(int a) {
	if(parents[a] == -1)
		return a;
	return (parents[a] = Find(parents[a]));
}

int main() {
	int nbElems;
	cin >> nbElems;
	
	for(int iElem = 0;iElem < nbElems;iElem++) {
		int av, ap;
		cin >> av >> ap;
		
		av--;ap--;
		
		paires.push_back({av, ap});
		
		if(av != -1 && Find(av) != Find(iElem)) {
			parents[Find(av)] = Find(iElem);
		}
	}
	
	for(int iDebut = 0;iDebut < nbElems;iDebut++) {
		if(paires[iDebut].first == -1) {
			for(int iFin = 0;iFin < nbElems;iFin++) {
				if(Find(iDebut) != Find(iFin) && paires[iFin].second == -1) {
					paires[iDebut].first = iFin;
					paires[iFin].second = iDebut;
					parents[Find(iDebut)] = Find(iFin);
					break;
				}
			}
		}
	}
	
	for(int iElem = 0;iElem < nbElems;iElem++) {
		cout << paires[iElem].first + 1 << " " << paires[iElem].second + 1 << endl;
	}
	return 0;
}