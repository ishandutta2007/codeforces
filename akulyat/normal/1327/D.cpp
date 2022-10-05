#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")

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
vector<ll> p, c, d;
vector<vector<ll>> v, cmp;
ll ans;
bool viv = false;

void DFS(ll v) {	
	if (d[v] != -1)
		return;
	d[v] = cmp.size() - 1;
	cmp.back().push_back(v);
	DFS(p[v]);
}

bool good(vector<ll> &cc, ll len) {
	if (viv) {
		for (auto i : cc)
			cout << i << ' ';
		cout << " Check " << len << endl;
	}
	for (int i = 0; i < len; i++) {
		bool good = true;
		for (int j = i; j < cc.size(); j += len)
			if (c[cc[j]] != c[cc[i]])
				good = false;

		if (good) {
			if (viv) {
				for (auto i : cc)
					cout << i << ' ';
				cout << " Good " << len << endl;
			}
			return true;
		}
	}
	return false;
}

void work(vector<ll> &c) {
	ll n = c.size();
	vector<ll> chk;
	for (int i = 1; i * i <= n; i++)
		if (n % i == 0)
			chk.push_back(i),
			chk.push_back(n / i);
	for (auto i : chk)
		if (good(c, i))
			ans = min(ans, i);
}

void solve() {
	cin >> n;
	p.clear();
	c.clear();
	p.resize(n);
	c.resize(n);
	for (auto &i : p)
		cin >> i, i--;
	for (auto &i : c)
		cin >> i, i--;

	d.clear();
	d.resize(n, -1);
	cmp.clear();
	for (int i = 0; i < n; i++)
		if (d[i] == -1) 
			cmp.push_back({}), DFS(i);
	ans = n;
	for (auto v : cmp)
		work(v);
	cout << ans << '\n';
}


int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}