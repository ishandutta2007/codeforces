#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s1, s2, virus;

	cin >> s1 >> s2 >> virus;

	static int nxt[102]['Z' + 1];
	static int dp[102][102][102];

	for (int i = 0; i < (int) virus.size(); ++i)
		for (char c = 'A'; c <= 'Z'; ++c) {
			string s = virus.substr(0, i) + c;

			while (virus.substr(0, s.size()) != s)
				s = s.substr(1);
			nxt[i][c] = (int) s.size();
			if (c == virus[i])
				assert(nxt[i][c] == i + 1);
		}

	for (int i = (int) s1.size(); i >= 0; --i)
		for (int j = (int) s2.size(); j >= 0; --j)
			for (int k = (int) virus.size(); k >= 0; --k) {
				int &res = dp[i][j][k];
				if (k == (int) virus.size())
					res = -200;
				else {
					res = max(dp[i + 1][j][k], dp[i][j + 1][k]);
					if (i < (int) s1.size() && j < (int) s2.size() && s1[i] == s2[j])
						res = max(res, 1 + dp[i + 1][j + 1][nxt[k][s1[i]]]);
				}
			}

	if (!dp[0][0][0])
		cout << 0;
	else {
		int i = 0, j = 0, k = 0;
		string res;
		while (dp[i][j][k]) {
			if (i < (int) s1.size() && dp[i][j][k] == dp[i + 1][j][k])
				++i;
			else if (j < (int) s2.size() && dp[i][j][k] == dp[i][j + 1][k])
				++j;
			else {
				res += s1[i];
				assert(k < (int ) virus.size());
				assert(s1[i] == s2[j]);
				k = nxt[k][s1[i]];
				++i, ++j;
			}
		}
		cout << res;
	}
	return 0;
}