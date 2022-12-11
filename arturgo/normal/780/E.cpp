#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int nbVilles, nbRoutes, nbLarbins;
vector<int> voisins[300 * 1000];
bool estPasse[300 * 1000];

vector<int> tour;

void construitTour(int noeud) {
	if(estPasse[noeud])
		return;
	tour.push_back(noeud);
	estPasse[noeud] = true;
	
	for(int voisin : voisins[noeud]) {
		construitTour(voisin);
		if(tour.back() != noeud)
			tour.push_back(noeud);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nbVilles >> nbRoutes >> nbLarbins;
	
	for(int iRoute = 0;iRoute < nbRoutes;iRoute++) {
		int deb, fin;
		cin >> deb >> fin;
		voisins[deb - 1].push_back(fin - 1);
		voisins[fin - 1].push_back(deb - 1);
	}
	
	construitTour(0);
	
	int curPos = 0;
	for(int iLarbin = 0;iLarbin < nbLarbins;iLarbin++) {
		vector<int> sol;
		while(curPos < tour.size() && sol.size() < (2 * nbVilles + nbLarbins - 1) / nbLarbins) {
			sol.push_back(tour[curPos++]);
		}
		
		if(sol.empty())
			sol.push_back(0);
			
		cout << sol.size() << " ";
		
		for(int val : sol) {
			cout << val + 1 << " ";
		}
		cout << endl;
	}
}