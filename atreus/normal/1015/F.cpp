#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
 
const int maxn = 200 + 10;
const int mod = 1e9 + 7;

int f[maxn], dp[maxn][maxn][maxn], pd[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	if (s.size() > 2 * n)
		return cout << 0 << endl, 0;
	int k = 0;
	for (int i = 1; i < s.size(); i++){
		while (k > 0 and s[i] != s[k])
			k = f[k];
		k += (s[i] == s[k]);
		f[i + 1] = k;
	}
	int m = s.size();
	
	for (int i = 0; i <= 2 * n; i++){
		for (int j = 0; j <= i; j++){
			if (i == 0){
				pd[i][j] = (j == 0);
				continue;
			}
			if (j > 0)
				pd[i][j] = (pd[i - 1][j - 1] + pd[i - 1][j + 1]) % mod;
			else
				pd[i][j] = pd[i - 1][j + 1];
		}
	}

	dp[0][0][0] = 1;
	for (int i = 0; i < 2 * n; i++){
		for (int j = 0; j < m; j++){
			for (int k = 0; k <= i; k++){
				if (k > 0){ // next character is )
					int x = j;
					while (x > 0 and s[x] != ')')
						x = f[x];
					x += (s[x] == ')');
					dp[i + 1][x][k - 1] += dp[i][j][k];
					dp[i + 1][x][k - 1] %= mod;
				}
				int x = j;
				while (x > 0 and s[x] != '(')
					x = f[x];
				x += (s[x] == '(');
				dp[i + 1][x][k + 1] += dp[i][j][k];
				dp[i + 1][x][k + 1] %= mod;
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= 2 * n; i++){
		for (int k = 0; k <= i; k++){
			int num = 1ll * dp[i][m][k] * pd[2 * n - i][k] % mod;
			answer = (answer + num) % mod;
		}
	}
	cout << answer << endl;
}