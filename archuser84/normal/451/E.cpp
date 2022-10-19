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

const int mod = 1e9+7;
const int N = 22;
ll inv[N];
ll a[N];
int n;

ll C(ll n, ll r){
	if(r < 0 || n < r) return 0;
	ll ans = 1; n %= mod;
	Loop(i,0,r) ans = ans*inv[r-i]%mod*(n-i)%mod;
	return ans;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	ll s;
	cin >> n >> s; s+=n;
	Loop(i,0,n) cin >> a[i];
	inv[1] = 1; Loop(x,2,N) inv[x] = mod - (mod/x)*inv[mod%x]%mod;
	ll ans = 0;
	Loop(msk,0,1<<n){
		ll t = s;
		Loop(i,0,n) if(msk&(1<<i)) t -= a[i]+1;
		ans += __builtin_popcount(msk)&1? -C(t-1,n-1): C(t-1,n-1);
	}
	ans = (ans%mod+mod)%mod;
	cout << ans << '\n';
}