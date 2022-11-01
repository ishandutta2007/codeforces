#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<string>
using namespace std;
inline int getint() {
	int val = 0;
	char c;
	while ((c = getchar()) && !(c >= '0' && c <= '9'));
	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));
	return val;
}
/*long long pw(long long et, int b) {
	if (b == 0)return 1;
	long long tmp = pw(et, b / 2);
	tmp = (tmp * tmp) % m;
	if (b % 2 == 1)tmp = (tmp * et) % m;
	return tmp;
}*/
const int Y = 200100;
const long long m = 998244353;
long long dp[3001][3001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s, t;
	long long ans = 0;
	cin >> s >> t;
	int ls = s.length(), lt = t.length();
	for (int i = 0; i <= lt; ++i)dp[0][i] = 1;
	for (int i = 1; i <= ls; ++i)dp[i][lt] = (dp[i - 1][lt] * 2) % m;
	for (int i = 0; i < ls; ++i) {
		for (int j = 0; j < lt; ++j)
			if (s[i] == t[j]) {
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j + 1]) % m;
				int s2 = j - i;
				if (s2 >= 0)dp[i + 1][s2] = (dp[i + 1][s2] + dp[i][s2]) % m;
			}
		for (int j = 0; j < lt; ++j) {
			if (j + i>= lt)dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % m;
		}
	}
	for (int i = lt; i <= ls; ++i)ans = (ans + dp[i][0]) % m;
	cout << ans;
	return 0;
}