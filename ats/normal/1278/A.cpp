#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		string S;
		string T;
		cin >> S >> T;
		sort(S.begin(), S.end());
		string res = "NO";
		for (int i = 0; i <= (int)T.size() - (int)S.size(); i++) {
			string a = T.substr(i, S.size());
			sort(a.begin(), a.end());
			if (a == S) {
				res = "YES";
				break;
			}
		}
		cout << res << "\n";
	}
	return 0;
}