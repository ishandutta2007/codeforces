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
map<int, vector<ll>> mp;

vector<ll> ask(int v) {
	if (mp.count(v))
		return mp[v];
	cout << "? " << v + 1 << endl;
	vector<ll> res(n);
	for (auto &i : res)
		cin >> i;

	return mp[v] = res;
}

vector<ll> start() {
	auto d = ask(0);
	int c0 = 0, c1 = 0;
	for (int i = 0; i < n; i++) {
		c0 += ((d[i] & 1) == 0);
		c1 += ((d[i] & 1) == 1);
	}
	int who = 0;
	if (c1 < c0)
		who = 1;
	vector<ll> asked;
	for (int i = 0; i < n; i++) 
		if ((d[i] & 1) == who)
			asked.push_back(i);
	return asked;
}

void work(vector<ll> asked) {
	set<pii> ans;
	for (auto v : asked) {
		auto d = ask(v);
		for (int i = 0; i < n; i++)
			if (d[i] == 1) {
				int a = v;
				int b = i;
				if (a > b)
					swap(a, b);
				ans.insert({a, b});
			}
	}
	cout << "!" << endl;
	for (auto p : ans)
		cout << p.F + 1 << " " << p.S + 1 << endl;
}

void solve() {
	cin >> n;
	work(start());
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