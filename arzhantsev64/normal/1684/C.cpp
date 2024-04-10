#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pt pair<int, int>
#define x first
#define y second

const int mod = 998244353;

int n, m;
vector<vector<int>> a;
vector<vector<int>> bads;

bool checkk(int i, int j) {
	if (j > 0 && a[i][j - 1] > a[i][j])
		return false;
	if (j + 1 < a[i].size() && a[i][j] > a[i][j + 1])
		return false;
	return true;
}

bool check(int i, int j1, int j2) {
	swap(a[i][j1], a[i][j2]);
	if (!checkk(i, j1)) { swap(a[i][j1], a[i][j2]); return false; }
	if (!checkk(i, j2)) { swap(a[i][j1], a[i][j2]); return false; }
	for (int j : bads[i])
		if (!checkk(i, j)) { swap(a[i][j1], a[i][j2]); return false; }
	swap(a[i][j1], a[i][j2]); return true;
}

void solve() {
	int n, m;
	cin >> n >> m;
	a = vector<vector<int>> (n, vector<int> (m));
	bads = vector<vector<int>> (n);
	vector<int> all_bads;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			if (a[i][j] > a[i][j + 1]) {
				bads[i].push_back(j);
				bads[i].push_back(j + 1);
				all_bads.push_back(j);
				all_bads.push_back(j + 1);
				if (bads[i].size() >= 5) {
					cout << -1 << '\n';
					return;
				}
			}
		}
	}

	if (all_bads.size() == 0) {
		cout << 1 << ' ' << 1 << '\n';
		return;
	}

	for (int j1 : {all_bads[0], all_bads[1]}) {
		for (int j2 = 0; j2 < m; ++j2) {
			bool flag = true;
			for (int i = 0; i < n; ++i) {
				if (!check(i, j1, j2)) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << j1 + 1 << ' ' << j2 + 1 << '\n';
				return;
			}
		}
	}
	cout << -1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    	 solve();

    return 0;
}