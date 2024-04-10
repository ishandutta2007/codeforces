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

const int N = 500'010;
int a[N]; bool b[N];
vector<int> divs[N];
int m[N];
int cnt[N];
int n, q;

void add(int x, int v){
	for(int d : divs[x])
		cnt[d] += v;
}

int Cnt(int x){
	int ans = 0;
	for(int d : divs[x])
		ans += cnt[d]*m[d];
	return ans;
}

void sieve(){
	fill(m+1,m+N,1);
	for(int x = 1; x < N; ++x){
		for(int y = x; y < N; y += x)
			divs[y].push_back(x);
		if(divs[x].size()==2){
			for(int y = x; y < N; y += x)
				m[y] *= -1;
			for(ll y = (ll)x*x; y < N; y += x*x)
				m[y] *= 0;
		}
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> q;
	Loop(i,0,n) cin >> a[i];
	sieve();
	ll ans = 0;
	while(q--){
		int i;
		cin >> i; --i;
		if(b[i]) add(a[i], -1), ans -= Cnt(a[i]);
		else ans += Cnt(a[i]), add(a[i], 1);
		b[i] = !b[i];
		cout << ans << '\n';
	}
}