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
		N *= 2;
		vector<int> A(N);
		int res = 0;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		vector<int> X;
		int mx = -1;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (mx < A[i]) {
				mx = A[i];
				if (cnt > 0) {
					X.push_back(cnt);
				}
				cnt = 1;
			} else {
				cnt++;
			}
		}
		X.push_back(cnt);

		vector<int> dp((N / 2) + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < X.size(); i++) {
			vector<int> ndp((N / 2) + 1, 0);
			for (int j = 0; j < dp.size(); j++) {
				ndp[j] |= dp[j];
				if (j + X[i] < dp.size()) {
					ndp[j + X[i]] |= dp[j];
				}
			}
			swap(dp, ndp);
		}
		if (dp[N / 2]) {
			cout << "YES"
				 << "\n";
		} else {
			cout << "NO"
				 << "\n";
		}
	}
	return 0;
}