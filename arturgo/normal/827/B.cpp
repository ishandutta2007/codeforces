#include <iostream>
#include <vector>
using namespace std;

vector< pair<int, int> > arcs;

int main() {
	int nbNoeuds, nbSorties;
	cin >> nbNoeuds >> nbSorties;
	
	vector<int> tailles;
	for(int iSortie = 0;iSortie < nbSorties;iSortie++) {
		if(iSortie < (nbNoeuds - nbSorties  - 1) % nbSorties) {
			tailles.push_back((nbNoeuds - nbSorties - 1) / nbSorties + 1);
		}
		else {
			tailles.push_back((nbNoeuds - nbSorties  - 1) / nbSorties);
		}
	}
	
	int curNoeud = nbSorties;
	for(int iSortie = 0;iSortie < nbSorties;iSortie++) {
		int derNoeud = iSortie;
		for(int iFois = 0;iFois < tailles[iSortie];iFois++) {
			arcs.push_back(make_pair(derNoeud, curNoeud));
			derNoeud = curNoeud++;
		}
		arcs.push_back(make_pair(derNoeud, nbNoeuds - 1));
	}
	
	cout << tailles[0] + tailles[1] + 2 << endl;
	
	for(pair<int, int> arc : arcs) {
		cout << arc.first + 1 << " " << arc.second + 1 << endl;
	}
}