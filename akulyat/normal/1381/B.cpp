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

ll n;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n;
	n *= 2;
	v.clear();
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;

	vector<pll> blocks;
	for (int i = 0; i < n; i++)
		blocks.push_back({i, i});
	for (int i = 0; i < n; i++) {
		vector<pll> nblocks;
		nblocks.push_back(blocks[0]);
		for (int j = 1; j < blocks.size(); j++) {
			if (v[nblocks.back().F] > v[blocks[j].F])
				nblocks.back().S = blocks[j].S;
			else
				nblocks.push_back(blocks[j]);
		}
		blocks = nblocks;
	}

	vector<ll> sz;
	for (auto p : blocks)
		sz.push_back(p.S - p.F + 1);

	if (viv) {
		for (auto p : blocks)
			cout << "[" << p.F << ' ' << p.S << "], ";
		cout << endl;
		for (auto i : sz)
			cout << i << ' ';
	}


	vector<bool> can(2 * n + 10, false);
	can[0] = true;
	for (auto len : sz)
		for (int j = can.size() - 1; j >= 0; j--)
			if (can[j])
				can[j + len] = true;

	if (viv) {
		for (int i = 0; i < n + 1; i++)
			cout << can[i] << ' ';
	}

	if (can[n / 2])
		cout << "YES\n";
	else
		cout << "NO\n";

	if (viv) {
		cout << endl;
	}
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