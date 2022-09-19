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
	ll n;
	cin >> n;
	str s;
	cin >> s;
	ll s1 = 0, s2 = 0;
	ll ans = 0, f;
	for(int i = 0; i< n;i++){
		f = 1;
		if(s[i] == ')'){
			if(s1 < s2) s1++;
			else s2 ++, f = 0;
		} else {
			if(s1 < s2) s2 --, f = 0;
			else s1 --;
		}
		cout << f;
	}
	return 0;
}