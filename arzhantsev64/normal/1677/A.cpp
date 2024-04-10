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

int n;
vector<vector<int>> sa;

int get(int x, int y) {
	if ((x < 0) || (y < 0) || (x >= n) || (y >= n))
		return 0;
	return sa[x][y];
}

int get_rect(int x1, int y1, int x2, int y2) {
	if (x1 >= x2)
		return 0;
	if (y1 >= y2)
		return 0;
	return get(x2, y2) - get(x1, y2) - get(x2, y1) + get(x1, y1);
}

void solve() {
	cin >> n;

	vector<int> v(n);
	sa = vector<vector<int>> (n, vector<int> (n));
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		v[i]--;
		sa[i][v[i]] = 1;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			sa[i][j] = sa[i][j] + get(i - 1, j) + get(i, j - 1) - get(i - 1, j - 1);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			ans += get_rect(-1, -1, i - 1, v[j] - 1) * get_rect(j, -1, n - 1, v[i] - 1);
			// cout << i << ' ' << j << ' ' << ans << endl;
		}
	cout << ans << endl;
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