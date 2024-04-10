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
vector<vector<ll>> v;
bool viv = false;


void solve() {
	cin >> n;
	v.clear();
	v.resize(n);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v[i].resize(k);
		for (auto &j : v[i])
			cin >> j, j--;
		sort(v[i].begin(), v[i].end());
	}
	set<ll> used;
	ll who = -1;
	for (int i = 0; i < n; i++) {
		ll now = 0;
		while (now < v[i].size() && used.find(v[i][now]) != used.end())
			now++;
		if (now == v[i].size()) {
			who = i;
		} else
			used.insert(v[i][now]);
	}
	if (who == -1) {
		cout << "OPTIMAL\n";
		return;
	}
	cout << "IMPROVE\n";
	cout << who + 1 << ' ';
	ll h = 0;
	while (used.find(h) != used.end())
		h++;
	cout << h + 1 << '\n';
	return;
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