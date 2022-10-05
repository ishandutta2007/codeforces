#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
ifstream in;
ofstream out;
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;;
const long long inf = ml * ml * ml + 7;
 
 
ll n, t, a, b, k;
vector<ll> m, p;
unordered_map<ll, ll> pl;
bool viv = false;

void solve() {
	cin >> n >> k;
	m.clear();
	m.resize(n);
	for (auto &i : m)
		cin >> i, i--;
	p.clear();
	p.resize(k);
	for (auto &i : p)
		cin >> i, i--;
	pl.clear();
	for (ll i = 0; i < n; i++)
		pl[m[i]] = i;
	for (auto &i : p)
		i = pl[i];

	ll mx = -1;
	ll ans = 0;
	ll cnt = 0;
	// for (auto i : p)
	// 	cout << i << ' ';
	// cout << endl;
	for (auto i : p) {
		if (mx > i)
			ans++;
		else {
			ans += 2 * (i - cnt) + 1;
//			cout << "add " << (i - cnt) << endl;
		}
		mx = max(mx, i);
		cnt++;
	}
	cout << ans << '\n';
}


int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    	solve();


    return 0;
}