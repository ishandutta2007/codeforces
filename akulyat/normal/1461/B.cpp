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
vector<vector<int>> v;
bool viv = false;


void solve() {
	cin >> n >> m;
	v.clear();
	v.resize(n);
	for (auto &l : v) {
		string s;
		cin >> s;
		for (auto i : s)
			l.push_back(i == '*');
	}
	auto r = v, l = v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] && j)
				l[i][j] += l[i][j - 1];
			if (v[i][m - 1 - j] && j)
				r[i][m - 1 - j] += r[i][m - 1 - j + 1];
		}
	}
	int ans = 0;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int u = i; u < n; u++) {
				if (cnt != -1) {
					if (l[u][j] >= (u - i + 1) && r[u][j] >= (u - i + 1))
						cnt++;
					else
						ans += cnt, cnt = -1;
				}
			}
			if (cnt != -1)
				ans += cnt, cnt = -1;
		}
	}
	cout << ans << '\n';
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