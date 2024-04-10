#include <iostream>
#include <vector>
using namespace std;

vector<int> ensembles[2];
int positions[8000][2];
int firstConflict[8000][2];

void setWin(int pos, int joueur);
void setLose(int pos, int joueur, bool sure = false);
int nbObjects;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nbObjects;
	
	for(int iJoueur = 0;iJoueur < 2;iJoueur++) {
		int taille;
		cin >> taille;
		
		for(int iNombre = 0;iNombre < taille;iNombre++) {
			int nombre;
			cin >> nombre;
			ensembles[iJoueur].push_back(nombre);
		}
	}
	
	positions[0][0] = -1;
	positions[0][1] = -1;
	for(int action : ensembles[0]) {
		setWin(nbObjects - action, 0);
	}
	for(int action : ensembles[1]) {
		setWin(nbObjects - action, 1);
	}
	
	for(int iJoueur = 0;iJoueur < 2;iJoueur++) {
		for(int iPos = 1;iPos < nbObjects;iPos++) {
			if(positions[iPos][iJoueur] == 0) {
				cout << "Loop ";
			}
			else if(positions[iPos][iJoueur] == 1) {
				cout << "Win ";
			}
			else {
				cout << "Lose ";
			}
		}
		cout << endl;
	}
	return 0;
}

void setLose(int pos, int joueur, bool sure) {
	if(positions[pos][joueur] != 0)
		return;
		
	if(!sure) {
		while(firstConflict[pos][joueur] < (int)ensembles[joueur].size()) {
			int action = ensembles[joueur][firstConflict[pos][joueur]];
			if(positions[(pos + action) % nbObjects][1 - joueur] != 1) {
				return;
			}
			firstConflict[pos][joueur]++;
		}
	}
	positions[pos][joueur] = -1;
	
	int autre = 1 - joueur;
	for(int action : ensembles[autre]) {
		setWin((pos - action + nbObjects) % nbObjects, autre);
	}
}

void setWin(int pos, int joueur) {
	if(positions[pos][joueur] != 0)
		return;
	positions[pos][joueur] = 1;
	
	int autre = 1 - joueur;
	for(int action : ensembles[autre]) {
		int av = (pos - action + nbObjects) % nbObjects;
		setLose(av, autre);
	}
}