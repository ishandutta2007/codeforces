#include <algorithm>
#include <iostream>
#include <bitset>
#include <vector>
#include <list>
using namespace std;

const int INFINI = 2000 * 1000 * 1000;

struct Arc {
	int debut, fin, temps;
	Arc(int _debut = 0, int _fin = 0, int _temps = 0) {
		debut = _debut;
		fin = _fin;
		temps = _temps;
	}
};

struct Matrice {
	vector<bitset<150> > ligs;
	int nbLigs;
	int nbCols;
};

bool operator < (const Arc &a, const Arc &b) {
	return a.temps < b.temps;
}

Matrice nulle(int taille) {
	Matrice res;
	res.nbLigs = taille;
	res.nbCols = taille;
	for(int iLig = 0;iLig < taille;iLig++) {
		bitset<150> lig;
		lig = lig ^ lig;
		res.ligs.push_back(lig);
	}
	return res;
}

Matrice identite(int taille) {
	Matrice res;
	res.nbLigs = taille;
	res.nbCols = taille;
	for(int iLig = 0;iLig < taille;iLig++) {
		bitset<150> lig;
		lig = lig ^ lig;
		lig[iLig] = true;
		res.ligs.push_back(lig);
	}
	return res;
}

Matrice produit(Matrice a, Matrice b) {
	Matrice res = nulle(a.nbLigs);
	for(int iLig = 0;iLig < a.nbLigs;iLig++) {
		for(int iCol = 0;iCol < a.nbCols;iCol++) {
			if(a.ligs[iLig][iCol]) {
				res.ligs[iLig] = (res.ligs[iLig] | b.ligs[iCol]);
			}
		}
	}
	return res;
}

Matrice puissance(Matrice a, int exp) {
	Matrice res = identite(a.nbLigs);
	Matrice cur_puis = a;
	
	for(int iExp = 0;exp != 0;iExp++) {
		if(exp % (1 << (iExp + 1)) == (1 << iExp)) {
			exp -= (1 << iExp);
			res = produit(res, cur_puis);
		}
		
		cur_puis = produit(cur_puis, cur_puis);
	}
	return res;
}

int nbNoeuds, nbArcs;
vector<Arc> arcs;
Matrice adjacence, positions;
vector<int> parents[150];

int main() {
	cin >> nbNoeuds >> nbArcs;
	
	adjacence = nulle(nbNoeuds);
	positions = nulle(nbNoeuds);
	positions.ligs[0][0] = true;
	
	for(int iArc = 0;iArc < nbArcs;iArc++) {
		int debut, fin, temps;
		cin >> debut >> fin >> temps;
		arcs.push_back(Arc(debut - 1, fin - 1, temps));
	}
	
	sort(arcs.begin(), arcs.end());
	
	int minTemps = INFINI;
	int derTemps = 0;
	for(Arc arc : arcs) {
		parents[arc.fin].push_back(arc.debut);
	
		int curTemps = arc.temps;
		positions = produit(positions, puissance(adjacence, curTemps - derTemps));
		adjacence.ligs[arc.debut][arc.fin] = true;
		
		list<pair<int, int> > events;
		vector<bool> est_passe(nbNoeuds, false);
		
		events.push_back(make_pair(nbNoeuds - 1, curTemps));
		while(!events.empty()) {
			pair<int, int> cur = events.front();
			events.pop_front();
			
			if(est_passe[cur.first])
				continue;
			est_passe[cur.first] = true;
			
			if(positions.ligs[0][cur.first])
				minTemps = min(minTemps, cur.second);
			
			for(int parent : parents[cur.first]) {
				events.push_back(make_pair(parent, cur.second + 1));
			}
		}
		
		derTemps = curTemps;
	}
	
	if(minTemps == INFINI) {
		cout << "Impossible" << endl;
	}
	else {
		cout << minTemps << endl;
	}
	return 0;
}