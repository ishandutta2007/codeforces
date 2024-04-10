#include <iostream>
#include <queue>
using namespace std;

int tailles[100 * 1000];

int main() {
	int nbBoites, nbPiles;
	cin >> nbBoites >> nbPiles;
	
	priority_queue<pair<int, int> > boites;
	
	for(int iPile = 0;iPile < nbPiles;iPile++) {
		cin >> tailles[iPile];
		
		for(int iBoite = 0;iBoite < tailles[iPile];iBoite++) {
			int id;
			cin >> id;
			boites.push({-id, iPile});
		}
	}
	
	int nbChanges = 0;
	
	int posUn = boites.top().second;
	
	while(!boites.empty() && boites.top().second == posUn) {
		boites.pop();
		tailles[posUn]--;
	}
	
	if(tailles[posUn] != 0)
		nbChanges++;
	
	for(int iPile = 0;iPile < nbPiles;iPile++) {
		if(tailles[iPile] != 0)
			nbChanges += 2 * tailles[iPile] - 1;
	}
	
	cout << nbChanges << endl;
	return 0;
}