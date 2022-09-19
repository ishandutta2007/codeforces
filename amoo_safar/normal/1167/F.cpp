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

ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 5e5 + 10;
const ll INF = (ll) (LONG_LONG_MAX - 3ll) / 2ll;
const ld EPS = (ld) 1e-8;
//const ll P = 104107;

inline ll mul(ll a, ll b){
	return (a * b) % MOD;
}

ll a[MAXN], c[MAXN];
ll v[MAXN];
pll b[MAXN];
ll n;

vector<ll> to_mk;

inline int ok(int x){
	x %= MOD;
	x += MOD;
	x %= MOD;
	return x;
}

ll fen[MAXN];

void add(int x, int v){
	for( ; x < MAXN; x += x & (-x)) fen[x] = (fen[x] + v) % MOD;
}
ll get(int x){
	ll res = 0;
	for( ; x > 0; x -= x & (-x)) res += fen[x];
	return res % MOD;
}

ll solve(){
	memset(fen, 0, sizeof fen);
	memset(v, 0, sizeof v);
	
	for(int i = 1; i <= n; i++) v[a[i]] = i;
	ll res = 0;
	for(int i = 1; i <= n; i++){
		res += mul(mul( get(a[i] - 1), n - i + 1 ),c[i]);
		add(a[i], v[a[i]]);
		res %= MOD;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie();
	ll ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> b[i].F;
		b[i].S = i + 1;
		c[i + 1] = b[i].F;
		ans += mul(b[i].F , mul(i + 1, n - i));
		ans %= MOD;
	}
	
	sort(b, b + n);
	for(int i = 0; i < n; i++){
		a[b[i].S] = i + 1;
	}
	ans += solve();
	ans = ok(ans);
	reverse(a + 1, a + n + 1);
	reverse(c + 1, c + n + 1);
	ans += solve();
	cout << ok(ans);
	return 0;
}