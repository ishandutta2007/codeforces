#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

struct Arc {
	int deb, fin, poids;
	Arc(int _deb = 0, int _fin = 0, int _poids = 0) {
		deb = _deb;
		fin = _fin;
		poids = _poids;
	}
};

vector<Arc> arcs;

int parents[500 * 1000 + 1];

int Find(int a) {
	if(parents[a] == -1)
		return a;
	return (parents[a] = Find(parents[a]));
}

bool problemes[500 * 1000 + 1];
vector<pair<int, vector<Arc>>> requetes[500 * 1000 + 1];

int curPasse = 1;
int derPasse[500 * 1000 + 1];
int parents_r[500 * 1000 + 1];

int FindR(int a) {
	if(derPasse[a] != curPasse)
		return a;
	return (parents_r[a] = FindR(parents_r[a]));
}

int main() {
	int nbNoeuds, nbArcs;
	scanf("%d%d", &nbNoeuds, &nbArcs);
	
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		parents[iNoeud] = -1;
	}
	
	for(int iArc = 0;iArc < nbArcs;iArc++) {
		int deb, fin, poids;
		scanf("%d%d%d", &deb, &fin, &poids);
		arcs.push_back(Arc(deb, fin, poids));
	}
	
	int nbRequetes;
	scanf("%d", &nbRequetes);
	
	for(int iRequete = 0;iRequete < nbRequetes;iRequete++) {
		int nbForces;
		scanf("%d", &nbForces);
		
		for(int iForce = 0;iForce < nbForces;iForce++) {
			int id;
			scanf("%d", &id);
			
			Arc cur = arcs[id - 1];
			if(requetes[cur.poids].empty() || requetes[cur.poids].back().first != iRequete) {
				requetes[cur.poids].push_back({iRequete, vector<Arc>()});
			}
			
			requetes[cur.poids].back().second.push_back(cur);
		}
	}
	
	sort(arcs.begin(), arcs.end(), [&](const Arc &a, const Arc &b) { return a.poids < b.poids; });
	
	int total = 0;
	int curPoids = 0;
	for(Arc arc : arcs) {
		while(curPoids <= arc.poids) {
			for(pair<int, vector<Arc>> req : requetes[curPoids]) {
				curPasse++;
				for(Arc ajout : req.second) {
					if(FindR(Find(ajout.deb)) == FindR(Find(ajout.fin))) {
						problemes[req.first] = true;
						break;
					}
					parents_r[FindR(Find(ajout.deb))] = FindR(Find(ajout.fin));
					derPasse[FindR(Find(ajout.deb))] = curPasse;
				}
			}
			curPoids++;
		}
		
		if(Find(arc.deb) != Find(arc.fin)) {
			parents[Find(arc.deb)] = Find(arc.fin);
			total += arc.poids;
		}
	}
	
	for(int iRequete = 0;iRequete < nbRequetes;iRequete++) {
		if(problemes[iRequete])
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}