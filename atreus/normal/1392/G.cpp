#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;

int a[maxn], b[maxn];
int f[21];
int dp[(1<<20)+10], pd[(1<<20)+10];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		a[i]--,b[i]--;
	}
	memset(dp, 63, sizeof dp);
	memset(pd, -63, sizeof pd);
	for (int i = 0; i < k; i++)
		f[i] = i;
	int x = 0;
	for (int j = 0; j < k; j++)
		if (s[j] == '1')
			x |= (1 << j);
	dp[x] = -1;
	for (int i = 0; i < n; i++){
		int tmp = f[a[i]];
		f[a[i]] = f[b[i]];
		f[b[i]] = tmp;
		int x = 0;
		for (int j = 0; j < k; j++)
			if (s[j] == '1')
				x |= (1 << f[j]);
		dp[x] = min(dp[x],i);
	}
	for (int i = 0; i < k; i++)
		f[i] = i;
	for (int i = 0; i < n; i++){
		int tmp = f[a[i]];
		f[a[i]] = f[b[i]];
		f[b[i]] = tmp;
		int x = 0;
		for (int j = 0; j < k; j++)
			if (t[j] == '1')
				x |= (1 << f[j]);
		pd[x] = max(pd[x],i);
	}
	for (int i = k-1; i >= 0; i--)
		for (int mask = 0; mask < (1<<k); mask++)
			 if (!(mask & (1<<i))){
				 dp[mask] = min(dp[mask],dp[mask^(1<<i)]);
				 pd[mask] = max(pd[mask],pd[mask^(1<<i)]);
			 }
	int opt = -1, cnt = -1;
	for (int mask = 0; mask < (1 << k); mask++)
		if (pd[mask]-dp[mask] >= m and cnt < __builtin_popcount(mask)){
			cnt = __builtin_popcount(mask);
			opt = mask;
		}
	int c1 = 0;
	for (int i = 0; i < k; i++)
		c1 += (s[i] == '1') + (t[i] == '1');
	cout << 2*cnt-c1+k << '\n';
	cout << dp[opt]+2 << ' ' << pd[opt]+1 << '\n';
}