#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		bool ok = false;
		int sum = 0;
		bool ok2 = false;
		string res = "cyan";
		for (int j = 0; j < (int)S.size(); j++) {
			sum += (S[j] - '0');
			if (S[j] == '0') {
				if (ok) {
					ok2 = true;
				}
				ok = true;
			} else {
				if ((S[j] - '0') % 2 == 0) {
					ok2 = true;
				}
			}
		}
		if (ok && ok2 && sum % 3 == 0) {
			res = "red";
		}

		cout << res << "\n";
	}

	return 0;
}