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

ll n, q;
vector<ll> v;
bool viv = false;
vector<map<int, multiset<char>>> mp;

ll cnt1, cnt2;

void add() {
	int v, u;
	string s;
	cin >> v >> u >> s;
	v--, u--;
	cnt1 += mp[u][v].size();
	cnt2 += mp[u][v].count(s[0]);
	mp[v][u].insert(s[0]);
}

void del() {
	int v, u;
	string s;
	cin >> v >> u;
	v--, u--;
	s += *(mp[v][u].begin());
	cnt1 -= mp[u][v].size();
	cnt2 -= mp[u][v].count(s[0]);
	if (viv) {
		cout << "del " << v << ' ' << u << ' ' << mp[v][u].size() << ":" << ' ' << s << ' ' << cnt1 << ' ' << cnt2 << endl;
		cout << (mp[v][u].find(s[0]) != mp[v][u].end()) << endl;
	}
	assert(mp[v][u].find(s[0]) != mp[v][u].end());
	mp[v][u].erase(mp[v][u].find(s[0]));
}

void qr() {
	int k;
	cin >> k;
	string ans;
	if (k & 1) {
		if (cnt1)
			ans = "YES\n";
		else
			ans = "NO\n";
	} else {
		if (cnt2)
			ans = "YES\n";
		else
			ans = "NO\n";
	}
	cout << ans;
}

void solve() {
	cin >> n >> q;
	if (viv)
		cout << n << ' ' << q << endl;
	mp.resize(n);
	while (q--) {
		string t;
		cin >> t;
		if (viv)
			cout << q << ' ' << t << endl;
		if (t[0] == '+')
			add();
		if (t[0] == '-')
			del();
		if (t[0] == '?')
			qr();
	}
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