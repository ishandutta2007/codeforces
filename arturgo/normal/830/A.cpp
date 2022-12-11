#include <iostream>
#include <algorithm>
using namespace std;

int posChiens[5000];
int posBalles[5000];

int main() {
	int nbChiens, nbBalles, posMaitre;
	cin >> nbChiens >> nbBalles >> posMaitre;
	
	for(int iChien = 0;iChien < nbChiens;iChien++) {
		cin >> posChiens[iChien];
	}
	
	for(int iBalle = 0;iBalle < nbBalles;iBalle++) {
		cin >> posBalles[iBalle];
	}
	
	sort(posChiens, posChiens + nbChiens);
	sort(posBalles, posBalles + nbBalles);
	
	int minTemps = 2000 * 1000 * 1000;
	for(int deb = 0;deb <= nbBalles - nbChiens;deb++) {
		int maxTemps = 0;
		for(int iChien = 0;iChien < nbChiens;iChien++) {
			maxTemps = max(maxTemps,
				abs(posChiens[iChien] - posBalles[deb + iChien])
			+	 abs(posBalles[deb + iChien] - posMaitre)
			);
		}
		minTemps = min(minTemps, maxTemps);
	}
	
	cout << minTemps << endl;
}