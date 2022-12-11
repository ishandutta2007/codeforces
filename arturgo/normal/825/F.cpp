#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string chaine;

int dyn[10000];

vector<int> kmp(int deb, int fin) {
	vector<int> res;
	res.push_back(-1);
	
	for(int iCar = deb;iCar < fin;iCar++) {
		int der = res.back();
		while(der != -1 && chaine[iCar] != chaine[deb + der]) {
			der = res[der];
		}
		
		res.push_back(der + 1);
	}
	
	return res;
}

int nbChiffres(int nb) {
	int nbC = 0;
	while(nb != 0) {
		nb /= 10;
		nbC++;
	}
	return nbC;
}

int main() {
	cin >> chaine;
	
	fill(dyn, dyn + 10 * 1000, 1000 * 1000 * 1000);
	dyn[0] = 0;
		
	for(int iCar = 0;iCar < (int)chaine.size();iCar++) {
		vector<int> bords = kmp(iCar, (int)chaine.size());
		
		for(int iSuiv = iCar + 1;iSuiv <= (int)chaine.size();iSuiv++) {
			int periode = iSuiv - iCar - bords[iSuiv - iCar];
			if((iSuiv - iCar) % periode != 0) {
				periode = iSuiv - iCar;
			}
			
			int nbFois = (iSuiv - iCar) / periode;
			
			dyn[iSuiv] = min(dyn[iSuiv], dyn[iCar] + nbChiffres(nbFois) + periode);
		}
	}
	
	cout << dyn[(int)chaine.size()] << endl;
}