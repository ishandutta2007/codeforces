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
		string A, B, C;
		cin >> A >> B >> C;
		bool ok = true;
		for (int i = 0; i < A.size(); i++) {
			if (A[i] == C[i] || B[i] == C[i]) {
			} else {
				ok = false;
			}
		}
		if (ok) {
			cout << "YES"
				 << "\n";
		} else {
			cout << "NO"
				 << "\n";
		}
	}
	return 0;
}