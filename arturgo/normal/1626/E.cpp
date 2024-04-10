#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <map>
#include <cmath>
#define int long long
using namespace std;

const int MAX_SOMMETS = 300 * 1000;

int couleurs[MAX_SOMMETS];
vector<int> voisins[MAX_SOMMETS];

bool estPasse[MAX_SOMMETS];
bool accedeNoirs[MAX_SOMMETS];

bool estUniversel = false, aDouble = false;
vector<int> explores;

int parents[MAX_SOMMETS];

int dfs(int sommet, int parent = -1) {
	if(couleurs[sommet]) return 0;
	estPasse[sommet] = true;
	
	parents[sommet] = parent;
	explores.push_back(sommet);
	
	int minDist = MAX_SOMMETS;
	
	int degre = (parent != -1);
	
	for(int voisin : voisins[sommet]) {
		if(voisin == parent) continue;
		int dist = dfs(voisin, sommet);
		
		if(dist < MAX_SOMMETS)
			degre++;
		
		minDist = min(minDist, 1 + dist);
	}
	
	if(degre > 1) {
		aDouble = true;
		parents[sommet] = -1;
	}
	
	if(minDist == 1 || parent == -1) {
		accedeNoirs[sommet] = true;
		
		if(degre >= 3)
			estUniversel = true;
	}
	
	return minDist;
}

bool explore(int sommet) {
	if(sommet == -1) return false;
	if(accedeNoirs[sommet]) return true;
	
	if(estPasse[sommet]) return false;
	estPasse[sommet] = true;
	
	return accedeNoirs[sommet] = explore(parents[sommet]);
}

signed main() {
	ios_base::sync_with_stdio(false);
	
	int nbSommets;
	cin >> nbSommets;
	
	for(int iSommet = 0;iSommet < nbSommets;iSommet++) {
		cin >> couleurs[iSommet];
		parents[iSommet] = -1;
	}
	
	for(int iArc = 0;iArc < nbSommets - 1;iArc++) {
		int deb, fin;
		cin >> deb >> fin;
		deb--; fin--;
		voisins[deb].push_back(fin);
		voisins[fin].push_back(deb);
	}
	
	for(int iSommet = 0;iSommet < nbSommets;iSommet++) {
		for(int voisin : voisins[iSommet]) {
			if(couleurs[iSommet] && couleurs[voisin])
				estUniversel = true;
		}
	}
	
	int nbRacines = 0;
	for(int iSommet = 0;iSommet < nbSommets;iSommet++) {
		if(couleurs[iSommet]) {
			accedeNoirs[iSommet] = true;
			continue;
		}
		
		bool voisinNoir = false;
		for(int voisin : voisins[iSommet]) {
			if(couleurs[voisin]) voisinNoir = true;
		}
		
		if(!voisinNoir) continue;
		
		if(!estPasse[iSommet]) {
			aDouble = false;
			
			dfs(iSommet);
			if(aDouble) nbRacines++;
		}
	}
	
	if(nbRacines >= 2) estUniversel = true;
	
	if(estUniversel) {
		for(int iSommet = 0;iSommet < nbSommets;iSommet++) {
			accedeNoirs[iSommet] = true;
		}
	}
	
	for(int iSommet = 0;iSommet < nbSommets;iSommet++) {
		estPasse[iSommet] = false;
	}
	
	for(int iSommet = 0;iSommet < nbSommets;iSommet++) {
		explore(iSommet);
		cout << accedeNoirs[iSommet] << " ";	
	}
	cout << endl;
	
	return 0;
}