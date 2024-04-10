#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 3650, mod = 998244353;

int n, m, q, cntx, cnty;
bool wx[N], wy[N];
ll f[N], rf[N], ans, dp[N][N], dpx[N], dpy[N];

ll bp(ll x, ll p){
	ll res = 1;
	while(p){
		if(p & 1)
			res = res * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return res;
}
ll C(int k, int n){
	if(k < 0 || k > n)
		return 0;
	return f[n] * rf[k] % mod * rf[n - k] % mod;
}
int getx(int a, int b){
	return dpx[b] * C(a, cntx - 2 * b) % mod;
}
int gety(int a, int b){
	return dpy[b] * C(a, cnty - 2 * b) % mod;
}

int main()
{
	f[0] = rf[0] = 1;
	for(int i = 1; i < N; i++){
		f[i] = f[i - 1] * i % mod;
		rf[i] = bp(f[i], mod - 2);
	}
	
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 0; i < q; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		wx[x] = 1;
		wy[y] = 1;
		scanf("%d%d", &x, &y);
		wx[x] = 1;
		wy[y] = 1;
	}            	
	for(int i = 1; i <= n; i++)
		if(!wx[i])
			cntx++;	
	for(int i = 1; i <= m; i++)
		if(!wy[i])
			cnty++;
			         
	wx[0] = 1;
	wy[0] = 1;

	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		
		for(int j = 0; j < N; j++)
			dp[i][j] = dp[i - 1][j];
		
		if(wx[i] || wx[i - 1])
			continue;
		
		for(int j = 1; j < N; j++)
			dp[i][j] = (dp[i][j] + dp[i - 2][j - 1]) % mod;
	}
	for(int i = 0; i < N; i++)
		dpx[i] = dp[n][i];
	
	dp[0][0] = 1;	
	for(int i = 1; i <= m; i++){
		
		for(int j = 0; j < N; j++)
			dp[i][j] = dp[i - 1][j];
		
		if(wy[i] || wy[i - 1])
			continue;
		
		for(int j = 1; j < N; j++)
			dp[i][j] = (dp[i][j] + dp[i - 2][j - 1]) % mod;
	}
	for(int i = 0; i < N; i++)
		dpy[i] = dp[m][i];

	for(int a = 0; a < N; a++)
		for(int b = 0; b < N; b++)
			ans = (ans + f[a] * f[b] % mod * getx(a, b) % mod * gety(b, a) % mod) % mod; 
	printf("%lld", ans);
	return 0;
}