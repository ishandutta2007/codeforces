#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

long long F[100042];

signed main() {
	ios_base::sync_with_stdio(false);
	
	int nbLigs, nbCols;
	cin >> nbLigs >> nbCols;

	F[0] = 1;
	F[1] = 1;
	for(int i = 2;i <= 100000;i++) {
		F[i] = (F[i - 1] + F[i - 2]) % MOD;
	}

	cout << 2 * (F[nbLigs] + F[nbCols] - 1) % MOD << endl;
	return 0;
}