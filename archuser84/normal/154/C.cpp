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

const int N = 1e6+10;
ll hsh[2*N];
int n, m;

unsigned long long Hsh(unsigned long long x){
	static ll RAND = time(0);
	x = x+RAND;
	x = x*0x6d705f0ba5936693ll;
	x = x^(x>>29);
	x = x*0x07baf821037cabe9ll;
	x = x^(x>>23);
	return x;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	while(m--){
		int v, u;
		cin >> v >> u;
		--v; --u;
		hsh[v] ^= Hsh(u);
		hsh[v+n] ^= Hsh(u);
		hsh[u] ^= Hsh(v);
		hsh[u+n] ^= Hsh(v);
	}
	Loop(i,0,n) hsh[i] ^= Hsh(i);
	n *= 2;
	sort(hsh, hsh+n);
	ll ans = 0;
	int i=0,j=0;
	while(i<n){
		while(j<n&&hsh[i]==hsh[j]) ++j;
		ll x = j-i;
		ans += x*(x-1)/2;
		i=j;
	}
	cout << ans << '\n';
}