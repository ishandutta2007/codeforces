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
	string S;
	cin >> S;	
	N = S.size();
	vector<int> L(N, N);

	for (int k = 1; k < 10; k++) {
		int mx = N - 2 * k;
		for (int i = 0; i < mx; i++) {
			if (S[i] == S[i + k] && S[i] == S[i + 2 * k]) {
				L[i] = min(L[i], i + 2 * k);
			}

		}
	}
	for (int i = N - 2; i >= 0; i--) {
		L[i] = min(L[i], L[i + 1]);
	}

	int res = (N * (N + 1)) / 2;
	for (int i = 0; i < N; i++) {
		res -= L[i] - i;
	}

	cout << res << endl;
}