#include <iostream>
#include <vector>
using namespace std;

const int MAX_SOMMETS = 200 * 1000;

int nbSommets, maxDup;
string lettres;
int gauches[MAX_SOMMETS];
int droites[MAX_SOMMETS];

vector<int> in_order;
vector<bool> peut_expand, duplique;

void dfs(int s) {
	if(s == -1) return;
	dfs(gauches[s]);
	in_order.push_back(s);
	dfs(droites[s]);
}

bool calcule_duplications(int s, int cout_expand) {
	if(s == -1) return false;
	if(cout_expand > maxDup) return false;
	
	bool etend_gauche = calcule_duplications(gauches[s], cout_expand + 1);
	
	if(etend_gauche) {
		duplique[s] = true;
		calcule_duplications(droites[s], 1);
		return true;
	}
	
	if(peut_expand[s]) {
		duplique[s] = true;
		
		maxDup -= cout_expand;
		calcule_duplications(droites[s], 1);
		return true;
	}
	
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	cin >> nbSommets >> maxDup;
	cin >> lettres;
	
	for(int iSommet = 0;iSommet < nbSommets;iSommet++) {
		int g, d;
		cin >> g >> d;
		gauches[iSommet] = g - 1;
		droites[iSommet] = d - 1;
	}
	
	dfs(0);
	
	peut_expand = vector<bool>(nbSommets, false);
	duplique = vector<bool>(nbSommets, false);
	
	char suivLettre = ' ';
	for(int iSommet = nbSommets - 1;iSommet >= 0;iSommet--) {
		if(iSommet != nbSommets - 1 && lettres[in_order[iSommet]] != lettres[in_order[iSommet + 1]]) {
			suivLettre = lettres[in_order[iSommet + 1]];
		}
		if(lettres[in_order[iSommet]] < suivLettre) {
			peut_expand[in_order[iSommet]] = true;
		}
	}
	
	calcule_duplications(0, 1);
	
	string solution;
	for(int sommet : in_order) {
		solution.push_back(lettres[sommet]);
		if(duplique[sommet]) {
			solution.push_back(lettres[sommet]);
		}
	}
	
	cout << solution << endl;
	return 0;
}