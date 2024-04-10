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

ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 4e5 + 10;
const ll INF = (ll) (LONG_LONG_MAX - 3ll) / 2ll;
const ld EPS = (ld) 1e-8;
const ll P = 104107;

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

int num(char c){
	return c - 'a' + 1;
}

vector<ll> of[MAXN];
ll n, m, s;
ll a[MAXN];
ll b[MAXN];

bool check(ll x){
	for(int i = 0; i < MAXN; i++) b[i] = a[i];
	
	
	ll mn = x;
	ll can, buy = 0;
	for(int da = x; da > 0; da --){
		mn = min(mn, (ll) da);
		for(auto x : of[da]){
			
			can = min(b[x], mn);
			mn -= can;
			b[x] -= can;
			buy += can;
		}
	}
	ll rem = x - buy;
	if(rem >= 2ll * (s-buy)) return true;
	return false;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	s=0;
	for(int i = 1; i <= n;i++){
		cin >> a[i];
		s+= a[i];
	}
	ll d, t;
	for(int i = 0;i<m;i++){
		cin >> d >> t;
		of[d].pb(t);
	}
	
	ll l, r, mid;
	l = 0, r = MAXN;
	
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout << r;
	return 0;
}