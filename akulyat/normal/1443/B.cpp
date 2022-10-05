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

ll n, a, b;
string s;
bool viv = false;


void solve() {
	cin >> a >> b;
	cin >> s;
	n = s.size();
	vector<ll> cnt(n + 1, 0);

	for (int i = 0; i < n; i++)
		cnt[i] = (s[i] == '1');
	for (int i = 1; i < n; i++)
		if (cnt[i])
			cnt[i] += cnt[i - 1];

	vector<pll> seg;
	for (int i = 0; i < n; i++)
		if (cnt[i + 1] == 0 && cnt[i])
			seg.push_back({i - cnt[i] + 1, i});

	ll lans = a * seg.size();
	ll ans = lans;
	vector<ll> dif;
	for (int i = 1; i < seg.size(); i++)
		dif.push_back(seg[i].F - seg[i - 1].S - 1);
	sort(dif.begin(), dif.end());
	for (int i = 0; i < dif.size(); i++) {
		lans -= a;
		lans += dif[i] * b;
		ans = min(ans, lans);		
	}
	cout << ans << '\n';
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