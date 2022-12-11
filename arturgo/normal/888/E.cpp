#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nbNombres, modulo;
vector<int> gauche, droite;

void genPossibles(vector<int>& vals, vector<int>& res, int pos = 0, int sum = 0) {
	if(pos == (int)vals.size()) {
		res.push_back(sum);
		return;
	}
	
	genPossibles(vals, res, pos + 1, sum);
	genPossibles(vals, res, pos + 1, (sum + vals[pos]) % modulo);
}

int main() {
	cin >> nbNombres >> modulo;
	
	gauche.push_back(0);
	droite.push_back(0);
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		int val;
		cin >> val;
		if(iNombre % 2 == 0) {
			gauche.push_back(val);
		}
		else {
			droite.push_back(val);
		}
	}
	
	vector<int> posGauche, posDroite;
	genPossibles(gauche, posGauche);
	genPossibles(droite, posDroite);
	
	sort(posGauche.begin(), posGauche.end());
	sort(posDroite.begin(), posDroite.end());
	
	int maxi = 0;
	
	int iDroite = posDroite.size() - 1;
	for(int iGauche = 0;iGauche < (int)posGauche.size();iGauche++) {
		while(iDroite != -1 && posDroite[iDroite] + posGauche[iGauche] >= modulo) {
			iDroite--;
		}
		
		if(iDroite != -1) {
			maxi = max(maxi, posDroite[iDroite] + posGauche[iGauche]);
		}
	}
	
	cout << maxi << endl;
	return 0;
}