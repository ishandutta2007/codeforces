#include <iostream>
using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;
int nbFils, mini;

bool estPasse[1000][2];
int dyn[1000][2];

int nbPos(int total, int aMini) {
	if(total == 0 && aMini)
		return 1;
	if(total <= 0)
		return 0;
	
	if(estPasse[total][aMini])
		return dyn[total][aMini];
	estPasse[total][aMini] = true;
	
	long long somme = 0;
	for(int iFils = 1;iFils <= nbFils;iFils++) {
		somme += nbPos(total - iFils, aMini || (iFils >= mini));
		somme %= MOD;
	}
	
	return (dyn[total][aMini] = somme);
}

int main() {
	int total;
	cin >> total >> nbFils >> mini;
	
	cout << nbPos(total, false) << endl;
}