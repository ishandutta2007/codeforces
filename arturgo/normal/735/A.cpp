#include <iostream>
using namespace std;

int main() {
	int taille, saut;
	cin >> taille >> saut;
	
	string ter;
	cin >> ter;
	
	int posG = 0;
	for(int iPos = 0;iPos < taille;iPos++) {
		if(ter[iPos] == 'G')
			posG = iPos;
	}
	
	for(int iSaut = posG + saut;iSaut < taille;iSaut += saut) {
		if(ter[iSaut] == 'T') {
			cout << "YES" << endl;
			return 0;
		}
		if(ter[iSaut] == '#') {
			break;
		}
	}
	
	for(int iSaut = posG - saut;iSaut >= 0;iSaut -= saut) {
		if(ter[iSaut] == 'T') {
			cout << "YES" << endl;
			return 0;
		}
		if(ter[iSaut] == '#') {
			break;
		}
	}
	
	cout << "NO" << endl;
}