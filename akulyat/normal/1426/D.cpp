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

ll n;
vector<ll> v;
bool viv = false;

	
void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	vector<ll> p;
	p.push_back(0);
	for (auto i : v)	
		p.push_back(p.back() + i);
	
	map<ll, vector<ll>> val;
	for (int i = 0; i < p.size(); i++)
		val[p[i]].push_back(i);

	vector<pll> seg;
	for (auto pr : val) {
		for (int i = 1; i < pr.S.size(); i++) 
			seg.push_back({pr.S[i - 1] + 1, pr.S[i] - 1});
	}
	sort(seg.begin(), seg.end());
	// for (auto p : seg)
	// 	cout << p.F << ' ' << p.S << endl;
	ll last = -1;
	ll ans = 0;
	for (int i = 0; i < seg.size(); i++) {
		if (last < seg[i].F) {
			ans++;
			last = seg[i].S;
		}
		last = min(last, seg[i].S);
	}
	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}