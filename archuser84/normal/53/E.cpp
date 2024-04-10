///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

#pragma GCC target("abm,bmi,bmi2")

const int N = 10;
int a[N];
int n, m, k;

int dp[1<<N][1<<N]; // V, L

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m >> k;
	Loop(i,0,m){
		int v, u;
		cin >>v>>u;
		--v; --u;
		a[v] |= 1<<u;
		a[u] |= 1<<v;
		dp[(1<<u)|(1<<v)][(1<<u)|(1<<v)]=1;
	}
	dp[0][0] = 1;
	Loop(v,0,n) dp[1<<v][0]=1;
	Loop(V,0,1<<n)
	{
		if(__builtin_popcount(V) <= 2) continue;
		Loop(L,0,1<<n){
			if((L|V) != V) continue;
			int v = __builtin_ctz(L), u;
			Loop(u,0,n) {
				if(V&~L&a[v]&(1<<u))
					dp[V][L] += dp[V^(1<<v)][L^(1<<v)]+dp[V^(1<<v)][L^(1<<v)^(1<<u)];
			}
		}
	}
	//Loop(V,0,1<<n){Loop(L,0,1<<n){cout << dp[V][L] << ' ';}cout<<'\n';}
	int ans = 0;
	Loop(L,0,1<<n){
		if(__builtin_popcount(L)==k) ans += dp[(1<<n)-1][L];
	}
	cout << ans << '\n';
}