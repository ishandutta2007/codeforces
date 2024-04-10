#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		string S;
		cin >> S;
		int N = S.size();
		vector<int> res;
		for (int i = 0; i < (int)S.size() - 2; i++) {
			if (S[i] == 'o' && S[i + 1] == 'n' && S[i + 2] == 'e') {
				res.push_back(i + 1 + 1);
				i += 1;
			}
			if (S[i] == 't' && S[i + 1] == 'w' && S[i + 2] == 'o') {
				if (i + 3 < S.size() && S[i + 3] == 'n') {
					res.push_back(i + 2 + 1);
					i += 2;
				} else {
					res.push_back(i + 1 + 1);
					i += 1;
				}
			}
		}
		cout << res.size() << "\n";
		for (int i = 0; i < res.size(); i++) {
			if (i > 0) cout << " ";
			cout << res[i];
		}
		cout << "\n";
	}
	return 0;
}