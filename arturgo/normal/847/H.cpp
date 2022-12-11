#include <iostream>
#include <vector>
using namespace std;

const long long INFINI = (long long)1000 * 1000 * 1000 * 1000 * 1000 * 1000;

int hauteurs[200 * 1000];
long long minAjout[2][200 * 1000];
int minHauteur[200 * 1000];

int main() {
	ios_base::sync_with_stdio(false);
	int nbMesures;
	cin >> nbMesures;
	
	for(int iMesure = 0;iMesure < nbMesures;iMesure++) {
		cin >> hauteurs[iMesure];
	}
	
	long long prec = 0;
	int derH = 0;
	for(int iMesure = 0;iMesure < nbMesures;iMesure++) {
		minHauteur[iMesure] = max(derH, hauteurs[iMesure]);
		minAjout[0][iMesure] = prec;
		
		prec += max(derH, hauteurs[iMesure]) - hauteurs[iMesure];
		derH = max(derH, hauteurs[iMesure]) + 1;
	}
	
	prec = 0;
	derH = 0;
	for(int iMesure = nbMesures - 1;iMesure >= 0;iMesure--) {
		minHauteur[iMesure] = max(derH, minHauteur[iMesure]);
		minAjout[1][iMesure] = prec;
		
		prec += max(derH, hauteurs[iMesure]) - hauteurs[iMesure];
		derH = max(derH, hauteurs[iMesure]) + 1;
	}
	
	long long total = INFINI;
	for(int iMesure = 0;iMesure < nbMesures;iMesure++) {
		total = min(total, 
			minAjout[0][iMesure] + minAjout[1][iMesure] + minHauteur[iMesure] - hauteurs[iMesure]
		);
	}
	
	cout << total << endl;
	return 0;
}