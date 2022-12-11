#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Route {
	int beaute, cout, debut, fin, id;
	Route(int _beaute = 0, int _cout = 0, int _debut = 0, int _fin = 0, int _id = 0) {
		beaute = _beaute;
		cout = _cout;
		debut = _debut;
		fin = _fin;
		id = _id;
	}
};

bool operator < (const Route &a, const Route &b) {
	return a.beaute < b.beaute;
}

const int MAX_NB_NOEUDS = 200 * 1000 + 42;

int nbNoeuds, nbRoutes;
vector<Route> routes;

int parents[MAX_NB_NOEUDS];
vector<int> arbre((1 << 20), 1000 * 1000 * 1000);

void modifie(int pos, int val) {
	pos += (1 << 19);
	while(pos != 0) {
		arbre[pos] = min(arbre[pos], val);
		pos /= 2;
	}
}

int getMax(int debut, int fin) {
	debut += (1 << 19);
	fin += (1 << 19);
	
	int maxi = 1000 * 1000 * 1000;
	while(debut < fin) {
		if(debut % 2 == 1) {
			maxi = min(maxi, arbre[debut]);
			debut++;
		}
		if(fin % 2 == 1) {
			fin--;
			maxi = min(maxi, arbre[fin]);
		}
		debut /= 2;
		fin /= 2;
	}
	
	return maxi;
}

int Find(int a) {
	if(parents[a] == 0)
		return a;
	return (parents[a] = Find(parents[a]));
}

vector<pair<int, int>> voisins[MAX_NB_NOEUDS];
int debuts[MAX_NB_NOEUDS];
int fins[MAX_NB_NOEUDS];
int hauteurs[MAX_NB_NOEUDS];
int remontees[MAX_NB_NOEUDS][19];
int valremontees[MAX_NB_NOEUDS][19];
int curId = 0;

void explore(int noeud, int parent, int prof, int valeur) {
	hauteurs[noeud] = prof;
	debuts[noeud] = curId++;
	
	remontees[noeud][0] = parent;
	valremontees[noeud][0] = valeur;
	for(int iFois = 0;iFois < 18;iFois++) {
		remontees[noeud][iFois + 1] = remontees[remontees[noeud][iFois]][iFois];
		valremontees[noeud][iFois + 1] = max(valremontees[remontees[noeud][iFois]][iFois], valremontees[noeud][iFois]);
	}
	
	for(pair<int, int> voisin : voisins[noeud]) {
		if(voisin.first != parent) {
			explore(voisin.first, noeud, prof + 1, voisin.second);
			fins[noeud] = curId++;
			modifie(fins[noeud], prof);
		}
	}
	
	if(voisins[noeud].size() == 1) {
		fins[noeud] = curId++;
		modifie(fins[noeud], prof);
	}
	
	modifie(debuts[noeud], prof);
}

int remonte(int noeud, int nombre) {
	int maxi = 0;
	while(nombre != 0) {
		int id = log2(nombre);
		maxi = max(maxi, valremontees[noeud][id]);
		noeud = remontees[noeud][id];
		nombre -= (1 << id);
	}
	return maxi;
}

int main() {
	cin >> nbNoeuds >> nbRoutes;
	
	routes = vector<Route>(nbRoutes, Route(0, 0, 0, 0));
	for(int iRoute = 0;iRoute < nbRoutes;iRoute++)
		cin >> routes[iRoute].beaute;
	for(int iRoute = 0;iRoute < nbRoutes;iRoute++)
		cin >> routes[iRoute].cout;
	
	for(int iRoute = 0;iRoute < nbRoutes;iRoute++) {
		cin >> routes[iRoute].debut >> routes[iRoute].fin;
		routes[iRoute].id = iRoute;
	}
	
	sort(routes.begin(), routes.end());
	
	long long total = 0;
	for(int iRoute = 0;iRoute < nbRoutes;iRoute++) {
		if(Find(routes[iRoute].debut) != Find(routes[iRoute].fin)) {
			parents[Find(routes[iRoute].debut)] = Find(routes[iRoute].fin);
			voisins[routes[iRoute].debut].push_back(make_pair(routes[iRoute].fin, routes[iRoute].beaute));
			voisins[routes[iRoute].fin].push_back(make_pair(routes[iRoute].debut, routes[iRoute].beaute));
			total += routes[iRoute].beaute;
		}
	}
	
	int argent;
	cin >> argent;
	
	explore(1, 0, 0, 0);
	
	int best = 0;
	long long minValue = total;
	for(int iRoute = 0;iRoute < nbRoutes;iRoute++) {
		long long melEnl = total;
		
		int d = min(debuts[routes[iRoute].debut], debuts[routes[iRoute].fin]);
		int f = max(fins[routes[iRoute].debut], fins[routes[iRoute].fin]);
		
		int lca = getMax(d, f + 1);
		
		melEnl -= max(
			remonte(routes[iRoute].debut, hauteurs[routes[iRoute].debut] - lca), 
			remonte(routes[iRoute].fin, hauteurs[routes[iRoute].fin] - lca)
		);
		
		melEnl += routes[iRoute].beaute;
		melEnl -= (argent / routes[iRoute].cout);
		
		if(melEnl < minValue) {
			minValue = melEnl;
			best = iRoute;
		}
	}
	
	cout << minValue << endl;
	
	for(int iNoeud = 0;iNoeud <= nbNoeuds;iNoeud++) {
		parents[iNoeud] = 0;
	}
	
	cout << routes[best].id + 1 << " " << routes[best].beaute - (argent / routes[best].cout) << endl;
	parents[Find(routes[best].debut)] = Find(routes[best].fin);
	
	for(int iRoute = 0;iRoute < nbRoutes;iRoute++) {
		if(Find(routes[iRoute].debut) != Find(routes[iRoute].fin)) {
			parents[Find(routes[iRoute].debut)] = Find(routes[iRoute].fin);
			cout << routes[iRoute].id + 1 << " " << routes[iRoute].beaute << endl;
		}
	}
	return 0;
}