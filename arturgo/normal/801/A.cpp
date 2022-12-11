#include <iostream>
using namespace std;

int main() {
	string chaine;
	cin >> chaine;
	
	int maxOccs = 0;
	for(int iPos = 0;iPos < (int)chaine.size();iPos++) {
		char ancien = chaine[iPos];
		char nouveau = chaine[iPos];
		if(nouveau == 'V') {
			nouveau = 'K';
		}
		else {
			nouveau = 'V';
		}
		
		int nbOccs = 0;
		for(int iAut = 1;iAut < (int)chaine.size();iAut++) {
			if(chaine[iAut - 1] == 'V' && chaine[iAut] == 'K') {
				nbOccs++;
			}
		}
		
		maxOccs = max(maxOccs, nbOccs);
		
		chaine[iPos] = nouveau;
		
		nbOccs = 0;
		for(int iAut = 1;iAut < (int)chaine.size();iAut++) {
			if(chaine[iAut - 1] == 'V' && chaine[iAut] == 'K') {
				nbOccs++;
			}
		}
		
		maxOccs = max(maxOccs, nbOccs);
		
		chaine[iPos] = ancien;
	}
	
	cout << maxOccs << endl;
	return 0;
}