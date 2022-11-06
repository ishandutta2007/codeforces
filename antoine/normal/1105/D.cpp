#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Cell {
	int x, y;
};

int n, m, P;
int a[10];
string grid[1009];
queue<Cell> q[10];
int ans[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> P;
	for (int i = 1; i <= P; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i)
		cin >> grid[i];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (grid[i][j] != '.' && grid[i][j] != '#')
				q[grid[i][j] - '0'].push( { i, j });

	for (int p = 1; any_of(q, q + 10, [](const queue<Cell> &q) {return !q.empty();}); ++p) {
		if (p > P)
			p = 1;
		for (int rnd = a[p]; rnd && !q[p].empty(); --rnd) {
			for (int rep = (int) q[p].size(); rep; --rep) {
				const int x = q[p].front().x;
				const int y = q[p].front().y;
				q[p].pop();
				for (int i = max(0, x - 1); i <= min(n - 1, x + 1); ++i)
					for (int j = max(0, y - 1); j <= min(m - 1, y + 1); ++j)
						if (abs(i - x) + abs(j - y) == 1 && grid[i][j] == '.') {
							q[p].push( { i, j });
							grid[i][j] = '0' + p;
						}
			}
		}
	}

	for (const string &s : grid)
		for (const char &c : s)
			if (c != '#' && c != '.')
				++ans[c - '0'];

	for (int p = 1; p <= P; ++p)
		cout << ans[p] << ' ';

	return 0;
}