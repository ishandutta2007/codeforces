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

ll n, m, q, cc;
bool viv = false;
vector<vector<bool>> f;
vector<int> col, cnt;

void DFS(int x, int y, int c) {
	// cout << "in " << x << ' ' << y << endl;
	cc++;
	col[x * m + y] = c;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++) 
			if ((i == 0) ^ (j == 0)) {
				if (x + i >= 0 && y + j >= 0 && x + i < n && y + j < m && f[x][y] == f[x + i][y + j] && col[(x + i) * m + y + j] == -1)
					DFS(x + i, y + j, c);
			}
}

vector<ll> BFS(vector<int> &st) {
	vector<ll> res(n * m, inf);
	for (auto v : st)
		res[v] = 0;
	int s = 0;
	while (s < st.size()) {
		int v = st[s];
		s++;
		int x = v / m;
		int y = v % m;
		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++) 
				if ((i == 0) ^ (j == 0)) {
					int nx = x + i, ny = y + j;
					if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
						int u = nx * m + ny;
						if (res[u] > res[v] + 1) {
							res[u] = res[v] + 1;
							st.push_back(u);
						}
					}
				}		
	}
	return res;
}

void solve() {
	cin >> n >> m >> q;
	f.resize(n);
	for (auto &l : f) {
		string s;
		cin >> s;
		for (auto i : s)
			l.push_back(i == '1');
	}

	col.resize(n * m, -1);
	int tc = 0;
	for (int i = 0; i < n ; i++)
		for (int j = 0; j < m; j++)
			if (col[i * m + j] == -1) {
				DFS(i, j, tc), tc++;
				cnt.push_back(cc);
				cc = 0;
			}
	vector<int> st;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (cnt[col[i * m + j]] > 1)
				st.push_back(i * m + j);
	auto res = BFS(st);			

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << res[i * m + j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	while (q--) {
		ll x, y, p;
		cin >> x >> y >> p;
		x--, y--;
		if (p < res[x * m + y])
			cout << f[x][y] << '\n';
		else {
			cout << (f[x][y] ^ ((p - res[x * m + y]) & 1)) << '\n';
		}
	}



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