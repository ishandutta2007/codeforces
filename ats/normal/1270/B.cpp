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
		int l = -1;
		for (int i = 0; i < N - 1; i++) {
			if (abs(A[i] - A[i + 1]) >= 2) {
				l = i;
			}
		}
		if (l == -1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			cout << l + 1 << " " << l + 2 << "\n";
		}
	}
	return 0;
}