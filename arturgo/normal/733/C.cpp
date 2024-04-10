#include <iostream>
#include <vector>

using namespace std;

int nbMonstres;
bool possible = true;
vector<pair<int, char> > mvts;
int taillesG[1000];

void mange(int debut, int fin, int reste) {
	vector<int> tailles;
	
	for(int iTaille = debut;iTaille < fin;iTaille++) {
		tailles.push_back(taillesG[iTaille]);
	}
	
	while((int)tailles.size() >  1) {
		int maxi = 0;
		for(int taille : tailles) {
			maxi = max(taille, maxi);
		}
		
		bool cont = true;
		for(int iTaille = 0;cont && iTaille < (int)tailles.size();iTaille++) {
			if(maxi == tailles[iTaille]) {
				if(iTaille != 0 && tailles[iTaille] > tailles[iTaille - 1]) {
					tailles[iTaille] += tailles[iTaille - 1];
					tailles.erase(tailles.begin() + iTaille - 1);
					
					mvts.push_back(make_pair(iTaille + reste, 'L'));
					
					cont = false;
					
				}
				if(cont && iTaille != (int)tailles.size() - 1 && tailles[iTaille] > tailles[iTaille + 1]) {
					tailles[iTaille] += tailles[iTaille + 1];
					tailles.erase(tailles.begin() + iTaille + 1);
					
					mvts.push_back(make_pair(iTaille + reste, 'R'));
					
					cont = false;
				}
			}
		}
		
		if(cont) {
			possible = false;
			return ;
		}
	}
}

int main() {
	cin >> nbMonstres;
	
	for(int iMonstre = 0;iMonstre < nbMonstres;iMonstre++) {
		cin >> taillesG[iMonstre];
	}
	
	int nbRestes;
	cin >> nbRestes;
	
	int iMonstre = 0;
	
	for(int iReste = 0;iReste < nbRestes;iReste++) {
		int taille;
		cin >> taille;
		
		int somme = 0;
		int debut = iMonstre;
		
		while(somme < taille && iMonstre != nbMonstres) {
			somme += taillesG[iMonstre];
			iMonstre++;
		}
		
		if(somme != taille) {
			possible = false;
		}
		
		int fin = iMonstre;
		
		mange(debut, fin, iReste);
	}
	
	if(iMonstre != nbMonstres)
		possible = false;
	
	if(!possible)
		cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for(pair<int, char> mvt : mvts) {
			cout << mvt.first + 1 << " " << mvt.second << endl;
		}
	}
	return 0;
}