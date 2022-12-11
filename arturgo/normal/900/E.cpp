#include <iostream>
using namespace std;

int cumulInterro[200 * 1000];
int precalc[200 * 1000][2];
pair<int, int> dyn[200 * 1000];

int main() {
	int taille;
	cin >> taille;
	
	string chaine;
	cin >> chaine;
	
	int bloc;
	cin >> bloc;
	
	cumulInterro[0] = 0;
	for(int iPos = 0;iPos < taille;iPos++) {
		dyn[iPos] = make_pair(0, 0);
		cumulInterro[iPos + 1] = cumulInterro[iPos] + (chaine[iPos] == '?'?1:0);
	}
	dyn[taille] = make_pair(0, 0);
	
	precalc[chaine.size()][0] = 0;
	precalc[chaine.size()][1] = 0;
	for(int iPos = taille - 1;iPos >= 0;iPos--) {
		precalc[iPos][0] = 0;
		precalc[iPos][1] = 0;
		if(chaine[iPos] == 'a' || chaine[iPos] == '?') {
			precalc[iPos][0] = 1 + precalc[iPos + 1][1];
		}
		if(chaine[iPos] == 'b' || chaine[iPos] == '?') {
			precalc[iPos][1] = 1 + precalc[iPos + 1][0];
		}
	}
	
	for(int iPos = 0;iPos < taille;iPos++) {
		if(precalc[iPos][0] >= bloc) {
			int fin = iPos + bloc;
			dyn[fin] = max(dyn[fin], {dyn[iPos].first + 1, dyn[iPos].second - cumulInterro[fin] + cumulInterro[iPos]});
		}
		dyn[iPos + 1] = max(dyn[iPos + 1], dyn[iPos]);
	}
	
	cout << -dyn[chaine.size()].second << endl;
	return 0;
}