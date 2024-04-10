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

ll n;
vector<ll> v;
bool viv = false;

vector<ll> get(vector<ll> ans) {
	vector<ll> res;
	set<ll> s;
	for (int i = 0; i < ans.size() + 1; i++) 
		s.insert(i);
	for (int i = 0; i < ans.size(); i++) {
		s.erase(ans[i]);
		res.push_back(*s.begin());
	}
	return res;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;


	vector<ll> ans(n, -1), used(n + 2, 0);

	for (int i = 1; i < n; i++)
		if (v[i - 1] != v[i])
			ans[i] = v[i - 1], used[v[i - 1]] = true;
	used[v.back()] = true;

	ll nxt = 0;
	for (int i = 0; i < n; i++)
		if (ans[i] == -1) {
			while (used[nxt])
				nxt++;
			ans[i] = nxt;
			used[nxt]++;
		}

	if (get(ans) == v) {
		for (auto i : ans)
			cout << i << ' ';
	} else {
		cout << -1;
	}
	if (!viv)
		return;
	cout << endl;
	for (auto i : ans)
		cout << i << ' ';
	cout << endl;
	for (auto i : get(ans))
		cout << i << ' ';
	cout << endl;
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