#include <iostream>
#include <algorithm>
using namespace std;

int nbMarches;
string marches;

long long reponses[1000 * 1000 + 1];

void retourne() {
	reverse(marches.begin(), marches.end());
	for(int iMarche = 0;iMarche < nbMarches;iMarche++) {
		if(marches[iMarche] == 'D')
			marches[iMarche] = 'U';
		else
			marches[iMarche] = 'D';
	}
	reverse(reponses, reponses + nbMarches);
}

void calcule() {
	int proD = 0;
	
	int nbChs = 0;
	long long secG = 0, secD = 0;
	bool finitGauche = true;
	for(int iMarche = 0;iMarche < nbMarches;iMarche++) {
		if(finitGauche) {
			if(marches[iMarche] == 'U') {
				proD = max(iMarche + 1, proD);
				while(proD != nbMarches && marches[proD] != 'D') {
					proD++;
				}
				
				if(proD == nbMarches) {
					finitGauche = false;
				}
				else {
					secG += 2 * nbChs + 1;
					secD -= 2 * nbChs;
					secD += 2 * (proD - iMarche) - 1;
					proD++;
					nbChs++;
				}
			}
			else {
				if(nbChs != 0)  {
					proD = max(iMarche + 1, proD);
					while(proD != nbMarches && marches[proD] != 'D') {
						proD++;
					}
				
					if(proD == nbMarches) {
						finitGauche = false;
					}
					else {
						secG += 2 * nbChs;
						secD -= 2 * nbChs - 1;
						secD += 2 * (proD - iMarche) - 1;
						proD++;
					}
				}
			}
		}
		
		if(finitGauche) {
			reponses[iMarche] = secG + secD + iMarche + 1;
		}
	}
}

int main() {
	cin >> nbMarches;
	cin >> marches;
	
	calcule();
	retourne();
	calcule();
	retourne();
	
	for(int iMarche = 0;iMarche < nbMarches;iMarche++) {
		cout << reponses[iMarche] << " ";
	}
	cout << endl;
	return 0;
}