#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> fils[100 * 1000];
int parents[100 * 1000], cardinaux[100 * 1000];
double esperances[100 * 1000];

int calculeCardinaux(int noeud) {
	int somme = 0;
	for(int pro : fils[noeud]) {
		somme += calculeCardinaux(pro);
	}
	cardinaux[noeud] = somme + 1;
	return cardinaux[noeud];
}

void calculeEsperances(int noeud, double esp) {
	esperances[noeud] = esp;
	
	int somme = cardinaux[noeud] - 1;
	for(int pro : fils[noeud]) {
		calculeEsperances(pro, esp + 1 + (somme - cardinaux[pro]) / 2.);
	}
}

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int nbNoeuds;
	cin >> nbNoeuds;
	
	for(int iNoeud = 1;iNoeud < nbNoeuds;iNoeud++) {
		cin >> parents[iNoeud];
		parents[iNoeud]--;
		fils[parents[iNoeud]].push_back(iNoeud);
	}
	
	calculeCardinaux(0);
	calculeEsperances(0, 1);
	
	cout << fixed << setprecision(10);
	
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		cout << esperances[iNoeud] << " ";
	}
	return 0;
}