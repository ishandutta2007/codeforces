#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> A(N);
		int res = 0;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		int la = -1;
		int mx = 0;
		int mn = (int)1 << 60;
		for (int i = 0; i < N; i++) {
			if (A[i] != -1) {
				if (i > 0) {
					if (A[i - 1] != -1) {
						res = max(res, abs(A[i] - A[i - 1]));
					} else {
						mn = min(mn, A[i]);
						mx = max(mx, A[i]);
					}
				}
				if (i < N - 1) {
					if (A[i + 1] != -1) {
						res = max(res, abs(A[i] - A[i + 1]));
					} else {
						mn = min(mn, A[i]);
						mx = max(mx, A[i]);
					}
				}
			}
		}
		int val = 5;
		if (mn <= mx) {
			val = (mx + mn) / 2;
			res = max(res, (mx - mn + 1) / 2);
		}
		cout << res <<" " << val  << "\n";
	}
	return 0;
}