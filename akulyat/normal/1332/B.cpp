#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

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
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 


ll n;
bool viv = false;
vector<ll> v;
vector<ll> p;

void prepare() {
	vector<ll> g(1024, true);
	g[0] = g[1] = false;
	for (int i = 2; i < g.size(); i++)
		if (g[i]) {
			for (int j = i; j < g.size(); j += i)
				g[j] = false;
			p.push_back(i);
		}
}

void solve() {
	cin >> n;
	v.clear();
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	p.resize(11);
	vector<ll> ans;
	ans.resize(n, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p.size(); j++)
			if (!(v[i] % p[j]))
				ans[i] = j;
	}
	set<ll> s;
	map<ll, ll> mp;
	for (auto i : ans)
		s.insert(i);
	int cnt = 0;
	for (auto i : s)
		mp[i] = cnt, cnt++;
	for (auto &i : ans)
		i = mp[i];

	cout << (*max_element(ans.begin(), ans.end()) + 1) << '\n';
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << '\n';
}


int main() {
	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	prepare();
	while (t--)
		solve();

	return 0;
}