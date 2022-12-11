#include <iostream>
#include <vector>
using namespace std;

int nbVilles, nbRoutes;
vector<int> voisins[100 * 1000];
bool estPasse[100 * 1000];

bool estCycle(int noeud, int parent = -1) {
	if(estPasse[noeud])
		return true;
	estPasse[noeud] = true;
	
	bool est = false;
	for(int voisin : voisins[noeud]) {
		if(voisin != parent && estCycle(voisin, noeud)) {
			est = true;
		}
	}
	
	return est;
}

int main() {
	cin >> nbVilles >> nbRoutes;
	
	for(int iRoute = 0;iRoute < nbRoutes;iRoute++) {
		int deb, fin;
		cin >> deb >> fin;
		voisins[deb - 1].push_back(fin - 1);
		voisins[fin - 1].push_back(deb - 1);
	}
	
	int nbVillages = 0;
	for(int iVille = 0;iVille < nbVilles;iVille++) {
		if(!estPasse[iVille] && !estCycle(iVille)) {
			nbVillages++;
		}
	}
	
	cout << nbVillages << endl;
	return 0;
}