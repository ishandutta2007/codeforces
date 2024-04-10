#include <iostream>
#include <algorithm>
using namespace std;

const long long MOD = 1000 * 1000 * 1000 + 7;
string n;
long long nbDeps[1003];
long long coeffBin[1003][1003];

long long nbPP(long long i, long long pos) {
	if(pos == (int)n.size())
		return i == 0;
	if(i < 0 || i > (int)n.size() - pos)
		return 0;
	if(n[pos] == '0')
		return nbPP(i, pos + 1);
	
	return (nbPP(i - 1, pos + 1) + coeffBin[n.size() - pos - 1][i]) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;

	long long k;

	cin >> k;
	if(k == 0) {
		cout << 1 << endl;
		return 0;
	}
	if(k == 1) {
		cout << n.size() - 1 << endl;
		return 0;
	}

	for(long long iLig = 0;iLig < 1003;iLig++) {
		for(long long iCol = 1;iCol < iLig;iCol++) {
			coeffBin[iLig][iCol] = (coeffBin[iLig - 1][iCol] + coeffBin[iLig - 1][iCol - 1]) % MOD;
		}
		coeffBin[iLig][0] = coeffBin[iLig][iLig] = 1;
	}

	long long nbSols = 0;

	nbDeps[1] = -1;
	for(long long i = 1;i < 1003;i++) {
		nbDeps[i] = nbDeps[__builtin_popcount(i)] + 1;
		if(nbDeps[i] == k - 1) {
			nbSols += nbPP(i, 0);
		}
		nbSols %= MOD;
	}

	cout << nbSols << endl;
	return 0;
}