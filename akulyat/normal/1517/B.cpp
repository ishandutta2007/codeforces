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

ll n, m;
vector<deque<int>> v;
bool viv = false;


void solve() {
	cin >> n >> m;
	v.assign(n, deque<int>(m, 0));
	for (auto &l : v) {
		for (auto &i : l) 
			cin >> i;
		sort(l.begin(), l.end());
	}

	vector<vector<int>> ans;
	ans.assign(n, vector<int>(m, -1));
	for (int j = 0; j < m; j++) {
		int pl = 0;
		for (int i = 0; i < n; i++) {
			if (v[pl].front() > v[i].front())
				pl = i;
		}
		for (int i = 0; i < n; i++) {
			if (i == pl) {
				ans[i][j] = v[i].front();
				v[i].pop_front();
			} else {
				ans[i][j] = v[i].back();
				v[i].pop_back();
			}
		}
	}
	for (auto &l : ans) {
		for (auto &i : l) 
			cout << i << ' ';
		cout << '\n';
	}

}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}