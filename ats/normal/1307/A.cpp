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
		int N, D;
		cin >> N >> D;
		vector<int> A(N);
		int res = 0;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		int cur = 0;
		for (int i = 1; i < N; i++) {
			if (cur + i <= D) {
				for (int j = 0; j < A[i]; j++) {
					if (cur + i <= D) {
						cur += i;
						A[0]++;
					}
				}
			}
		}
		cout << A[0] << "\n";
	}
	return 0;
}