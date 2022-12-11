#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int INFINI = 2000 * 1000 * 1000;

struct Noeud {
	int val, g, d;
	
	Noeud(int _val = 0, int _g = 0, int _d = 0) {
		val = _val;
		g = _g;
		d = _d;
	}
};

bool aParent[200 * 1000];

vector<Noeud> noeuds;
set<int> vals;

void trouveVals(int noeud, int deb = 0, int fin = INFINI) {
	if(noeud < 0)
		return;	
	
	if(noeuds[noeud].val >= deb && noeuds[noeud].val < fin)
		vals.insert(noeuds[noeud].val);
	
	trouveVals(noeuds[noeud].g, deb, min(noeuds[noeud].val, fin));
	trouveVals(noeuds[noeud].d, max(noeuds[noeud].val + 1, deb), fin);
}

int main() {
	int nbNoeuds;
	cin >> nbNoeuds;
	
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		int val, g, d;
		cin >> val >> g >> d;
		noeuds.push_back(Noeud(val, g - 1, d - 1));
		
		if(g - 1 >= 0)
			aParent[g - 1] = true;
		if(d - 1 >= 0)
			aParent[d - 1] = true;
	}
	
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		if(!aParent[iNoeud]) {
			trouveVals(iNoeud);
		}
	}
	
	int nbFails = 0;
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		if(vals.find(noeuds[iNoeud].val) == vals.end()) {
			nbFails++;
		}
	}
	
	cout << nbFails << endl;
}