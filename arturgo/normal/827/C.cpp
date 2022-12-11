#include <iostream>
#include <vector>
using namespace std;

struct Compteur {
	int nbs[4];
	Compteur() {
		for(int iCoeff = 0;iCoeff < 4;iCoeff++) {
			nbs[iCoeff] = 0;
		}
	}
};

Compteur operator + (const Compteur &a, const Compteur &b) {
	Compteur nouv;
	for(int iCoeff = 0;iCoeff < 4;iCoeff++) {
		nouv.nbs[iCoeff] = a.nbs[iCoeff] + b.nbs[iCoeff];
	}
	
	return nouv;
}

int getP2(int a) {
	int s = 1;
	while(s < a) {
		s *= 2;
	}
	return s;
}

vector<Compteur> arbres[10][10];

void modif(vector<Compteur> &a, int pos, Compteur val) {
	pos += (int)a.size() / 2;
	
	while(pos != 0) {
		a[pos] = a[pos] + val;
		pos /= 2;
	}
}

Compteur getSomme(vector<Compteur> &a, int deb, int fin) {
	deb += (int)a.size() / 2;
	fin += (int)a.size() / 2;
	
	Compteur somme;
	while(deb < fin) {
		if(deb % 2 == 1) {
			somme = somme + a[deb];
			deb++;
		}
		if(fin % 2 == 1) {
			fin--;
			somme = somme + a[fin];
		}
		
		deb /= 2;
		fin /= 2;
	}
	
	return somme;
}

int conv[256];

int main() {
	string chaine;
	cin >> chaine;
	
	conv['A'] = 0;
	conv['T'] = 1;
	conv['G'] = 2;
	conv['C'] = 3;
	
	for(int iTaille = 1;iTaille <= 10;iTaille++) {
		for(int iMod = 0;iMod < iTaille;iMod++) {
			arbres[iTaille - 1][iMod] = vector<Compteur>(2 * getP2((chaine.size() + iTaille) / iTaille), Compteur());
		}
	}
	
	for(int iCar = 0;iCar < chaine.size();iCar++) {
		Compteur nouv;
		nouv.nbs[conv[chaine[iCar]]]++;
		
		for(int iTaille = 1;iTaille <= 10;iTaille++) {
			int mod = iCar % iTaille;
			int pos = iCar / iTaille;
			
			modif(arbres[iTaille - 1][mod], pos, nouv);
		}
	}
	
	int nbReqs;
	cin >> nbReqs;
	
	for(int iReq = 0;iReq < nbReqs;iReq++) {
		int type;
		cin >> type;
		
		if(type == 1) {
			int iCar; char val;
			cin >> iCar >> val;
			iCar--;
			
			Compteur nouv;
			nouv.nbs[conv[val]]++;
			nouv.nbs[conv[chaine[iCar]]]--;
			
			for(int iTaille = 1;iTaille <= 10;iTaille++) {
				int mod = iCar % iTaille;
				int pos = iCar / iTaille;
			
				modif(arbres[iTaille - 1][mod], pos, nouv);
			}
			
			chaine[iCar] = val;
		}
		else {
			int deb, fin; string comp;
			cin >> deb >> fin >> comp;
			
			deb--;
			
			int iTaille = comp.size();
			
			int somme = 0;
			
			for(int iMod = 0;iMod < iTaille;iMod++) {
				int mod = (deb + iMod) % iTaille;
				int debPos = (deb + iMod) / iTaille;
				int finPos = (fin - iTaille) / iTaille;
				
				while(finPos * iTaille + mod < fin) {
					finPos++;
				}
				
				Compteur vals = getSomme(arbres[iTaille - 1][mod], debPos, finPos);
				
				somme += vals.nbs[conv[comp[iMod]]];
			}
			
			cout << somme << endl;
		}
	}
	
}