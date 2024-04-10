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
		int N, P, K;
		cin >> N >> P >> K;
		vector<int> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		vector<int> mn(N, (int)1 << 60);
		mn[0] = A[0];
		mn[K - 1] = A[K - 1];
		for (int i = 1; i < N; i++) {
			mn[i] = min(mn[i], mn[i - 1] + A[i]);
			if (i - K >= 0) {
				mn[i] = min(mn[i], mn[i - K] + A[i]);
			}
		}
		int res = 0;
		for (int i = 0; i < N; i++) {
			if (mn[i] <= P) {
				res = i + 1;
			}
		}
		cout << res << "\n";
	}
	return 0;
}