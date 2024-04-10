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

const int maxn = 1010;
char c[maxn][maxn];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, m;

bool used[maxn][maxn];

void dfs(int x, int y) {
	used[x][y] = true;

	for (int it = 0; it < 4; it++) {
		int nx = x + dx[it];
		int ny = y + dy[it];

		if (0 <= nx && nx < n && 0 <= ny && ny < m && !used[nx][ny] && c[nx][ny] == '#') {
			dfs(nx, ny);
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		scanf("%s", c[i]);
	}

	int ans = 0;

	bool isa = false, isb = false;

	for (int i = 0; i < n; i++) {
		bool fir = true;

		for (int j = 0; j < m; j++) {
			if (c[i][j] == '#') {
				if (fir) {
					fir = false;
					continue;
				}
				else if (c[i][j - 1] != '#') {
					cout << -1 << '\n';
					return 0;
				}
			}
		}

		if (fir) {
			isa = true;
		}
	}

	for (int j = 0; j < m; j++) {
		bool fir = true;

		for (int i = 0; i < n; i++) {
			if (c[i][j] == '#') {
				if (fir) {
					fir = false;
					continue;
				}
				else if (c[i - 1][j] != '#') {
					cout << -1 << '\n';
					return 0;
				}
			}
		}

		if (fir) {
			isb = true;
		}
	}

	if (isa && !isb) {
		cout << -1 << '\n';
		return 0;
	}

	if (isb && !isa) {
		cout << -1 << '\n';
		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] == '#' && !used[i][j]) {
				dfs(i, j);
				ans++;
			}
		}
	}

	cout << ans << '\n';
}