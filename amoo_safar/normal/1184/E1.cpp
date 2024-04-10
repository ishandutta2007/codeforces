#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> edge;

const int Maxn = 2e5 + 10;
ll Inf = 1e18;
const int Log = 20;
const ll Sqrt = 1000000;
const ll Mod = 998244353LL;

ll mul(ll a, ll b){
	a%=Mod;
	b%=Mod;
	return (a * b) % Mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw)) if(p & j) res = mul(res, pw);
	return res;
}

ll p[Maxn];

ll par(ll u){
	if(p[u] == u) return u;
	return p[u] = par(p[u]);
}
void merge(ll u, ll v){
	u = par(u);
	v= par(v);
	if(u == v) return ;
	p[u] = v;
}


vector< pair<ll, pll> > V;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 0; i < Maxn; i++) p[i] = i;
	ll n, m;
	cin >> n >>m;	
	ll a, b, u, v, w;
	cin >> a >> b >> w;
	for(int i = 2; i <= m; i++){
		cin >> v >> u >> w;
		V.pb({w, {u, v}});	
	}
	sort(all(V));
	
	for(auto X : V){
		merge(X.S.F, X.S.S);
		if(par(a) == par(b)) return cout << X.F, 0;
	}
	cout << 1000000000LL;
	return 0;
}