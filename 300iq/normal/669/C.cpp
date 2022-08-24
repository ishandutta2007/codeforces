#include <bits/stdc++.h>

using namespace std;

const int MAXN = 111;
int a[MAXN][MAXN];
pair <int, int> was[MAXN][MAXN];
int cur[MAXN][MAXN];

int main() {
	#ifdef __linux__
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, m, q;
	cin >> n >> m;
	cin >> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			was[i][j] = make_pair(i, j);
		}
	}
	for (int i = 0; i < q; i++) {
		int t, r, c, x;
		cin >> t;
		if (t == 1) {
			cin >> r;
			r--;
			vector <pair <int, int> > p;
			for (int j = 0; j < m; j++) {
				p.push_back(was[r][j]);
			}
			rotate(p.begin(), p.begin() + 1, p.end());
			for (int j = 0; j < m; j++) {
				was[r][j] = p[j];
			}
		} else if (t == 2) {
			cin >> c;
			c--;
			vector <pair <int, int> > p;
			for (int j = 0; j < n; j++) {
				p.push_back(was[j][c]);
			}
			rotate(p.begin(), p.begin() + 1, p.end());
			for (int j = 0; j < n; j++) {
				was[j][c] = p[j];
			}
		} else {
			cin >> r >> c >> x;
			r--, c--;
			a[was[r][c].first][was[r][c].second] = x;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}