#include <bits/stdc++.h>

#define pb push_back

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 1e6 + 10;
const ll INF = (ll) 92233720368545;
const ld EPS = (ld) 1e-8;

set<ll> s, t;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, k;
	cin >> n >> k;
	ll a, b;
	cin >> a >> b;
	s.insert(a);
	s.insert((k - a) % k);
	t.insert(b);
	t.insert((k - b) % k);
	ll mn = INF, mx = -1;
	ll d;
	for(auto x : s) for(auto y : t) for(int i = 0; i <= n; i++){
		if(x <= y) d = y - x;
		else d = y + k - x;
		ll l = i * k + d;
		if(l == 0) continue;
		ll d = ((n * k) / __gcd(l, n * k));
		mn = min(mn, d);
		mx = max(mx, d);
	}
	cout << mn << " " << mx;
	return 0;
}