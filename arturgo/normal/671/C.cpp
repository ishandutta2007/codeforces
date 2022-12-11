#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Inter {
	int deb, fin, val;
	Inter(int _deb = 0, int _fin = 0, int _val = 0) {
		deb = _deb;
		fin = _fin;
		val = _val;
	}
};

int nbNombres;
vector<int> nombres;

vector<int> positions[200 * 1000 + 1];

long long curSomme = 0;
map<int, int> vals;

void supprimer(map<int, int>::iterator it) {
	int nouvVal = 0;
	auto suiv = it;
	suiv++;
	if(suiv != vals.end()) {
		nouvVal = suiv->second;
	}
	
	long long taille = it->first + 1;
	if(it != vals.begin()) {
		auto prec = it;
		prec--;
		taille = it->first - prec->first;
	}
	
	curSomme += taille * (nouvVal - it->second);
	vals.erase(it);
}

void ajouter(int fin, int val) {
	int ancVal = 0;
	auto suiv = vals.lower_bound(fin);
	if(suiv != vals.end()) {
		ancVal = suiv->second;
	}
	
	long long taille = fin + 1;
	if(vals.lower_bound(fin) != vals.begin()) {
		auto prec = vals.lower_bound(fin);
		prec--;
		taille = fin - prec->first;
	}
	
	curSomme += taille * (val - ancVal);
	vals[fin] = val;
}

vector<int> getDiviseurs(int nombre) {
	vector<int> diviseurs;
	for(int div = 1;div * div <= nombre;div++) {
		if(nombre % div == 0) {
			diviseurs.push_back(div);
			if(div != nombre / div)
				diviseurs.push_back(nombre / div);
		}
	}
	return diviseurs;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nbNombres;
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		int nombre;
		cin >> nombre;
		nombres.push_back(nombre);
	
		vector<int> diviseurs = getDiviseurs(nombre);
		for(int diviseur : diviseurs) {
			positions[diviseur].push_back(iNombre);
		}
	}
	
	vector<Inter> inters;
	for(int div = 0;div <= 200 * 1000;div++) {
		sort(positions[div].begin(), positions[div].end());
		int taille = positions[div].size();
		if(taille >= 2) {
			inters.push_back(Inter(positions[div][0] + 1, positions[div][taille - 1], div));
			inters.push_back(Inter(positions[div][1] + 1, nbNombres, div));
			inters.push_back(Inter(0, positions[div][taille - 2], div));
		}
	}
	
	sort(inters.begin(), inters.end(), [&](const Inter &a, const Inter &b) { return a.deb < b.deb; });
	
	int iInter = 0;
	long long somme = 0;
	for(int deb = 0;deb < nbNombres;deb++) {
		while(!vals.empty() && vals.begin()->first <= deb) {
			supprimer(vals.begin());
		}
		
		while(iInter < (int)inters.size() && inters[iInter].deb == deb) {
			auto suiv = vals.lower_bound(inters[iInter].fin);
			
			if(suiv == vals.end() || suiv->second < inters[iInter].val) {
				while(true) {
					auto avant = vals.lower_bound(inters[iInter].fin);
					if(avant == vals.begin())
						break;
					avant--;
					if(avant->second <= inters[iInter].val) {
						supprimer(avant);
					}
					else {
						break;
					}
				}
				ajouter(inters[iInter].fin, inters[iInter].val);
			}
			iInter++;
		}
		
		while(!vals.empty() && vals.begin()->first <= deb) {
			supprimer(vals.begin());
		}
		
		if(!vals.empty()) {
			somme += curSomme - (deb + 1) * (long long)vals.begin()->second;
		}
	}
	
	cout << somme << endl;
	return 0;
}