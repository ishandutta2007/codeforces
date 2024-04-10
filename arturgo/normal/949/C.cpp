#include <iostream>
#include <vector>
using namespace std;

int nbNoeuds, nbReqs, nbHeures;
int heureMAJ[100 * 1000];

vector<int> decales[100 * 1000];
vector<int> invs[100 * 1000];

bool estPasse[100 * 1000];

vector<int> postOrder;

void genPostOrder(int noeud) {
	if(estPasse[noeud])
		return;
	estPasse[noeud] = true;
	
	for(int voisin : invs[noeud]) {
		genPostOrder(voisin);
	}
	postOrder.push_back(noeud);
}

int curComposante = 0;
int composante[100 * 1000];

int explore(int noeud) {
	if(composante[noeud] != 0) {
		if(composante[noeud] == curComposante)
			return 0;
		return 1000 * 1000;
	}
	composante[noeud] = curComposante;
	
	int taille = 0;
	for(int voisin : decales[noeud]) {
		taille += explore(voisin);
		taille = min(taille, 1000 * 1000);
	}
	return taille + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nbNoeuds >> nbReqs >> nbHeures;
	
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		cin >> heureMAJ[iNoeud];
	}
	
	for(int iReq = 0;iReq < nbReqs;iReq++) {
		int a, b;
		cin >> a >> b;
		
		if((heureMAJ[a - 1] + 1) % nbHeures == heureMAJ[b - 1]) {
			decales[a - 1].push_back(b - 1);
			invs[b - 1].push_back(a - 1);
		}
		
		if((heureMAJ[b - 1] + 1) % nbHeures == heureMAJ[a - 1]) {
			decales[b - 1].push_back(a - 1);
			invs[a - 1].push_back(b - 1);
		}
	}
	
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		genPostOrder(iNoeud);
	}
	
	int minTaille = 1000 * 1000;
	int minComposante = 0;
	while(!postOrder.empty()) {
		int racine = postOrder.back();
		postOrder.pop_back();
		
		curComposante++;
		int taille = explore(racine);
		
		if(taille < minTaille) {
			minTaille = taille;
			minComposante = curComposante;
		}
	}
	
	cout << minTaille << endl;
	
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		if(composante[iNoeud] == minComposante) {
			cout << iNoeud + 1 << " ";
		}
	}
	cout << endl;
	return 0;
}