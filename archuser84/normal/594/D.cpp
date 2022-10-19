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

const int N = 200'010;
const int mod = 1e9 + 7;

ll mpow(ll x, ll y)
{
	ll ans = 1;
	while(y)
	{
		if(y&1) ans = ans*x % mod;
		x = x*x % mod;
		y >>= 1;
	}
	return ans;
} ll rev(ll x){return mpow(x,mod-2);}

int ans[N];
int a[N];
int n, q;
map<int,int> lst;

int fen[N];
void mul(int i, ll x)
{
	++i;
	while(i < N){
		fen[i] = fen[i]*x % mod;
		i += i&-i;
	}
}
ll get(int r)
{
	ll ans = 1;
	while(r > 0){
		ans = ans*fen[r] % mod;
		r -= r&-r;
	}
	return ans;
}
ll get(int l, int r){return get(r)*rev(get(l)) % mod;}

vector<pii> Q[N];

const int M = 1e6+10;
vector<int> divs[M];

void sieve()
{
	for(int x = 2; x < M; ++x)
	{
		if(divs[x].size()) continue;
		for(int y = x; y < M; y += x)
			divs[y].push_back(x);
	}
}

int main()
{
	sieve();
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	Loop(i,0,n) cin >> a[i];
	cin >> q;
	Loop(i,0,q)
	{
		int l, r;
		cin >> l >> r; --l;
		Q[r].push_back({l,i});
	}
	fill(fen,fen+N,1);
	Loop(r,1,n+1)
	{
		int x = a[r-1];
		for(int d : divs[x]){
			do {
				if(lst.count(d)) mul(lst[d], rev(d-1)*d % mod);
				mul(r-1, d-1);
				lst[d] = r-1;
				x /= d;
			} while(x%d == 0);
		}
		for(auto [l, i] : Q[r])
			ans[i] = get(l,r);
	}
	Loop(i,0,q) cout << ans[i] << '\n';
}