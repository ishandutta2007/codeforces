#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <unordered_set>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = 110;
bool eq[maxn][maxn][maxn];
int col[maxn][maxn];
vector<int> cl[maxn][maxn];

char s[maxn];
bool used[maxn];
int us[maxn];

vector<pii> ed;
vector<int> e[maxn];

int n;

bool check(int a, int b) {
	for (int i = 0; i < n; i++) {
		if (col[i][a] == col[i][b]) {
			return false;
		}
	}

	for (int i = 0; i < n; i++) {
		us[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		if (i == a || i == b || used[i]) {
			continue;
		}

		int ca = col[a][i];
		int cb = col[b][i];

		if (us[ca] != -1) {
			if (us[ca] != cb) {
				return false;
			}
			continue;
		}

		us[ca] = cb;

		int pa = 0;
		int pb = 0;

		while (true) {
			while (pa < (int)cl[a][ca].size() && (used[cl[a][ca][pa]] || cl[a][ca][pa] == a || cl[a][ca][pa] == b)) {
				pa++;
			}

			while (pb < (int)cl[b][cb].size() && (used[cl[b][cb][pb]] || cl[b][cb][pb] == a || cl[b][cb][pb] == b)) {
				pb++;
			}

			if (pa == (int)cl[a][ca].size() && pb != (int)cl[b][cb].size()) {
				return false;
			}

			if (pa != (int)cl[a][ca].size() && pb == (int)cl[b][cb].size()) {
				return false;
			}

			if (pa == (int)cl[a][ca].size()) {
				break;
			}

			if (cl[a][ca][pa] != cl[b][cb][pb]) {
				return false;
			}
			pa++;
			pb++;
		}
	}

	return true;
}

void solve() {
	int total = 0;
	for (int i = 0; i < n; i++) {
		if (used[i]) {
			continue;
		}

		total++;

		for (int j = 0; j < n; j++) {
			if (used[j] || i == j) {
				continue;
			}

			int c = col[i][j];

			int cnt = 0;
			for (auto& v : cl[i][c]) {
				if (!used[v]) {
					cnt++;
				}
			}
			if (cnt == 1) {
				cnt = 0;
				c = col[j][i];
				for (auto& v : cl[j][c]) {
					if (!used[v]) {
						cnt++;
					}
				}
				if (cnt == 1) {
					continue;
				}
				if (check(i, j)) {
					ed.push_back(mp(i, j));
					e[i].push_back(j);
					e[j].push_back(i);
					used[i] = true;
					solve();
					return;
				}
			}
		}
	}

	if (total == 2) {
		ed.push_back({ -1, -1 });
		for (int i = 0; i < n; i++) {
			if (used[i]) {
				continue;
			}

			if (ed.back().first == -1) {
				ed.back().first = i;
			}
			else {
				ed.back().second = i;
			}
		}
		e[ed.back().first].push_back(ed.back().second);
		e[ed.back().second].push_back(ed.back().first);
	}
}

int dst[maxn];

void dfs(int v, int p = -1, int d = 0) {
	dst[v] = d;
	for (int u : e[v]) {
		if (u == p) {
			continue;
		}

		dfs(u, v, d + 1);
	}
}

int main() {
	int tt;
	cin >> tt;

	while (tt--) {
		ed.clear();
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			used[i] = false;
			e[i].clear();
			for (int j = 0; j < n; j++) {
				col[i][j] = -1;
				cl[i][j].clear();
			}
		}

		bool good = true;

		for (int i = 1; i <= n - 1; i++) {
			for (int j = 1; j <= n - i; j++) {
				scanf("%s", s);

				for (int k = 1; k <= n; k++) {
					int a = i - 1;
					int b = i + j - 1;
					int c = k - 1;
					if (s[k - 1] == '1') {
						eq[c][a][b] = 1;
						eq[c][b][a] = 1;
						if (c == a || c == b) {
							good = false;
						}
					}
					else {
						eq[c][a][b] = 0;
						eq[c][b][a] = 0;
					}
				}
			}
		}

		if (!good) {
			printf("No\n");
			continue;
		}

		for (int i = 0; i < n; i++) {
			int cur = 0;
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}

				if (col[i][j] != -1) {
					continue;
				}

				col[i][j] = cur;
				cl[i][cur].push_back(j);
				for (int k = j + 1; k < n; k++) {
					if (i == k) {
						continue;
					}

					if (eq[i][j][k]) {
						col[i][k] = cur;
						cl[i][cur].push_back(k);
					}
				}

				cur++;
			}
		}

		solve();
		if ((int)ed.size() == n - 1) {
			bool ok = true;
			for (int i = 0; i < n; i++) {
				dfs(i);

				for (int j = 0; j < n; j++) {
					if (j == i) {
						continue;
					}
					for (int k = 0; k < n; k++) {
						if (k == i || k == j) {
							continue;
						}

						if (eq[i][j][k] && dst[j] != dst[k]) {
							ok = false;
							break;
						}

						if (!eq[i][j][k] && dst[j] == dst[k]) {
							ok = false;
							break;
						}
					}
				}
			}
			if (ok) {
				printf("Yes\n");
				for (auto[x, y] : ed) {
					printf("%d %d\n", x + 1, y + 1);
				}
			}
			else {
				printf("No\n");
			}
		}
		else {
			printf("No\n");
		}
	}
}