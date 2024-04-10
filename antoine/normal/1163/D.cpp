#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define DBG(v) cerr << #v << " = " << (v) << endl;

struct DS {
	int n;
	string s;
	vector<int> lps;
	vector<array<int, 26>> nxt;

	void computeLPS() {
		lps.resize(n, 0);

		int len = 0;

		for (int i = 1; i < n;)
			if (s[i] == s[len])
				lps[i++] = ++len;
			else if (len)
				len = lps[len - 1];
			else
				lps[i++] = 0;
	}

	void computeNxt() {
		nxt.resize(n + 1);
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j < 26; ++j)
				nxt[i][j] = i < n && j == s[i] - 'a' ? i + 1 : !i ? 0 : nxt[lps[i - 1]][j];
		}
	}

	DS(string _s) :
			s(_s) {
		n = (int) s.size();
		computeLPS();
		computeNxt();
	}
};

int dp[1009][59][59];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s, s1, s2;
	cin >> s >> s1 >> s2;

	DS ds1(s1), ds2(s2);

	const int n = (int) s.size();
	const int n1 = (int) s1.size();
	const int n2 = (int) s2.size();

	for (int i = n; i >= 0; --i)
		for (int j = 0; j <= n1; ++j)
			for (int k = 0; k <= n2; ++k) {
				int &res = dp[i][j][k] = -(int) 1e9;
				if (i == n)
					res = 0;
				else {
					for (char c = 'a'; c <= 'z'; ++c) {
						if (s[i] != '*' && s[i] != c)
							continue;
						const int jj = ds1.nxt[j][c - 'a'];
						const int kk = ds2.nxt[k][c - 'a'];
						res = max(res, (jj == n1) - (kk == n2) + dp[i + 1][jj][kk]);
					}
				}
			}
	cout << dp[0][0][0];
	return 0;
}