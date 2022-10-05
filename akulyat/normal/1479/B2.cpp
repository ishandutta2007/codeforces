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


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	vector<ll> v2;
	for (int i = 0; i < n; i++)
		if (i == 0 || (v[i] != v[i - 1]))
			v2.push_back(v[i]);
	v = v2;
	n = v.size();

	map<int, deque<int>> mp;
	for (int i = 0; i < n; i++) {
		mp[v[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		mp[v[i]].push_back(n);
	}
	mp[-1].push_back(n);
	mp[-1].push_back(n);
	mp[-1].push_back(n);

	int a = -1, b = -1, ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] != a && v[i] != b) {
			if (mp[a].front() > mp[b].front()) {
				a = v[i];
				ans++;
			} else {
				b = v[i];
				ans++;				
			}
		}
		mp[v[i]].pop_front();
	}
	cout << ans << '\n';
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