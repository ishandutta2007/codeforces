#include <iostream>
using namespace std;

int main() {
	int nbAmis, hauteur;
	cin >> nbAmis >> hauteur;
	
	int largeur = 0;
	for(int iAmi = 0;iAmi < nbAmis;iAmi++) {
		int h;
		cin >> h;
		if(h <= hauteur)
			largeur += 1;
		else
			largeur += 2;
	}
	cout << largeur << endl;
	return 0;
}