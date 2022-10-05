#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long     ll;
typedef long double   ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n, l;
vector<string> v;
bool viv = false;

ll delt(string s, string t) {
	ll res = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] != t[i])
			res++;
	return res;
}

bool good() {
	for (int i = 0; i < n; i++)
		if (delt(v[i], v.back()) > 1)
			return false;
	return true;
}

void solve() {
	cin >> n >> l;
	v.clear();
	v.resize(n, "");
	for (auto &s : v) {
		cin >> s;
		// cout << s << endl;
	}

	vector<set<ll>> vs(l);
	vector<vector<ll>> vv(l);
	for (int j = 0; j < l; j++) {
		for (int i = 0; i < n; i++)
			vs[j].insert(v[i][j]);
		vs[j].erase(v[0][j]);
	}
	for (int j = 0; j < l; j++) {
		for (auto c : vs[j])
			vv[j].push_back(c);
	}
	ll vars = 1;
	for (int j = 0; j < l; j++)
		vars *= (vv[j].size() + 1);
	if (viv) 
		for (auto vec : vv) {
			for (auto i : vec)
				cout << char(i) << ' ';
			cout << endl;
		}
	vars = min(vars, ml / 100);
	if (viv)
		cout << "have " << vars << endl;

	for (int i = 0; i < vars; i++) {
		ll mask = i;
		string str;
		for (int j = 0; j < l; j++) {
			ll ch = mask % (vv[j].size() + 1);
			if (ch == vv[j].size())
				str += v[0][j];
			else
				str += vv[j][ch];
			mask /= (vv[j].size() + 1);
		}
		if (viv)
			cout << "check " << str << endl;
		v.push_back(str);
		if (good()) {
			cout << str << '\n';
			return;
		}
		v.pop_back();
	}
	cout << -1 << '\n';
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}