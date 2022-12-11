#include <iostream>
using namespace std;

int vals[1000 * 1000];

int arbre[(1 << 20)];

void ajoute(int pos, int val) {
	pos += (1 << 19);
	
	while(pos != 0) {
		arbre[pos] = max(arbre[pos], val);
		pos /= 2;
	}
}

int getMax(int deb, int fin) {
	deb += (1 << 19);
	fin += (1 << 19);
	
	int maxi = 0;
	while(deb < fin) {
		if(deb % 2 == 1) {
			maxi = max(maxi, arbre[deb]);
			deb++;
		}
		if(fin % 2 == 1) {
			fin--;
			maxi = max(maxi, arbre[fin]);
		}
		fin /= 2;
		deb /= 2;
	}
	
	return maxi;
}

int main() {
	int nb;
	cin >> nb;
	
	for(int i = 0;i < nb;i++) {
		cin >> vals[i];
		
		int maxi = getMax(0, vals[i]);
		ajoute(vals[i], maxi + 1);
	}
	
	cout << getMax(0, 200 * 1000) << endl;
	return 0;
}