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
		string A, B;
		cin >> A >> B;
		vector<vector<int> > X(20, vector<int>(20, 0));
		bool ok = true;
		for (int i = 0; i < N; i++) {
			X[A[i] - 'a'][B[i] - 'a'] = 1;
			if (A[i] > B[i]) {
				ok = false;
			}
		}
		if (!ok) {
			cout << -1 << "\n";
			continue;
		}
		int res = 0;
		for (int i = 0; i < 20; i++) {
			for (int j = i + 1; j < 20; j++) {
				if (X[i][j] == 1) {
					res++;
					for (int k = j; k < 20; k++) {
						if (X[i][k] == 1) {
							X[j][k] = 1;
						}
					}
					break;
				}
			}
		}
		cout << res << "\n";
	}
	return 0;
}