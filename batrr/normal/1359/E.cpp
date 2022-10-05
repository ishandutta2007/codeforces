#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)5e5 + 123, inf = 1e9, mod = 998244353;
const ll INF = 1e18;

int n, k;
ll ans, f[N], rf[N];
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
	if(k == 0)	
		return 1;
	if(k < 0 || k > n)
		return 0;
	return f[n] * rf[k] % mod * rf[n - k] % mod;
}
int main()
{
	f[0] = rf[0] = 1;
	for(int i = 1; i < N; i++)
		f[i] = f[i - 1] * i % mod, rf[i] = bp(f[i], mod - 2);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		ans = (ans + C(k - 1, n / i - 1)) % mod;
	printf("%lld", ans);
}