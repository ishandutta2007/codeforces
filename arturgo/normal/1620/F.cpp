#include <iostream>
#include <vector>
using namespace std;

const int INFINI = 1000 * 1000 * 1000;

vector<int> nombres;

int curPasse = 0;
int derPasse[1000 * 1000 + 42][2];
int dyn[1000 * 1000 + 42][2];

int max_hauteur(int pos, int signe) {
	if(pos == (int)nombres.size() - 1) return INFINI;

	int dSigne = (1 + signe) / 2;
	if(derPasse[pos][dSigne] == curPasse)
		return dyn[pos][dSigne];
	derPasse[pos][dSigne] = curPasse;
	
	int maxi = -INFINI;
	int val = signe * nombres[pos];
	
	{
		int hauteur = max_hauteur(pos + 1, -1);
	   
		if(hauteur >= val)
			maxi = max(maxi, -nombres[pos + 1]);
		if(-nombres[pos + 1] >= val)
			maxi = max(maxi, hauteur);
	}
	{
		int hauteur = max_hauteur(pos + 1, 1);
	   
		if(hauteur >= val)
			maxi = max(maxi, nombres[pos + 1]);
		if(nombres[pos + 1] >= val)
			maxi = max(maxi, hauteur);
	}
	
	dyn[pos][dSigne] = maxi;
	return maxi;
}

void max_hauteur_affiche(int pos, int signe) {
	if(pos == (int)nombres.size() - 1) {
		cout << signe * nombres[pos] << endl;
		return;
	}
	
	int val = signe * nombres[pos];
	cout << val << " ";
	
	int maxi = max_hauteur(pos, signe);
	
	{
		int hauteur = max_hauteur(pos + 1, -1);
	   
		if(hauteur >= val && -nombres[pos + 1] == maxi) {
			max_hauteur_affiche(pos + 1, -1); return;
		}
		if(-nombres[pos + 1] >= val && hauteur == maxi) {
			max_hauteur_affiche(pos + 1, -1); return;
		}
	}
	{
		int hauteur = max_hauteur(pos + 1, 1);
	   
		if(hauteur >= val && nombres[pos + 1] == maxi) {
			max_hauteur_affiche(pos + 1, 1); return;
		}
		if(nombres[pos + 1] >= val && hauteur == maxi) {
			max_hauteur_affiche(pos + 1, 1); return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int nbTests;
	cin >> nbTests;
	
	for(int iTest = 0;iTest < nbTests;iTest++) {
		int nbNombres;
		cin >> nbNombres;
		
		for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
			int nombre;
			cin >> nombre;
			nombres.push_back(nombre);
		}
		
		curPasse++;
		
		int max_h = max(
			max_hauteur(0, -1),
			max_hauteur(0, 1)
		);
		
		if(max_h == -INFINI) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			
			if(max_h == max_hauteur(0, -1)) {
				max_hauteur_affiche(0, -1);
			}
			else {
				max_hauteur_affiche(0, 1);
			}
		}
		
		nombres.clear();
	}
	return 0;
}