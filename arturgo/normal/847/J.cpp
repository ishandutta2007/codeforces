#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Arc {
	int fin, cap, inv;
	
	Arc(int _fin = 0, int _cap = 0, int _inv = 0) {
		fin = _fin;
		cap = _cap;
		inv = _inv;
	}
};

vector<Arc> arcs;
vector<int> voisins[20000];

void ajouteArc(int deb, int fin, int cap) {
	int s = arcs.size();
	
	arcs.push_back(Arc(fin, cap, s + 1));
	arcs.push_back(Arc(deb, 0, s));
	
	voisins[deb].push_back(s);
	voisins[fin].push_back(s + 1);
}

int curPasse = 0;
int derPasse[20000];

int nbNoeuds, nbArcs;
vector<pair<int, int>> memoire;
int SOURCE, PUITS;

bool ameliore(int noeud) {
	if(noeud == PUITS)
		return true;
	
	if(derPasse[noeud] == curPasse)
		return false;
	derPasse[noeud] = curPasse;
	
	for(int id : voisins[noeud]) {
		Arc& cur = arcs[id];
		if(cur.cap > 0 && ameliore(cur.fin)) {
			cur.cap--;
			arcs[cur.inv].cap++;
			return true;
		}
	}
	return false;
}

void creeGraphe(int val) {
	for(int v = 0;v < 20000;v++)
		voisins[v].clear();
	arcs.clear();
	
	SOURCE = 0;
	PUITS = nbArcs + nbNoeuds + 1;
	
	int iArc = 1;
	for(pair<int, int> arc : memoire) {
		ajouteArc(SOURCE, iArc, 1);
		ajouteArc(iArc, nbArcs + 1 + arc.first, 1);
		ajouteArc(iArc, nbArcs + 1 + arc.second, 1);
		iArc++;
	}
	
	for(int iNoeud = 1;iNoeud <= nbNoeuds;iNoeud++) {
		ajouteArc(nbArcs + iNoeud, PUITS, val);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nbNoeuds >> nbArcs;
	
	if(nbArcs == 0) {
		cout << 0 << endl;
		return 0;
	}
	
	for(int iArc = 0;iArc < nbArcs;iArc++) {
		int deb, fin;
		cin >> deb >> fin;
		deb--;fin--;
		
		memoire.push_back({deb, fin});
	}

	int deb = 0, fin = 5000;
	while(deb + 1 < fin) {
		int mil = (deb + fin) / 2;
		
		creeGraphe(mil);
		
		curPasse++;
		int flot = 0;
		while(ameliore(SOURCE)) {
			curPasse++;
			flot++;
		}
		
		if(flot == nbArcs) {
			fin = mil;
		}
		else {
			deb = mil;
		}
	}
	
	cout << deb + 1 << endl;
	creeGraphe(deb + 1);
	
	int flot = 0;
	curPasse++;
	while(ameliore(SOURCE)) {
		curPasse++;
		flot++;
	}
	
	for(int iArc = 0;iArc < nbArcs;iArc++) {
		if(arcs[6 * iArc + 2].cap == 0) {
			cout << arcs[6 * iArc + 2].fin - nbArcs << " " << arcs[6 * iArc + 4].fin - nbArcs << endl;
		}
		else {
			cout << arcs[6 * iArc + 4].fin - nbArcs << " " << arcs[6 * iArc + 2].fin - nbArcs << endl;
		}
	}
	return 0;
}