///
///   You fell for it, fool!
///   Thunder Cross Split Attack!
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;

const int N = 1<<20;
ll mod;
int n, m; ll ex;
ll e[N], b[21], t[N];

ll mpow(ll x, ll y)
{
	ll ans = 1;
	while(y){
		if(y&1) ans = (__int128)ans*x % mod;
		x = (__int128)x*x % mod;
		y >>= 1;
	}
	return ans;
}

void hadamard(ll* b, ll* e)
{
	if(e-b == 1) return;
	ll* m = b+(e-b)/2;
	hadamard(b,m);
	hadamard(m,e);
	Loop(i,0,m-b){
		ll x1 = b[i]+m[i], x2 = b[i]+mod-m[i];
		x1 = x1>=mod?x1-mod:x1;
		x2 = x2>=mod?x2-mod:x2;
		b[i] = x1;
		m[i] = x2;
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> m >> ex >> mod; n = 1<<m;
	Loop(i,0,n) cin >> e[i], e[i] %= mod;
	Loop(i,0,m+1) cin >> b[i], b[i] %= mod;
	Loop(i,0,n) t[i] = b[__builtin_popcount(i)];
	mod <<= m;
	hadamard(t,t+n);
	hadamard(e,e+n);
	Loop(i,0,n) t[i] = (__int128)mpow(t[i],ex)*e[i] % mod;
	hadamard(t,t+n);
	Loop(i,0,n) cout << (t[i] >> m) << '\n';
}