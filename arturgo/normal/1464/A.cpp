#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> voisins;
vector<bool> estPasse;

pair<int, int> explore(int pos) {
	if(estPasse[pos])
		return {0, 0};
	estPasse[pos] = true;
	
	pair<int, int> somme = {1, (int)voisins[pos].size()};
	for(int v : voisins[pos]) {	
		pair<int, int> res = explore(v);
		
		somme.first += res.first;
		somme.second += res.second;
	}
	
	return somme;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int nbTests;
	cin >> nbTests;
	
	for(int iTest = 0;iTest < nbTests;iTest++) {
		int taille, nbTours;
		cin >> taille >> nbTours;
		
		voisins = vector<vector<int>>(taille + 1, vector<int>());
		
		estPasse = vector<bool>(taille + 1, false);
		
		int nbTurns = 0;
		for(int iTour = 0;iTour < nbTours;iTour++) {
			int x, y;
			cin >> x >> y;
			
			if(x != y) {
				nbTurns++;
				voisins[x].push_back(y);
				voisins[y].push_back(x);
			}
		}
		
		int nbCycles = 0;
		for(int iPos = 0;iPos <= taille;iPos++) {
			if(!estPasse[iPos] && !voisins[iPos].empty()) {
				pair<int, int> res = explore(iPos);
				
				if(2 * res.first == res.second) {
					nbCycles++;
				}
			}
		}
		
		nbTurns += nbCycles;
		
		cout << nbTurns << endl;
	}
	
	return 0;
}