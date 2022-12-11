#include <iostream>
using namespace std;

int dateEntree[100042];
int voitures[100042];

int main() {
	ios_base::sync_with_stdio(false);
	
	int nbVoitures;
	cin >> nbVoitures;

	for(int iVoiture = 0;iVoiture < nbVoitures;iVoiture++) {
		int voiture;
		cin >> voiture;
		dateEntree[voiture] = iVoiture;
	}

	for(int iVoiture = 0;iVoiture < nbVoitures;iVoiture++) {
		cin >> voitures[iVoiture];
	}

	int minEntree = nbVoitures;
	int nbTriche = 0;

	for(int iVoiture = nbVoitures - 1;iVoiture >= 0;iVoiture--) {
		if(dateEntree[voitures[iVoiture]] > minEntree) {
			nbTriche++;
		}
		minEntree = min(minEntree, dateEntree[voitures[iVoiture]]);
	}

	cout << nbTriche << endl;
	return 0;
}