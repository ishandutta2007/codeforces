#include <iostream>
#include <vector>
using namespace std;

vector<int> voisins[100 * 1000 + 1];
int couleurs[100 * 1000 + 1];

vector<int> possibles;

bool estMono(int noeud, int parent) {
	for(int vois : voisins[noeud]) {
		if(vois != parent && (couleurs[vois] != couleurs[noeud] || !estMono(vois, noeud))) {
			return false;
		}
	}
	return true;
}

bool explore(int noeud, int parent) {
	if(couleurs[noeud] != couleurs[parent]) {
		return false;
	}
	
	int cnt = 0;
	int der = 0;
	for(int vois : voisins[noeud]) {
		if(vois != parent) {
			if(!explore(vois, noeud)) {
				cnt++;
				der = vois;
			}
		}
	}
	
	if(cnt >= 2) {
		possibles.push_back(noeud);
	}
	if(cnt == 1) {
		possibles.push_back(der);
	}
	
	return true;
}

int main() {
	int nbNoeuds;
	cin >> nbNoeuds;
	
	for(int iEdge = 0;iEdge < nbNoeuds - 1;iEdge++) {
		int d, f;
		cin >> d >> f;
		voisins[d - 1].push_back(f - 1);
		voisins[f - 1].push_back(d - 1);
	}
	
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		cin >> couleurs[iNoeud];
	}
	
	explore(0, 0);
	
	if(possibles.size() > 1) {
		cout << "NO" << endl;
	}
	else if(possibles.size() == 0) {
		cout << "YES" << endl;
		cout << 1 << endl;
	}
	else {
		int pos = possibles[0];
		
		bool marche = true;
		for(int v : voisins[pos]) {
			if(!estMono(v, pos))
				marche = false;
		}
		
		if(marche) {
			cout << "YES" << endl;
			cout << pos + 1 << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}