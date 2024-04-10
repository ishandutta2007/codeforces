/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define mp make_pair

using namespace std;

const int maxn = (int)1010;

char c[maxn][maxn];
int d[maxn][maxn];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char f[4] = {'D', 'L', 'R', 'U'};
int n, m;

const int inf = (int)1e9;

void bfs(int x, int y) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			d[i][j] = inf;
		}
	}

	queue <pii> q;

	q.push(mp(x, y));
	d[x][y] = 0;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int it = 0; it < 4; it++) {
			int nx = x + dx[it];
			int ny = y + dy[it];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && d[nx][ny] > d[x][y] + 1 && c[nx][ny] == '.') {
				d[nx][ny] = d[x][y] + 1;
				q.push(mp(nx, ny));
			}
		}
	}
}

char ans[(int)1e6 + 10];

int main() {
	int k;

	cin >> n >> m >> k;

	int x, y;

	for (int i = 0; i < n; i++) {
		scanf("%s", c[i]);

		for (int j = 0; j < m; j++) {
			if (c[i][j] == 'X') {
				x = i;
				y = j;
				c[i][j] = '.';
			}
		}
	}

	if (k & 1) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	bfs(x, y);

	int pos = 0;

	while (k != 0) {
		bool st = false;

		for (int it = 0; it < 4; it++) {
			int nx = x + dx[it];
			int ny = y + dy[it];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && c[nx][ny] == '.' && d[nx][ny] <= k - 1) {
				x = nx;
				y = ny;
				st = true;
				ans[pos++] = f[it];
				break;
			}
		}

		if (!st) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}

		k--;
	}

	printf("%s", ans);

	return 0;
}