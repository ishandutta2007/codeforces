#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <list>
using namespace std;

struct Arc {
	int debut, fin, flot, id;
	bool actif;
	Arc(int _debut, int _fin, int _flot, int _id) {
		debut = _debut;
		fin = _fin;
		flot = _flot;
		id = _id;
		actif = true;
	}
};

int nbVilles, nbRoutes;
int source, puit;

vector<int> voisins[1001];
vector<Arc> arcs;

vector<int> shortestPath;

void ajouterArc(int debut, int fin, int flot, int id) {
	voisins[debut].push_back(arcs.size());
	arcs.push_back(Arc(debut, fin, flot, id));
	voisins[fin].push_back(arcs.size());
	arcs.push_back(Arc(fin, debut, flot, id));
}

vector<int> calculePlusCourt() {
	vector<int> chemin;
	vector<bool> passage(1001, false);
	vector<int> parents(1001, -1);
	vector<Arc> events;
	int curPos = 0;
	events.push_back(Arc(-1, source, 0, -1));
	
	while(curPos != events.size()) {
		Arc cur = events[curPos++];
		
		if(cur.fin == puit) {
			int parent = cur.id;
			while(parent != -1) {
				chemin.push_back(parent);
				parent = parents[arcs[parent].debut];
			}
			return chemin;
		}
		
		if(passage[cur.fin])
			continue;
		passage[cur.fin] = true;
		parents[cur.fin] = cur.id;
		
		for(int voisin : voisins[cur.fin]) {
			if(arcs[voisin].actif) {
				events.push_back(Arc(cur.fin, arcs[voisin].fin, cur.flot + 1, voisin));
			}
		}
	}
	return chemin;
}

int couleur = 0;
int couleurs[1001];

void colorie(int noeud) {
	if(couleurs[noeud] == couleur) {
		return;
	}
	couleurs[noeud] = couleur;
	for(int voisin : voisins[noeud]) {
		if(arcs[voisin].actif)
			colorie(arcs[voisin].fin);
	}
}

int melArcCoupe() {
	vector<int> newChem = calculePlusCourt();
	
	if(newChem.empty()) {
		return -1;
	}
	
	couleur++;
	for(int arc : newChem) {
		arcs[arc].actif = false;
	}
	
	int melArc = -2;
	for(int iArc = (int)newChem.size() - 1;iArc >= 0;iArc--) {
		int arc = newChem[iArc];
		colorie(arcs[arc].debut);
		if(couleurs[arcs[arc].fin] != couleur) {
			if(melArc == -2 || arcs[arc].flot < arcs[melArc].flot) {
				melArc = arc;
			}
		}
		arcs[arc].actif = true;
	}
	
	return melArc;
}

int main() {
	scanf("%d%d", &nbVilles, &nbRoutes);
	scanf("%d%d", &source, &puit);
	
	for(int iRoute = 0;iRoute < nbRoutes;iRoute++) {
		int debut, fin, flot;
		scanf("%d%d%d", &debut, &fin, &flot);
		ajouterArc(debut, fin, flot, iRoute);
	}
	
	shortestPath = calculePlusCourt();
	
	if(shortestPath.empty()) {
		printf("0\n");
		printf("0\n");
		
		return 0;
	}
	
	vector<int> melSol;
	int valMelSol = 2000 * 1000 * 1000 + 1;
	
	for(int arc : shortestPath) {
		arcs[arc].actif = false;
		int melArc = melArcCoupe();
		if(melArc == -1) {
			if(valMelSol > arcs[arc].flot) {
				melSol.clear();
				melSol.push_back(arc);
				valMelSol = arcs[arc].flot;
			}
		}
		else if(melArc != -2) {
			if(valMelSol > arcs[arc].flot + arcs[melArc].flot) {
				melSol.clear();
				melSol.push_back(arc);
				melSol.push_back(melArc);
				valMelSol = arcs[arc].flot + arcs[melArc].flot;
			}
		}
		arcs[arc].actif = true;
	}
	
	if(valMelSol == 2000 * 1000 * 1000 + 1) {
		printf("-1");
		return 0;
	}
	
	printf("%d\n", valMelSol);
	printf("%d\n", (int)melSol.size());
	for(int arc : melSol) {
		printf("%d ", arcs[arc].id + 1);
	}
	return 0;
}