#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld long double

using namespace std;

const int maxn = 2010;
char f[maxn][maxn];

pii dst[maxn][maxn];

int dx[4] = { -1, 1, 0 ,0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	int n, m;

	cin >> n >> m;

	int r, c, x, y;

	cin >> r >> c >> x >> y;

	for (int i = 0; i < n; i++) {
		scanf( "%s", f[i]);
	}

	set <pair <pii, pii> > q;

	q.insert(mp(mp(0, 0), mp(r, c)));

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dst[i][j] = mp((int)1e9 + 1, (int)1e9 + 1);
		}
	}

	dst[r][c] = mp(0, 0);

	while (!q.empty()) {
		int cx = q.begin()->second.first;
		int cy = q.begin()->second.second;
		q.erase(q.begin());

		if (dst[cx][cy].first <= x && dst[cx][cy].second <= y) {
			ans++;
		}

		for (int it = 0; it < 4; it++) {
			int nx = cx + dx[it];
			int ny = cy + dy[it];

			if (1 <= nx && nx <= n && 1 <= ny && ny <= m && f[nx - 1][ny - 1] != '*') {
				pii curd = dst[cx][cy];

				if (it == 2) {
					curd.first++;
				}
				else if (it == 3) {
					curd.second++;
				}

				if (curd < dst[nx][ny]) {
					q.erase(mp(dst[nx][ny], mp(nx, ny)));
					dst[nx][ny] = curd;
					q.insert(mp(dst[nx][ny], mp(nx, ny)));
				}
			}
		}
	}

	cout << ans << endl;

	//system("pause");
}