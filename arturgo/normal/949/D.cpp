#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

long long nbPieces, d, nbOfficiel;
long long nbActuels[100 * 1000];

bool estPossible(long long bord) {
	vector<pair<long long, long long>> inters;
	
	for(long long posAjout = bord;posAjout < nbPieces - bord;posAjout++) {
		long long temps = min(
			1 + posAjout,
			nbPieces - posAjout
		);
		inters.push_back({max<long long>(0, posAjout - temps * d), min<long long>(nbPieces, posAjout + temps * d + 1)});
	}
	
	sort(inters.begin(), inters.end());
	
	map<long long, long long> restes;
	
	long long iInter = 0;
	for(long long iPiece = 0;iPiece < nbPieces;iPiece++) {
		while(iInter < (int)inters.size() && inters[iInter].first == iPiece) {
			if(restes.find(inters[iInter].second) == restes.end()) {
				restes[inters[iInter].second] = 0;
			}
			restes[inters[iInter].second] += nbOfficiel;
			iInter++;
		}
		
		while(!restes.empty() && restes.begin()->first <= iPiece) {
			if(restes.begin()->second != 0)
				return false;
			restes.erase(restes.begin());
		}
		
		long long ajout = nbActuels[iPiece];
		
		while(!restes.empty() && ajout != 0) {
			long long peutAjouter = min(ajout, restes.begin()->second);
			
			restes.begin()->second -= peutAjouter;
			ajout -= peutAjouter;
			
			if(restes.begin()->second == 0)
				restes.erase(restes.begin());
		}
	}
	
	while(!restes.empty()) {
		if(restes.begin()->second != 0)
			return false;
		restes.erase(restes.begin());
	}
	
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nbPieces >> d >> nbOfficiel;
	
	for(long long iPiece = 0;iPiece < nbPieces;iPiece++) {
		cin >> nbActuels[iPiece];
	}
	
	long long deb = -1, fin = 1 + nbPieces / 2;
	while(fin - deb > 1) {
		long long mil = (deb + fin) / 2;
		
		if(estPossible(mil)) {
			fin = mil;
		}
		else {
			deb = mil;
		}
	}
	
	cout << deb + 1 << endl;
	return 0;
}