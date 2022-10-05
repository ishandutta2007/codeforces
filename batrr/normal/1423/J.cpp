#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7, LOG = 62;
const ll INF = 1e18;
 
ll dp[100][100];
void add(ll &x, ll y){
	x += y;
	if(x >= mod)
		x -= mod;
}
ll rofl(ll x){
	x >>= 1;
	x++;
	ll a = (x >> 1);
	ll b = ((x + 1) >> 1);
	a %= mod;
	b %= mod;
	return a * (a + 1) / 2 % mod + b * (b + 1) / 2 % mod;	
}
int main()
{
	int n;
	scanf("%d", &n);
	while(n--){
		ll x;
		scanf("%lld", &x);
		/*
		x = n;
		for(int i = 0; i <= LOG; i++)
			for(int j = 0; j <= LOG; j++)
				dp[i][j] = 0;				
		dp[0][0] = 1;
		for(int i = 0; i < LOG; i++)
			for(int j = 0; j < 8; j++)
				for(int q = 0; q < 8; q++)
					if((q ^ j ^ (x >> i)) & 1 ^ 1)
						add(dp[i + 1][(q + j) >> 1], dp[i][q]);			
		printf("%lld\n", dp[LOG][0]);
		assert(dp[LOG][0] == rofl(x));
		*/
		printf("%lld\n", rofl(x) % mod);
	}
}