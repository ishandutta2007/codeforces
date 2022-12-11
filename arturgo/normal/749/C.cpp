#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool banni[300 * 1000];

int main() {
	int nb;
	cin >> nb;
	
	string chaine;
	cin >> chaine;
	
	int der = -1;
	int cur = nb;
	
	int nbD = 0, nbR = 0;
	char derVu = 'E';
	while(der != cur) {
		der = cur;
		for(int i = 0;i < nb;i++) {
			if(!banni[i] && chaine[i] == 'D' && nbD != 0) {
				banni[i] = true;
				nbD--;
				cur--;
			}
			if(!banni[i] && chaine[i] == 'R' && nbR != 0) {
				banni[i] = true;
				nbR--;
				cur--;
			}
			if(!banni[i]) {
				derVu = chaine[i];
				if(chaine[i] == 'D')
					nbR++;
				else
					nbD++;
			}
		}
	}
	
	cout << derVu << endl;
	return 0;
}