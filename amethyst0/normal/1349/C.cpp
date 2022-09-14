#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>
#include <unordered_map>
#include <array>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int

const int maxn = 1001;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
char c[maxn][maxn];

int n, m;

queue <int> q;
int wh[maxn][maxn];

#define tm aklsdhajksdjka

int tm = 0;

char ans[maxn * maxn];

int main() {
	int t;

	cin >> n >> m >> t;

	for (int i = 0; i < n; i++) {
		scanf("%s", c[i]);
	}

	memset(wh, -1, sizeof wh);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int it = 0; it < 4; it++) {
				int x = i + dx[it];
				int y = j + dy[it];

				if (0 <= x && x < n && 0 <= y && y < m && c[i][j] == c[x][y]) {
					wh[i][j] = 0;
					q.push(i * m + j);
				}
			}
		}
	}

	while (!q.empty()) {
		int x = q.front() / m;
		int y = q.front() % m;
		q.pop();

		for (int it = 0; it < 4; it++) {
			int nx = x + dx[it];
			int ny = y + dy[it];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && wh[nx][ny] == -1) {
				wh[nx][ny] = wh[x][y] + 1;
				q.push(nx * m + ny);
			}
		}
	}

	while (t--) {
		int x, y;
		ll t;

		scanf("%d %d %lld", &x, &y, &t);
		x--;
		y--;

		if (t < wh[x][y] || wh[x][y] == -1) {
			printf("%c\n", c[x][y]);
		}
		else {
			t -= wh[x][y];

			if (t % 2 == 0) {
				printf("%c\n", c[x][y]);
			}
			else {
				printf("%c\n", (c[x][y] == '1' ? '0' : '1'));
			}
		}
	}
}