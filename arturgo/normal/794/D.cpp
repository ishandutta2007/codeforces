#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long fact = 300001;

vector<int> voisins[300 * 1000];
pair<long long, int> hashs[300 * 1000];
int ids[300 * 1000];
int tailles[300 * 1000];
int couleurs[300 * 1000];

vector<int> voisins2[300 * 1000];

int nbNoeuds, nbArcs;

long long getHash(vector<int> t) {
	sort(t.begin(), t.end());
	long long has = 0;
	for(int v : t) {
		has = has * fact + v;
	}
	return has * fact + t.size();
}

int main() {
	cin >> nbNoeuds >> nbArcs;
	
	for(int iArc = 0;iArc < nbArcs;iArc++) {
		int deb, fin;
		cin >> deb >> fin;
		voisins[deb - 1].push_back(fin - 1);
		voisins[fin - 1].push_back(deb - 1);
	}
	
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		voisins[iNoeud].push_back(iNoeud);
		hashs[iNoeud] = make_pair(getHash(voisins[iNoeud]), iNoeud);
	}
	
	sort(hashs, hashs + nbNoeuds);
	
	int iFois = 0;
	for(int iDeb = 0;iDeb < nbNoeuds;iDeb++) {
		int iFin = iDeb;
		while(iFin != nbNoeuds && hashs[iFin].first == hashs[iDeb].first) {
			iFin++;
		}
		
		for(int iPos = iDeb;iPos < iFin;iPos++) {
			ids[hashs[iPos].second] = iFois;
		}
		
		tailles[iFois] = iFin - iDeb;
		
		iFois++;
		iDeb = iFin - 1;
	}
	
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		int nbMemes = 0;
		
		for(int voisin : voisins[iNoeud]) {
			if(ids[voisin] != ids[iNoeud]) {
				voisins2[ids[voisin]].push_back(ids[iNoeud]);
				voisins2[ids[iNoeud]].push_back(ids[voisin]);
			}
			else {
				nbMemes++;
			}
		}
		
		if(nbMemes != tailles[ids[iNoeud]]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	for(int iGroupe = 0;iGroupe < iFois;iGroupe++) {
		int pre = -1;
		
		for(int voisin : voisins2[iGroupe]) {
			if(pre != -1 && voisin != pre) {
				pre = -2;
			}
			else if(pre != -2) {
				pre = voisin;
			}
		}
		
		if(pre >= -1) {
			int pos = iGroupe, parent = -1;
			int val = 1;
			
			while(true) {
				int pre = -1;
				for(int voisin : voisins2[pos]) {
					if(voisin == parent)
						continue;
					if(pre == -1) {
						pre = voisin;
					}
					else if(pre != voisin) {
						cout << "NO" << endl;
						return 0;
					}
				}
	
				if(pre != -2) {
					couleurs[pos] = val;
				}
				if(pre == -1) {
					break;
				}
				
				val++;
				parent = pos;
				pos = pre;
			}
			
			break;
		}
	}
	
	for(int iGroupe = 0;iGroupe < iFois;iGroupe++) {
		if(couleurs[iGroupe] == 0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		cout << couleurs[ids[iNoeud]] << endl;
	}
	return 0;
}