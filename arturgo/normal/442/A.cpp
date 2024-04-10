#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

string couleurs = "RGBYW";
string nombres = "12345";

int invCouleur[256];
int invNombre[256];

vector<string> cartes;

bool separe(string a, string b, bitset<10> config) {
	if(a[0] != b[0] && (config[invCouleur[(int)a[0]]] || config[invCouleur[(int)b[0]]])) {
		return true;
	}
	if(a[1] != b[1] && (config[5 + invNombre[(int)a[1]]] || config[5 + invNombre[(int)b[1]]])) {
		return true;
	}
	return false;
}

int main() {
	int nbCartes;
	cin >> nbCartes;
	
	for(int iCarte = 0;iCarte < nbCartes;iCarte++) {
		string carte;
		cin >> carte;
		cartes.push_back(carte);
	}
	
	invCouleur[(int)'R'] = 0;
	invCouleur[(int)'G'] = 1;
	invCouleur[(int)'B'] = 2;
	invCouleur[(int)'Y'] = 3;
	invCouleur[(int)'W'] = 4;
	invNombre[(int)'1'] = 0;
	invNombre[(int)'2'] = 1;
	invNombre[(int)'3'] = 2;
	invNombre[(int)'4'] = 3;
	invNombre[(int)'5'] = 4;
	
	int minConseil = 10;
	for(int rep = 0;rep < (1 << 10);rep++) {
		bitset<10> config(rep);
		
		bool estValide = true;
		
		for(string a : cartes) {
			for(string b : cartes) {
				if(a != b && !separe(a, b, config)) {
					estValide = false;
				}
			}
		}
		
		if(estValide && (int)config.count() < minConseil) {
			minConseil = config.count();
		}
	}
	
	cout << minConseil << endl;
	return 0;
}