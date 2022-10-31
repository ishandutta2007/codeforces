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
	cin.tie(0);
	ios::sync_with_stdio(false);
	int A, B;
	cin >> A >> B;



	if (A < B) {
		cout << -1 << endl;
		return 0;
	}
	double res = 1e18;
	int X = A - B;
	for (int t = 0; t < 2; t++) {
		
		int ii = X / (2 * B);
		for (int i = ii - 10; i <= ii + 10; i++) {
			if (i > 0) {
				if (X >= 2 * i*B) {
					res = min(res, X / (2.0 * i));
				}
			}
		}
		X = A + B;
	}
	cout << fixed << setprecision(15) << res << endl;
}