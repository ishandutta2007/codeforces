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
		int A, B;
		string res = "YES";
		cin >> A >> B;
		for (int i = 0; i < A; i++) {
			int a;
			cin >> a;
		}
		for (int i = 0; i < B; i++) {
			int a;
			cin >> a;
			if (a == N) {
				res = "NO";
			}
		}
		cout << res << "\n";
	}
	return 0;
}