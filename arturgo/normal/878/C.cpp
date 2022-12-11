#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Noeud {
	int nbElems;
	vector<int> mins, maxs;
};

int nbTournois, nbSports;

bool operator < (const Noeud &a, const Noeud &b) {
	for(int iSport = 0;iSport < nbSports;iSport++) {
		if(a.maxs[iSport] > b.mins[iSport]) {
			return false;
		}
	}
	return true;
}

bool operator == (const Noeud &a, const Noeud &b) {
	return !((a < b) ^ (b < a));
}

Noeud merge(Noeud a, Noeud b) {
	Noeud ret;
	ret.nbElems = a.nbElems + b.nbElems;
	
	ret.maxs = ret.mins = a.mins;
	
	for(int iSport = 0;iSport < nbSports;iSport++) {
		ret.mins[iSport] = min(a.mins[iSport], b.mins[iSport]);
		ret.maxs[iSport] = max(a.maxs[iSport], b.maxs[iSport]);
	}
	
	return ret;
}

multiset<Noeud> noeuds;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nbTournois >> nbSports;
	
	for(int iTournoi = 0;iTournoi < nbTournois;iTournoi++) {
		vector<int> talents;
		
		for(int iSport = 0;iSport < nbSports;iSport++) {
			int val;
			cin >> val;
			talents.push_back(val);
		}
		
		Noeud nouv;
		nouv.nbElems = 1;
		nouv.mins = talents;
		nouv.maxs = talents;
		
		while(true) {
			auto deb = noeuds.lower_bound(nouv);
			auto fin = noeuds.upper_bound(nouv);
			
			if(deb == noeuds.end() || deb == fin) {
				break;
			}
			
			auto suiv = deb; suiv++;
			if(suiv != fin) {
				Noeud a = *deb;
				Noeud b = *suiv;
				noeuds.erase(deb);
				noeuds.erase(suiv);
				noeuds.insert(merge(a, b));
			}
			else
				break;
		}
		
		auto deb = noeuds.lower_bound(nouv);
		if(deb == noeuds.end()) {
			noeuds.insert(nouv);
		}
		else if(*deb == nouv) {
			Noeud a = *deb;
			noeuds.erase(deb);
			
			noeuds.insert(merge(nouv, a));
		}
		else {
			noeuds.insert(nouv);
		}
		
		cout << noeuds.rbegin()->nbElems << endl;
	}
}