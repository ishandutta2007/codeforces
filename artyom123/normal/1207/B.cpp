#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 1;

int a[100][100];
int b[100][100];

bool f(int x, int y) {
	return a[x][y] == 1 && a[x + 1][y] == 1 && a[x][y + 1] == 1 && a[x + 1][y + 1] == 1;
}

void done(int x, int y) {
	b[x][y] = 1;
	b[x][y + 1] = 1;
	b[x + 1][y] = 1;
	b[x + 1][y + 1] = 1;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> a[i][j];
    		b[i][j] = 0;
    	}
    }
    vector <pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (a[i][j] == b[i][j]) {
    			continue;
    		}
    		if (a[i][j] == 0 && b[i][j] == 1) {
    			cout << -1;
    			return 0;
    		}
    		if (i > 0 && j > 0 && f(i - 1, j - 1)) {
    			ans.pb({i - 1, j - 1});
    			done(i - 1, j - 1);
    			continue;
    		}
    		if (i < n - 1 && j > 0 && f(i, j - 1)) {
    			ans.pb({i, j - 1});
    			done(i, j - 1);
    			continue;
    		}
    		if (i > 0 && j < m - 1 && f(i - 1, j)) {
    			ans.pb({i - 1, j});
    			done(i - 1, j);
    			continue;
    		}
    		if (i < n - 1 && j < m - 1 && f(i, j)) {
    			ans.pb({i, j});
    			done(i, j);
    			continue;
    		}
    		cout << -1;
    		return 0;
    	}
    }
    cout << ans.size() << "\n";
    for (auto &c : ans) {
    	cout << c.fi + 1 << " " << c.se + 1 << "\n";
    }

    return 0;
}