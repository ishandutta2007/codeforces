#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;
	bool ok = false;
	string res(N, '9');
	for (int i = 0; i < N; i++) {
		if (i - K < 0) {
			res[i] = S[i];
		} else {
			res[i] = res[i - K];
		}
	}
	if (res >= S) {
		cout << N << endl;
		cout << res << endl;
	} else {
		for (int i = K - 1; i >= 0; i--) {
			if (res[i] == '9') {
				res[i] = '0';
			} else {
				res[i] += 1;
				break;
			}
		}
		for (int i = K; i < N; i++) {
			res[i] = res[i - K];
		}
		cout << N << endl;
		cout << res << endl;
	}
}