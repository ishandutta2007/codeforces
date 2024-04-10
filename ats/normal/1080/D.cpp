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
	int Q;
	cin >> Q;
	for (int t = 0; t < Q; t++) {
		int N, K;
		cin >> N >> K;
		bool yes = false;
		int res = 0;
		for (int i = 1; i <= N; i++) {
			int mn = ((int)1 << (i + 1)) - (i + 2);
			if (K < mn)break;
			bool ok = false;
			if (N > 31) {
				ok = true;
			}
			else {
				int mx = ((((int)1 << (2 * N)) - 1) / 3);
				mx -= (((int)1 << (i + 1)) - 1)*((((int)1 << (2 * (N - i))) - 1) / 3);
				cerr << mn << " " << mx << endl;
				if (K <= mx) {
					ok = true;
				}
			}
			if (ok) {
				yes = true;
				res = N - i;
				break;
			}
		}

		if (yes) {
			cout << "YES " << res << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}