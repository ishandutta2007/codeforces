#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
string s;
bool pal[5000][5000];
int dp[5000][5000];
int add[5002];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s;
	n = s.size();
	for(int i = 0; i < n; i++) {
		pal[i][i] = true;
		dp[i][i] = 1;
		add[1]++;
		add[2]--;
		if(i + 1 < n && s[i] == s[i + 1]) {
			pal[i][i + 1] = true;
			dp[i][i + 1] = 2;
			add[1]++;
			add[3]--;
		}
	}
	for(int i = n - 1; i >= 0; i--)
		for(int j = i + 2; j < n; j++) {
			pal[i][j] = (s[i] == s[j]) && pal[i + 1][j - 1];
			if(pal[i][j]) {
				int len = (j - i + 1) / 2;
				dp[i][j] = min(dp[i][i + len - 1], dp[j - len + 1][j]) + 1;
				add[1]++;
				add[dp[i][j] + 1]--;
			}
		}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += add[i];
		cout << ans << ' ';
	}
}