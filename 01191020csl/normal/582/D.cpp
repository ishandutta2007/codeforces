#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int f[4001][4001][2][2];
int g[4001];
int main() {
	int p, k;
	cin >> p >> k;
	string s;
	cin >> s;
	int len = 0, st = 0;
	while (st < s.size()) {
		long long num = 0;
		for (int i = st; i < s.size(); i++) {
			num = num * 10 + s[i] - '0';
			s[i] = num / p + '0', num %= p;
		}
		g[++len] = num;
		while (st < s.size() && s[st] == '0') ++st;
	}
	reverse(g + 1, g + len + 1);
	f[0][0][1][0] = 1;
	for (int i = 1; i <= len; i++)
		for (int j = 0; j <= i; j++) {
			f[i][j][0][0] = (1ll*p*(p+1)/2%mod*f[i-1][j][0][0]+1ll*g[i]*(g[i]+1)/2%mod*f[i-1][j][1][0]
				+1ll*p*(p-1)/2%mod*f[i-1][j][0][1]+1ll*(2*p-g[i]-1)*g[i]/2%mod*f[i-1][j][1][1])%mod;
			f[i][j][1][0] = (1ll*(g[i]+1)*f[i-1][j][1][0]+1ll*(p-g[i]-1)*f[i-1][j][1][1])%mod;
			if (j) {
				f[i][j][0][1] = (1ll*p*(p-1)/2%mod*f[i-1][j-1][0][0]%mod+1ll*g[i]*(g[i]-1)/2%mod*f[i-1][j-1][1][0]
					+1ll*p*(p+1)/2%mod*f[i-1][j-1][0][1]+1ll*(2*p-g[i]+1)*g[i]/2%mod*f[i-1][j-1][1][1])%mod;
				f[i][j][1][1] = (1ll*g[i]*f[i-1][j-1][1][0]+1ll*(p-g[i])*f[i-1][j-1][1][1])%mod;
			}
		}
	int ans = 0;
	for (int i = k; i <= len; i++) ans = (1ll*ans+f[len][i][0][0]+f[len][i][1][0])%mod;
	cout << ans << endl;
}