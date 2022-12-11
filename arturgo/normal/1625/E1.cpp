#include <iostream>
#include <queue>
#include <map>
#define int long long
using namespace std;

const int MAX_POINTS = 300 * 1000 + 1;

vector<int> inters[2 * MAX_POINTS];
int hauteurs[MAX_POINTS];
int indices[MAX_POINTS];

map<pair<int, int>, int> dyn;

int solve(int deb, int fin) {
	if(deb >= fin) return 0;
	
	if(dyn.count({deb, fin})) return dyn[{deb, fin}];
	
	int h = hauteurs[deb];
	int idDeb = indices[deb];
	int idFin = indices[fin];
	
	if(idFin - idDeb == 1) {
		int val = 1 + solve(deb + 1, fin - 1);
		return dyn[{deb, fin}] = val;
	}
	
	int dist = 1;
	while(idDeb + (2 * dist) < idFin) {
		dist *= 2;
	}
	
	return dyn[{deb, fin}] = solve(deb, inters[h][idDeb + dist]) 
	+ solve(inters[h][idDeb + dist], fin) 
	+ dist * (idFin - idDeb - dist);
}

signed main() {
	ios_base::sync_with_stdio(false);
	
	int tailleChaine, nbReqs;
	cin >> tailleChaine >> nbReqs;
	
	string chaine;
	cin >> chaine;
	
	inters[MAX_POINTS].push_back(0);
	indices[0] = 0;
	hauteurs[0] = MAX_POINTS;
	
	int somme = 0;
	for(int iCar = 0;iCar < chaine.size();iCar++) {
		somme += (chaine[iCar] == '(') ? 1 : -1;
		hauteurs[iCar + 1] = MAX_POINTS + somme;
		indices[iCar + 1] = inters[MAX_POINTS + somme].size();
		inters[MAX_POINTS + somme].push_back(iCar + 1);
	}
	
	for(int iReq = 0;iReq < nbReqs;iReq++) {
		int t, deb, fin;
		cin >> t >> deb >> fin;
		deb--;
		
		cout << solve(deb, fin) << endl;
	}
	return 0;
}