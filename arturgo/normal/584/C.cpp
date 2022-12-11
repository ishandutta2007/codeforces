#include <iostream>
#include <vector>
using namespace std;

int main() {
	int taille, nbDiffs;
	cin >> taille >> nbDiffs;
	
	int nbMemes = taille - nbDiffs;
	
	string a, b;
	cin >> a >> b;

	string c = a;
	
	vector<int> posMemes, posDiffs;
	
	for(int pos = 0;pos < taille;pos++) {
		if(a[pos] == b[pos])
			posMemes.push_back(pos);
		else
			posDiffs.push_back(pos);
	}
	
	for(int pos : posMemes) {
		if(nbMemes == 0) {
			c[pos] = ((c[pos] + 1 - 'a') % 26) + 'a';
		}
		else {
			nbMemes--;
		}
	}
	
	for(int fois = 0;fois < nbMemes;fois++) {
		if(posDiffs.empty()) {
			cout << "-1" << endl;
			return 0;
		}
		c[posDiffs.back()] = a[posDiffs.back()];
		posDiffs.pop_back();
	}
	
	for(int fois = 0;fois < nbMemes;fois++) {
		if(posDiffs.empty()) {
			cout << "-1" << endl;
			return 0;
		}
		c[posDiffs.back()] = b[posDiffs.back()];
		posDiffs.pop_back();
	}
	
	for(int pos : posDiffs) {
		char ac = a[pos];
		char bc = b[pos];
		
		for(char car = 'a';car <= 'z';car++) {
			if(car != ac && car != bc) {
				c[pos] = car;
			}
		}
	}
	
	cout << c << endl;
	
	return 0;
}