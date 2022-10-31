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
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> res(N);
	map<int, int> mp;

	for (int i = 1; i < 27; i++) {
		int t = (1 << i) - 1;
		int x = 1;
		int f = -1;
		for (int z = 2; z <= t; z++) {
			if (t % z == 0) {
				f = z;
				break;
			}
		}
		t = (1 << i) - 1;

		mp[t] = t / f;
	}

	for (int i = 0; i < N; i++) {
		cin >> A[i];

		if (mp.count(A[i]) == 0) {
			for (int k = 26; k >= 0; k--) {
				if ((A[i] & (1 << k))) {
					res[i] = (1 << (k + 1)) - 1;
					break;
				}
			}
		}
		else {
			res[i] = mp[A[i]];
		}



	}
	for (int i = 0; i < N; i++) {
		cout << res[i] << "\n";
	}
}