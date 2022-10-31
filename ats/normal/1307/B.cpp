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
		int N, X;
		cin >> N >> X;
		vector<int> A(N);
		int res = 0;
		bool f1 = false;
		int mx = 0;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			if (A[i] == X) f1 = true;
			mx = max(mx, A[i]);
		}
		if (f1) {
			cout << 1 << "\n";
		} else {
			cout << max((int)2, (X + mx - 1) / mx) << "\n";
		}
	}
}