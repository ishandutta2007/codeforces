#include <iostream>
using namespace std;

const int INFINI = 1000 * 1000 * 1000;

int nbTours;
int hauteurs[5000];

int dyn[5001][5001];

int main() {
	cin >> nbTours;
	
	for(int iTour = 0;iTour < nbTours;iTour++) {
		cin >> hauteurs[iTour];
	}
	
	for(int nbAvant = 0;nbAvant <= nbTours;nbAvant++) {
		fill(dyn[nbAvant], dyn[nbAvant] + nbTours + 1, -INFINI);
	}
	
	dyn[0][0] = 1;
	
	for(int fin = 1;fin <= nbTours;fin++) {
		int sommeBloc = 0, somme = 0;
		int pos = fin;
		
		for(int deb = fin - 1;deb >= 0;deb--) {
			sommeBloc += hauteurs[deb];
			
			dyn[fin][deb] = max(
				dyn[fin][deb],
				dyn[fin - 1][deb]
			);
			
			while(somme < sommeBloc && pos != nbTours) {
				somme += hauteurs[pos];
				pos++;
			}
			
			
			if(somme >= sommeBloc) {
				dyn[pos][fin] = max(
					dyn[pos][fin],
					dyn[fin][deb] + 1
				);
			}
		}
	}
	
	int maxi = 0;
	for(int deb = 0;deb <= nbTours;deb++) {
		maxi = max(maxi, dyn[nbTours][deb]);
	}
	
	cout << nbTours - maxi << endl;
	return 0;
}