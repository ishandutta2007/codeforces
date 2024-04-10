#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_NB_NOMBRES = 3000;
const long long INFINI = (long long)1000 * 1000 * 1000 * 1000 * 1000;

int nbNombres;
long long hauteurs[MAX_NB_NOMBRES];
long long hauteursPossibles[MAX_NB_NOMBRES];

long long cost[2][MAX_NB_NOMBRES];

int main() {
	cin >> nbNombres;
	
	for(int iN = 0;iN < nbNombres;iN++) {
		cin >> hauteurs[iN];
		hauteursPossibles[iN] = hauteurs[iN] - iN;
	}
	
	sort(hauteursPossibles, hauteursPossibles + nbNombres);
	
	for(int iH = 0;iH < nbNombres;iH++) {
		cost[0][iH] = abs(hauteursPossibles[iH] - hauteurs[0]);
	}
	
	bool cur = false;
	for(int iPos = 0;iPos < nbNombres - 1;iPos++) {
		for(int iH = 0;iH < nbNombres;iH++)
			cost[!cur][iH] = INFINI;
		
		for(int iH = 0;iH < nbNombres;iH++) {
			if(iH + 1 < nbNombres)
				cost[cur][iH + 1] = min(cost[cur][iH + 1], cost[cur][iH]);
			cost[!cur][iH] = min(cost[!cur][iH], cost[cur][iH] + abs(hauteursPossibles[iH] + iPos + 1 - hauteurs[iPos + 1]));
		}
		
		cur = !cur;
	}
	
	long long mini = INFINI;
	for(int iH = 0;iH < nbNombres;iH++) {
		mini = min(mini, cost[cur][iH]);
	}
	cout << mini << endl;
	return 0;
}