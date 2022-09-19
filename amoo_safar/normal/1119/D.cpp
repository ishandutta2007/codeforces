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
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 3e18;
const ld EPS = (ld) 1e-8;
const ll LOG = 20;

ll a[MAXN], d[MAXN], p[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//debug(INF);
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	a[n] = INF;
	for(int i = 0; i < n; i++) d[i] = a[i + 1] - a[i];
	sort(d, d + n);
	p[0] = 0;
	for(int i = 0; i< n; i++) p[i + 1] = p[i] + d[i];
	ll q;
	cin >> q;
	ll l, r;
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		ll le = r - l + 1;
		ll ind = lower_bound(d, d + n, le) - d;
		//debug(ind);
		ll ans = p[ind];
		ans += (le * (n - ind));
		cout << ans << " ";
	}
	return 0;
}