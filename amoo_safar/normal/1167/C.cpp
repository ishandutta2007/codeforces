#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

ll MOD = (ll) 10883;
const ll MAXN = (ll) 5e5 + 10;
const ll INF = (ll) (LONG_LONG_MAX - 3ll) / 2ll;
const ld EPS = (ld) 1e-8;
//const ll P = 104107;

ll mul(ll a, ll b){
	return ((a % MOD) * (b % MOD)) % MOD;
}

ll pw(ll b, ll p){
	if(p == 0) return 1;
	if(p & 1) return mul(b, pw(b, p - 1));
	return pw(mul(b, b), p / 2);
}
ll inv(ll x){
	return pw(x, MOD - 2);
}

ll sz[MAXN];
ll p[MAXN];

ll pa(ll u){
	if(p[u] == u) return u;
	return p[u] = pa(p[u]);
}

void merge(ll u, ll v){
	//debug(u); debug(v);
	u = pa(u);
	v = pa(v);
	if(u == v) return ;
	p[u] = v;
	sz[v] += sz[u];
	return ;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie();
	for(int i = 0; i<MAXN; i++){
		p[i] =i;
		sz[i] = 1;
	}
	ll n, m;
	cin >> n >> m;
	ll k, l, v;
	for(int i = 0; i < m;i++){
		cin >> k;
		if(k) cin >> l;
		for(int j = 1; j < k; j++){
			cin >> v;
			merge(l, v);
		}
	}
	for(int i = 1; i<=n;i++){
		cout << sz[pa(i)] << " ";
	}
	return 0;
}