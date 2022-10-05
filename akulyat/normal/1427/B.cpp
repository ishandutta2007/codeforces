#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, k;
string s;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> k;
	cin >> s;
	vector<ll> pl;
	pl.push_back(-1);
	for (int i = 0; i < n; i++)
		if (s[i] == 'W')
			pl.push_back(i);
	pl.push_back(n);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			ans++;
			if (i && s[i - 1] == 'W') 
				ans++;
		}
	}
	if (pl.size() == 2) {
		if (k)
			ans += 2 * k - 1;
		cout << ans << '\n';
		return;
	}
	vector<ll> d;
	for (int i = 1; i < pl.size(); i++)
		if (pl[i] != pl[i - 1] + 1 || (i + 1 == pl.size()) || (i == 1))
			d.push_back(pl[i] - pl[i - 1] - 1);
	vector<ll> bad;
	bad.push_back(d.back());
	d.pop_back();
	reverse(d.begin(), d.end());
	bad.push_back(d.back());
	d.pop_back();
	reverse(d.begin(), d.end());
	sort(d.rbegin(), d.rend());
	sort(bad.rbegin(), bad.rend());
	if (viv) {
		for (auto i : d)
			cout << i << ' ';
		cout << endl;
		for (auto i : bad)
			cout << i << ' ';
		cout << endl;
	}
	while (k && d.size()) {
		ll can = min(k, d.back());
		d.back() -= can;
		k -= can;
		ans += 2 * can;
		if (d.back() == 0)
			ans++;
		d.pop_back();
	}
	while (k && bad.size()) {
		ll can = min(k, bad.back());
		bad.back() -= can;
		k -= can;
		ans += 2 * can;
		bad.pop_back();
	}
	cout << ans << '\n';
	if (viv)
		cout << endl;
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}