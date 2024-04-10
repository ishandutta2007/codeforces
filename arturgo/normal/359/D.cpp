#include <iostream>
#include <vector>
using namespace std;

int pgcd(int a, int b) {
	if(a == 0)
		return b;
	return pgcd(b % a, a);
}

int nbNombres;
int vals[300*1000];

int minRange[20][300 * 1000];
int pgcdRange[20][300 * 1000];

vector<int> possibles(int taille) {
	vector<int> sol;	
	
	int etage = __builtin_log2(taille);
	int pseudo = (1 << etage);
	for(int iDebut = 0;iDebut + taille <= nbNombres;iDebut++) {
		int mini = min(minRange[etage][iDebut], minRange[etage][iDebut + taille - pseudo]);
		int pg = pgcd(pgcdRange[etage][iDebut], pgcdRange[etage][iDebut + taille - pseudo]);
		
		if(mini == pg)
			sol.push_back(iDebut);
	}
	return sol;
}

int main() {
	cin >> nbNombres;
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		cin >> vals[iNombre];
		minRange[0][iNombre] = vals[iNombre];
		pgcdRange[0][iNombre] = vals[iNombre];
	}
	
	for(int iPuis = 1;iPuis < 20;iPuis++) {
		int curPuis = (1 << iPuis), derPuis = (1 << (iPuis - 1));
		for(int iPos = 0;iPos + curPuis <= nbNombres ;iPos++) {
			minRange[iPuis][iPos] = min(minRange[iPuis - 1][iPos], minRange[iPuis - 1][iPos + derPuis]);
			pgcdRange[iPuis][iPos] = pgcd(pgcdRange[iPuis - 1][iPos], pgcdRange[iPuis - 1][iPos + derPuis]);
		}
	}
	
	int debut = 0, fin = nbNombres + 1;
	while(debut + 1 < fin) {
		int mil = (debut + fin) / 2;
		if(!possibles(mil).empty()) {
			debut = mil;
		}
		else {
			fin = mil;
		}
	}
	
	vector<int> sol = possibles(debut);
	cout << sol.size() << " " << debut - 1 << endl;
	
	for(int val : sol) {
		cout << val + 1 << " ";
	}
	cout << endl;
	return 0;
}