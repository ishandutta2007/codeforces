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

const ll K = 10;
const ll SZ = (1 << (K + 2));
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n;
vector<string> v;
bool viv = false;
vector<vector<bitset<SZ>>> bb;

vector<bitset<SZ>> work(string s) {
	vector<bitset<SZ>> have;
	for (int len = 1; len < K; len++) {
		bitset<SZ> res;
		if (len <= s.size()) {
			ll val = 0;
			for (int i = 0; i < len; i++)
				val <<= 1, val += (s[i] == '1');
			res[val] = true;
			for (int r = len; r < s.size(); r++) {
				val <<= 1;
				val &= ((1 << len) - 1);
				val += s[r] == '1';
				res[val] = true;
			}
		}
		have.push_back(res);
	}
	return have;
}

ll get(vector<bitset<SZ>> b) {
	for (int st = 0; st < b.size(); st++) {
		for (int i = 0; i < (1 << (st + 1)); i++)
			if (!b[st][i])
				return st;
	}
	return b.size();
}

vector<bitset<SZ>> got(vector<bitset<SZ>> a, vector<bitset<SZ>> b) {
	vector<bitset<SZ>> res;
	for (int i = 0; i < a.size(); i++) {
		res.push_back(a[i] | b[i]);
	}
	return res;
}

string norm(string s) {
	string res;
	for (int i = 0; i < s.size(); i++) {
		if (min(i, (int)s.size() - 1 - i) <= 2 * K + 1)
			res += s[i];
	}
	return res;
}

string mid(string a, string b) {
	while (b.size() > K)
		b.pop_back();
	reverse(a.begin(), a.end());
	while (a.size() > K)
		a.pop_back();
	reverse(a.begin(), a.end());
	string res = a + b;
	return res;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &l : v)
		cin >> l;
	for (auto l : v)
		bb.push_back(work(l));

	ll q;
	cin >> q;
	vector<ll> ans;
	while (q--) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		auto sa = v[a];
		sa = norm(sa);
		auto sb = v[b];
		sb = norm(sb);
		auto ch = mid(v[a], v[b]);
		v.push_back(sa + sb);
		bb.push_back(got(got(bb[a], bb[b]), work(ch)));
		ans.push_back(get(bb.back()));
	}
	for (auto i : ans)
		cout << i << '\n';
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}