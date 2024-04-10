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
		int X;
		cin >> X;
		int N;
		string S;
		cin >> S;
		N = S.size();
		int res = N;
		for (int i = 0; i < X; i++) {
			if ((int)S.size() < X) {
				int a = S[i] - '1';
				for (int j = 0; j < a; j++) {
					for (int k = i + 1; k < res; k++) {
						if ((int)S.size() >= X) break;
						S.push_back(S[k]);
					}
				}
			}
			res += (res - i - 1) * (S[i] - '1');
			res %= MOD;
		}
		res += MOD;
		res %= MOD;
		cout << res << "\n";
	}
	return 0;
}