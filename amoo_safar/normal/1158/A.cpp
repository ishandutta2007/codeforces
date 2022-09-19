#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) //cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) LONG_LONG_MAX / 100;
const ld EPS = (ld) 1e-8;
const ll P = 104107;

ll mul(ll a, ll b){
	return (a * b) % MOD;
}

ll pw(ll b, ll p){
	if(p == 0) return 1;
	if(p & 1) return mul(b, pw(b, p - 1));
	return pw(mul(b, b), p / 2);
}
ll inv(ll x){
	return pw(x, MOD - 2);
}

ll n, m;
ll a[MAXN];
ll b[MAXN];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n>>m;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a,a + n);
	//reverse(a,a + n);
	for(int i = 0; i < m;i++) cin >> b[i];
	sort(b, b + m);
	if(b[0] < a[n - 1]) return cout << -1, 0;
	if(b[0] == a[n - 1]){
		ll ans = 0;
		for(int i = 0; i < n-1; i++) ans += (m * a[i]);
		for(int j = 0; j < m; j++) ans += (b[j]);
		return cout << ans, 0;
	}
	if(n == 1){
		return cout << -1, 0;
	}
	ll ans = 0;
	for(int i = 0; i < n-1; i++) ans += (m * a[i]);
	ans -= a[n - 2];
	ans += a[n - 1];
	for(int j = 0; j < m; j++) ans += (b[j]);
	return cout << ans, 0;
	return 0;
}


/*
fuck hashal
*/