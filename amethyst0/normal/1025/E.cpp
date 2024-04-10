#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>
#include <ctime>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair

const int maxn = 55;

int f[maxn][maxn];
int c[maxn][maxn];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool used[maxn][maxn];

int n;

vector <pii> bfs(int g) {
	queue <pii> q;
	q.push(mp(g, n - 1));
	memset(used, 0, sizeof used);
	used[g][n - 1] = true;
	vector <pii> v;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int it = 0; it < 4; it++) {
			int nx = x + dx[it];
			int ny = y + dy[it];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (f[nx][ny] == 0) {
					if (!used[nx][ny]) {
						used[nx][ny] = true;
						q.push(mp(nx, ny));
					}
				}
				else {
					if (!(ny == n - 1 && nx < g)) {
						v.push_back(mp(nx, ny));
					}
				}
			}
		}
	}

	return v;
}

vector <pair <pii, pii> > ans;
pii lnk[maxn][maxn];

void bfs(int x1, int y1, int x2, int y2) {
	queue <pii> q;

	q.push(mp(x1, y1));
	memset(used, 0, sizeof used);
	used[x1][y1] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int it = 0; it < 4; it++) {
			int nx = x + dx[it];
			int ny = y + dy[it];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (f[nx][ny] != 0) {
					continue;
				}

				if (!used[nx][ny]) {
					used[nx][ny] = true;
					lnk[nx][ny] = mp(x, y);
					q.push(mp(nx, ny));
				}
			}
		}
	}

	if (!used[x2][y2]) {
		throw 1;
	}

	vector <pii> h;

	while (!(x2 == x1 && y2 == y1)) {
		h.push_back(mp(x2, y2));
		int x = lnk[x2][y2].first;
		int y = lnk[x2][y2].second;
		x2 = x;
		y2 = y;
	}

	h.push_back(mp(x1, y1));

	for (int i = (int)h.size() - 1; i >= 1; i--) {
		ans.push_back(mp(h[i], h[i - 1]));
		swap(f[h[i].first][h[i].second], f[h[i - 1].first][h[i - 1].second]);
	}
}

int main() {
	int m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		x--;
		y--;
		f[x][y] = i;
	}

	for (int i = 1; i <= m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		x--;
		y--;
		c[x][y] = i;
	}

	for (int i = 0; i < m; i++) {
		if (f[i][n - 1] != 0) {
			continue;
		}

		vector <pii> v = bfs(i);

		if (v.empty()) {
			throw 1;
		}

		int ps = rand() % (int)v.size();
		bfs(v[ps].first, v[ps].second, i, n - 1);
	}
	
	for (int i = 0; i < n; i++) {
		int ps = 0;

		for (int j = 0; j < n; j++) {
			if (c[i][j] != 0) {
				for (int k = 0; k < n; k++) {
					if (f[k][n - 1] == c[i][j]) {
						bfs(k, n - 1, i, ps);
						ps++;
						break;
					}
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (f[i][j] != 0) {
				for (int k = 0; k < n; k++) {
					if (c[i][k] == f[i][j]) {
						bfs(i, j, i, k);
						break;
					}
				}
			}
		}
	}

	if (ans.size() > 10800) {
		throw 1;
	}

	cout << ans.size() << endl;

	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i].first.first + 1 << ' ' << ans[i].first.second + 1 << ' ' << ans[i].second.first + 1 << ' ' << ans[i].second.second + 1 << endl;
	}

	//system("pause");
}