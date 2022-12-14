#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3000 + 10;
const int mod = 998244353;

string s, t;
int n, m;
int answer=0;

int dp[maxn][maxn], pd[maxn];
int mp[maxn][maxn];

int f(int a, int l){
	if (mp[a][l] != -1)
		return mp[a][l];
	int len = m - l;
	if (len == 0){
		if (a == 0)
			return mp[a][l] = 1;
		int ret = 2 * f(a-1, l);
		if (ret >= mod)
			ret -= mod;
		return mp[a][l] = ret;
	}
	if (a < len)
		return mp[a][l] = 0;
	if (a == len){
		if (len == m){
			answer += pd[l];
			if (answer >= mod)
				answer -= mod;
		}
		return mp[a][l] = pd[l];
	}
	int ret = f(a-1, l);
	if (s[a-1] == t[l]){
		ret += f(a-1, l+1);
		if (ret >= mod)
			ret -= mod;
	}
	if (len == m){
		answer += ret;
		if (answer >= mod)
			answer -= mod;
	}
	return mp[a][l] = ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> s >> t;
	n = s.size(), m = t.size();
	for (int len = 1; len <= m; len++){
		for (int i = 0; i + len - 1 < m; i++){
			int j = i + len - 1;
			if (len == 1){
				dp[i][j] = 2 * (s[0] == t[i]);
				continue;
			}
			if (s[len-1] == t[i]){
				dp[i][j] += dp[i+1][j];
				if (dp[i][j] >= mod)
					dp[i][j] -= mod;
			}
			if (s[len-1] == t[j]){
				dp[i][j] += dp[i][j-1];
				if (dp[i][j] >= mod)
					dp[i][j] -= mod;
			}
		}
	}
	for (int i = 0; i < m; i++)
		pd[i] = dp[i][m-1];
	memset(mp, -1, sizeof mp);
	f(n, 0);
	cout << answer << endl;
}