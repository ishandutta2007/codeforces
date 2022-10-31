#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	int A[4];
	for (int i = 0; i < 4; i++) {
		cout << "? " << i + 1 << " " << i + 2 << endl;
		cout << flush;
		cin >> A[i];
	}

	vector<int> X = { 4 , 8, 15, 16, 23, 42 };
	do {

		bool ok = true;
		for (int i = 0; i < 4; i++) {
			if (X[i] * X[i + 1] != A[i]) {
				ok = false;
			}
		}
		if (ok)break;
	} while (next_permutation(X.begin(), X.end()));

	cout << "!";
	for (int i = 0; i < 6; i++ ) {
		cout << " " << X[i];
	}
	cout << endl;
	cout << flush;
}