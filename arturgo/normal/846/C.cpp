#include <iostream>
#include <vector>
using namespace std;

int nbNombres;
int nombres[10000];
long long sommes[10000];

pair<int, long long> mel(int deb, int fin) {
	int pos = 0;
	long long maxi = 0;
	
	for(int iPos = deb;iPos <= fin;iPos++) {
		long long val = sommes[iPos] - sommes[deb] - (sommes[fin] - sommes[iPos]);
		
		if(val >= maxi) {
			maxi = val;
			pos = iPos;
		}
	}
	
	return make_pair(pos, maxi);
}

int main() {
	cin >> nbNombres;
	
	sommes[0] = 0;
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		cin >> nombres[iNombre];
		sommes[iNombre + 1] = sommes[iNombre] + nombres[iNombre];
	}
	
	vector<int> mels;
	long long melRes = -1000 * 1000 * 1000;
	
	for(int iMil = 0;iMil <= nbNombres;iMil++) {
		pair<int, long long> gauche = mel(0, iMil);
		pair<int, long long> droite = mel(iMil, nbNombres);
		
		if(gauche.second + droite.second > melRes) {
			melRes = gauche.second + droite.second;
			mels.clear();
			mels.push_back(gauche.first);
			mels.push_back(iMil);
			mels.push_back(droite.first);
		}
	}
	
	for(int e : mels) {
		cout << e << " ";
	}
	cout << endl;
	
	return 0;
}