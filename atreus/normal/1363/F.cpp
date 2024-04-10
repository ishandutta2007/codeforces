#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2000 + 10;
const int mod = 1e9 + 7;

int a[30], b[30];
int dp[maxn][maxn];
int last[30];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		for (int i = 0; i < 26; i++)
			a[i] = b[i] = 0;
		for (int i = 0; i < (int)s.size(); i++)
			a[(int)s[i]-'a'] ++;
		for (int i = 0; i < (int)t.size(); i++)
			b[(int)t[i]-'a'] ++;
		bool flag = true;
		for (int i = 0; i < 26; i++)
			if (a[i] != b[i])
				flag = false;
		if (!flag){
			cout << -1 << '\n';
			continue;
		}
		for (int i = 0; i < 26; i++)
			last[i] = -1, a[i] = 0, b[i] = 0;
		int now = 0;
		for (int i = 1; i <= n; i++){
			int c = (int)s[i-1] - 'a';
			a[c] ++;
			while (b[c] < a[c])
				b[(int)t[now ++] - 'a'] ++;
			dp[i][now-1] = n;
			for (int j = now; j <= n; j++){
				dp[i][j] = min(dp[i][j-1], dp[i-1][j] + 1);
				if (s[i-1] == t[j-1])
					dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
			}
		}
		cout << dp[n][n] << '\n';
	}
}