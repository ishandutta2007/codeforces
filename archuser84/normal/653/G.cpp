///
///   Oh? You're approaching me?
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int mod = 1e9+7;
const int N = 300'010, M=20;
ll fct[N], ifct[N], p2[N];

ll mpow(ll x, ll y){ll ans=1; while(y){if(y&1)ans=ans*x%mod;x=x*x%mod;y>>=1;} return ans;}
ll inv(ll x){return mpow(x, mod-2);}
ll C(ll n, ll r){return r<0 || r>n? 0ll: fct[n]*ifct[r]%mod*ifct[n-r]%mod;}

void init() // OpenRC
{
	p2[0] = fct[0] = ifct[0] = 1;
	Loop(i,1,N) {
		p2[i] = p2[i-1]*2 % mod;
		fct[i] = fct[i-1]*i % mod;
		ifct[i] = inv(fct[i]);
	}
}

int cnt[N][M];
int n;

int main()
{
	init();
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n)
	{
		int x;
		cin >> x;
		for(int d=2; d*d <= x; ++d){
			if(x%d) continue;
			int cnt;
			for(cnt=0; x%d==0; x/=d, ++cnt);
			::cnt[d][cnt]++;
		}
		if(x) cnt[x][1]++;
	}
	ll ans = 0;
	Loop(i,2,N)
	{
		cnt[i][0] = n;
		Loop(j,1,M) cnt[i][0] -= cnt[i][j];
		int mr=n;
		Loop(j,0,M){
			mr -= cnt[i][j];
			ll Cmore = p2[n-mr];
			ll C2less = 0;
			Loop(k,0,mr+1){
				ans = (ans + C(mr, k)*C2less) % mod;
				ans = (ans + C(mr, k)*k%mod*Cmore) % mod;
				Cmore = (Cmore + mod - C(n-mr, k)) % mod;
				C2less = (C2less + C(n-mr, k)*k) % mod;
			}
		}
	}
	cout << ans << '\n';
}