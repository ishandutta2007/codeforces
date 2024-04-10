#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
char s[2001];
int f[2001][2001], g[2001][2001];
int main() {
//	freopen("string.in", "r", stdin);
//	freopen("string.out", "w", stdout);
	int n, k;
	cin >> n >> k >> s + 1;
	f[0][0] = g[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++) {
			int tmp1 = g[i-1][j], tmp2 = 0;
			for (int l = i - 1; l >= 0; l--)
				if (j >= (n-i+1)*(i-l))	tmp2 = (tmp2 + f[l][j-(n-i+1)*(i-l)])%mod;
				else break;
			f[i][j] = (1ll*(s[i]-'a')*tmp1+1ll*('z'-s[i])*tmp2)%mod;
			g[i][j] = (g[i-1][j] + f[i][j]) % mod;
		}
	cout << g[n][k] << endl;
}