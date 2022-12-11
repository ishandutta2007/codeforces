#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

bool estPalin(string chaine) {
	for(int iCar = 0;iCar < (int)chaine.size();iCar++) {
		if(chaine[iCar] != chaine[(int)chaine.size() - iCar - 1])
			return false;
	}
	
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	string chaine;
	cin >> chaine;
	
	int nb;
	cin >> nb;
	
	if(chaine.size() % nb != 0) {
		cout << "NO" << endl;
		return 0;
	}
	
	int taille = (int)chaine.size() / nb;
	
	for(int iFois = 0;iFois < nb;iFois++) {
		if(!estPalin(chaine.substr(iFois  * taille, taille))) {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	return 0;
}