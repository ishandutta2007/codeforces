#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 5010, mod = 998244353;
 
int n;
ll f[N], rf[N], dp[N][N], ans[N];
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
ll inv(ll x){
	return bp(x, mod - 2);
}
int main()
{
	f[0] = rf[0] = 1;
	for(int i = 1; i <= 5000; i++)
		f[i] = f[i - 1] * i % mod, rf[i] = inv(f[i]);
	dp[0][0] = 1;
	for(int i = 1; i <= 5000; i++){
		for(int j = 0; j < i; j++){
			int a = j, b = i - 1 - j;
			dp[a + 1][b] = (dp[a + 1][b] + dp[a][b] * (b + 1)) % mod;
			dp[a][b + 1] = (dp[a][b + 1] + dp[a][b] * (a + 1)) % mod;
		}	
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; i + j < n; j++)
			ans[i] = (ans[i] + dp[i][j] * f[n] % mod * rf[i + j + 1]) % mod;
	for(int i = 0; i < n; i++)
		printf("%lld ", ans[i]);
}