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
using namespace std;

const int N = 1e6+50;
const int mod = 1e9+7;
ll mpow(ll x, ll y){ll ans=1; while(y){if(y&1)ans=ans*x%mod;x=x*x%mod;y>>=1;}return ans;}
ll fct[N], rev[N];
ll C(ll n, ll r){return r<0||n<r?0:fct[n]*rev[r]%mod*rev[n-r]%mod;}

vector<int> v[N];
void sieve(){
	for(int x = 2; x < N; ++x){
		if(v[x].size()) continue;
		for(int z = x; z < N; z += x)
			v[z].push_back(0);
		for(ll y = x; y < N; y = y*x)
			for(int z = y; z < N; z += y)
				v[z].back()++;
	}
}

void init(){
	fct[0] = 1; Loop(i,1,N) fct[i] = fct[i-1]*i % mod;
	rev[N-1] = mpow(fct[N-1], mod-2);
	LoopR(i,0,N-1) rev[i] = rev[i+1]*(i+1) % mod;
	sieve();
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	init();
	int q; cin >> q;
	while(q--){
		ll n, r;
		cin >> r >> n;
		ll ans = 1;
		for(ll z : v[n]){
			ll cnt = (C(z+r-1,r-1) + C(z+r-1,r)*2) % mod;
			ans = ans*cnt % mod;
		}
		cout << ans << '\n';
	}
}