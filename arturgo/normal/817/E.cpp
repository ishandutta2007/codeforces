#include <iostream>
#include <algorithm>
using namespace std;

struct Noeud {
	int g, d;
	int taille, nb;
	Noeud(int _taille = 1, int _g = -1, int _d = -1, int _nb = 0) {
		g = _g;
		d = _d;
		nb = _nb;
		taille = _taille;
	}
};

vector<Noeud> noeuds;

void modif(int perso, int val, int noeud = 0) {
	noeuds[noeud].nb += val;
	
	if(noeuds[noeud].taille == 1)
		return;
	
	if(perso >= noeuds[noeud].taille / 2) {
		if(noeuds[noeud].d == -1) {
			noeuds[noeud].d = noeuds.size();
			noeuds.push_back(Noeud(noeuds[noeud].taille / 2));
		}
		modif(perso - noeuds[noeud].taille / 2, val, noeuds[noeud].d);
	}
	else {
		if(noeuds[noeud].g == -1) {
			noeuds[noeud].g = noeuds.size();
			noeuds.push_back(Noeud(noeuds[noeud].taille / 2));
		}
		modif(perso, val, noeuds[noeud].g);
	}
}

int nombre(int perso, int sup, int noeud = 0) {
	if(noeud == -1)
		return 0;
	
	if(sup >= noeuds[noeud].taille) {
		return noeuds[noeud].nb;
	}
	if(sup <= 0) {
		return 0;
	}
	
	if(perso < noeuds[noeud].taille / 2) {
		return 
			nombre(perso, sup, noeuds[noeud].g)
		+	nombre(perso, sup - noeuds[noeud].taille / 2, noeuds[noeud].d);
	}
	else {
		return 
			nombre(perso - noeuds[noeud].taille / 2, sup - noeuds[noeud].taille / 2, noeuds[noeud].g)
		+	nombre(perso - noeuds[noeud].taille / 2, sup, noeuds[noeud].d);
	}
}

int main() {
	int nbEvents;
	cin >> nbEvents;
	
	noeuds.push_back(Noeud(1 << 27));
	
	for(int iEvent = 0;iEvent < nbEvents;iEvent++) {
		int type;
		cin >> type;
		
		if(type == 1) {
			int perso;
			cin >> perso;
			
			modif(perso, 1);
		}
		else if(type == 2) {
			int perso;
			cin >> perso;
			
			modif(perso, -1);
		}
		else if(type == 3) {
			int perso, sup;
			cin >> perso >> sup;
			
			cout << nombre(perso, sup) << endl;
		}
	}
}