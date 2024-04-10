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
		int a = 0;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			a ^= A[i];
		}
		if (a == 0) {
			cout << "DRAW"
				 << "\n";
			continue;
		}
		for (int i = 40; i >= 0; i--) {
			int bit = ((int)1 << i);
			if ((a & bit) > 0) {
				//cerr << i << endl;
				int cnt = 0;
				for (int j = 0; j < N; j++) {
					if (A[j] & bit) {
						cnt++;
					}
				}
				//cerr << cnt << endl;
				if ((cnt % 4 == 3) && (N % 2 == 1)) {
					cout << "LOSE\n";
				} else {
					cout << "WIN\n";
				}
				break;
			}
		}
	}
}