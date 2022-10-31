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
	int N, A, B, T;
	cin >> N >> A >> B >> T;
	string S;
	cin >> S;

	int res = 0;

	for (int tt = 0; tt < 2; tt++) {

		int r = T;
		vector<int> X(N + 1);
		X[N] = 0;

		for (int j = N - 1; j >= 0; j--) {
			X[j] = X[j + 1];
			X[j] += A;
			if (S[j] == 'w') {
				X[j] += B;
			}
			X[j]++;
		}

		for (int i = 0; i < N; i++) {


			if (i > 0) {
				r -= A;
			}
			if (S[i] == 'w') {
				r -= B;
			}
			r--;


			int ok = N;
			int ng = i;
			if (r >= 0) {
				res = max(res, i + 1);
				while (ok - ng > 1) {
					int m = (ok + ng) / 2;
					int c = X[m];
					if (c + i * A <= r) {
						ok = m;
					}
					else {
						ng = m;
					}
				}
				res = max(res, i + 1 + N - ok);
			}



		}
		reverse(S.begin() + 1, S.end());
	}


	cout << res << endl;
}