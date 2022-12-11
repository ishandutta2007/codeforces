#include <iostream>
#include <vector>
using namespace std;

int nombres[100 * 1000];

struct Segment {
	int taille;
	int nbCouleurs = 0;
	int curPasse = 1;
	vector<int> derPasse;
	vector<int> occs;
	Segment() {
		derPasse = vector<int>(100 * 1000 + 1, 0);
		occs = vector<int>(100 * 1000 + 1, 0);
	} 
};

vector<Segment> segments;

inline int couleursApres(Segment& a, int couleur) {
	if(a.derPasse[couleur] != a.curPasse) {
		a.occs[couleur] = 0;
		a.derPasse[couleur] = a.curPasse;
	}
	if(a.occs[couleur] == 0)
		return a.nbCouleurs + 1;
	return a.nbCouleurs;
}

inline void ajoute(Segment& a, int couleur) {
	if(a.derPasse[couleur] != a.curPasse) {
		a.occs[couleur] = 0;
		a.derPasse[couleur] = a.curPasse;
	}
	a.occs[couleur]++;
	if(a.occs[couleur] == 1)
		a.nbCouleurs++;
}

inline void enleve(Segment& a, int couleur) {
	if(a.derPasse[couleur] != a.curPasse) {
		a.occs[couleur] = 0;
		a.derPasse[couleur] = a.curPasse;
	}
	a.occs[couleur]--;
	if(a.occs[couleur] == 0)
		a.nbCouleurs--;
}

int main() {
	ios_base::sync_with_stdio(false);
	int nbNombres;
	cin >> nbNombres;
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		cin >> nombres[iNombre];
	}
	
	Segment cur;
	for(int k = 1;k < min(400, nbNombres + 1);k++) {
		int nb = 1;
		cur.taille = 0;
		cur.nbCouleurs = 0;
		cur.curPasse++;
		for(int pos = 0;pos < nbNombres;pos++) {
			if(couleursApres(cur, nombres[pos]) > k) {
				cur.taille = 0;
				cur.nbCouleurs = 0;
				cur.curPasse++;
				nb++;
			}
			cur.taille++;
			ajoute(cur, nombres[pos]);
		}
		cout << nb << " ";
	}
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		if(iNombre % 400 == 0) {
			Segment nouv;
			nouv.taille = 0;
			nouv.nbCouleurs = 0;
			segments.push_back(nouv);
		}
		segments.back().taille++;
		ajoute(segments.back(), nombres[iNombre]);
	}
	
	for(int k = 400;k <= nbNombres;k++) {
		int pos = 0;
		for(int i = 0;i < (int)segments.size() - 1;i++) {
			int suiv = pos + segments[i].taille;
			while(suiv < nbNombres && couleursApres(segments[i], nombres[suiv]) <= k) {
				ajoute(segments[i], nombres[suiv]);
				segments[i].taille++;
				enleve(segments[i + 1], nombres[suiv]);
				segments[i + 1].taille--;
				suiv = pos + segments[i].taille;
			}
			pos += segments[i].taille;
		}
		
		while(segments.back().taille <= 0)
			segments.pop_back();
		
		cout << segments.size() << " ";
	}
	cout << endl;
	return 0;
}