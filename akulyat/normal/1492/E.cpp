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
vector<int> ans;
vector<vector<bool>> b;
bool viv = false;

void NO() {
	cout << "No\n";
	exit(0);
}

void YES(vector<int> ans) {
	cout << "Yes\n";
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
	exit(0);
}

void work(int x, int y, vector<int> ans, vector<vector<bool>> b, int ch) {
	if (viv)
		cout << "work(" << x << ' ' << y << ' ' << ch << ")" << endl;
	if (x != -1) {
		ans[y] = v[x][y];
		for (int i = 0; i < n; i++)
			b[i][y] = (v[i][y] != ans[y]);
	}
	for (int i = 0; i < n; i++) {
		vector<int> bad;
		for (int j = 0; j < m; j++) {
			if (b[i][j])
				bad.push_back(j);
		}
		if (viv) {
			cout << "at " << i << ": " << bad.size() << endl;
		}
		if ((int)bad.size() - ch > 2) {
			if (viv)
				cout << "\t\tBAD\n";
			return;
		}
		if (bad.size() > 2) {
			if (viv) {
				cout << "\tat " << i << ": ";
				for (auto j : bad)
					cout << j << ' ';
				cout << endl;
			}
			for (auto j : bad) {
				work(i, j, ans, b, ch - 1);
			}
			if (viv)
				cout << "\t\tBAD\n";
			return;
		}
	}
	YES(ans);
}

void solve() {
	cin >> n >> m;
	v.resize(n, vector<int>(m, 0));
	for (auto &l : v)
		for (auto &i : l)
			cin >> i;
	b.resize(n, vector<bool>(m, 0));
	ans = v[0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[i][j] = v[i][j] != ans[j];
		}
	}
	work(-1, -1, ans, b, 2);
	NO();
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