//#pragma comment(linker, "/STACK:1000000000")
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
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double

using namespace std;

const int maxn = (int)5e5 + 10;
vector <int> ed[maxn];
int deg[maxn];
int used[maxn];
int posit = 0;
int h[maxn];
int pr[maxn];

vector <int> c;

int n;

bool dfs(int v, int p = -1, int hh = 0) {
	if (used[v] != -1) {
		return false;
	}

	used[v] = posit;
	h[v] = hh;
	pr[v] = p;

	int to = -1;

	for (int u : ed[v]) {
		if (deg[u] % 3 != 2 || u == p) {
			continue;
		}

		if (used[u] == posit && h[v] - h[u] != n - 1 && h[v] > h[u]) {
			if (to == -1 || h[to] < h[u]) {
				to = u;
			}
		}
	}

	if (to != -1) {
		int x = v;

		while (x != to) {
			c.push_back(x);
			x = pr[x];
		}

		c.push_back(x);
		return true;
	}

	for (int u : ed[v]) {
		if (deg[u] % 3 != 2 || u == p) {
			continue;
		}

		if (dfs(u, v, hh + 1)) {
			return true;
		}
	}

	return false;
}

vector <int> num[maxn];
int dst[maxn];
int lnk[maxn];
bool in[maxn];

void bfs(int v) {
	c.clear();
	memset(dst, -1, (n + 1) * sizeof(int));
	queue <int> q;
	q.push(v);
	dst[v] = 0;
	lnk[v] = -1;
	memset(in, 0, (n + 1) * sizeof(bool));

	for (int u : ed[v]) {
		in[u] = true;
	}

	int st = v;

	while (!q.empty()) {
		v = q.front();
		q.pop();
		int h = v;

		if (deg[v] % 3 == 1 && dst[v] != 0) {
			memset(used, 0, sizeof(int) * (n + 1));
			int ans = n;
			while (!in[v]) {
				ans--;
				used[v] = 1;
				v = lnk[v];
			}

			used[v] = 1;
			ans--;
			used[st] = 1;
			ans--;

			cout << "Yes\n";
			cout << ans << '\n';
			for (int i = 1; i <= n; i++) {
				if (used[i] == 0) {
					cout << i << ' ';
				}
				else {
					if (i == h || i == st) {
						if (deg[i] % 3 != 1) {
							throw 1;
						}
						int cnt = 0;

						for (int u : ed[i]) {
							if (used[u] == 1) {
								cnt++;
							}
						}

						if (cnt != 1) {
							throw 1;
						}
					}
					else {
						if (deg[i] % 3 != 2) {
							throw 1;
						}
						int cnt = 0;

						for (int u : ed[i]) {
							if (used[u] == 1) {
								cnt++;
							}
						}

						if (cnt != 2) {
							throw 1;
						}
					}
				}
			}

			cout << '\n';
			return;
		}

		for (int u : ed[v]) {
			if (dst[u] == -1) {
				q.push(u);
				dst[u] = dst[v] + 1;
				lnk[u] = v;
			}
		}
	}

	assert(false);
}

vector <int> vt[maxn];

void print(vector <int> &c, bool check = true) {
	cout << "Yes\n";
	cout << n - (int)c.size() << '\n';
	memset(used, 0, (n + 1) * sizeof(int));
	for (int x : c) {
		used[x] = true;
	}

	for (int j = 1; j <= n; j++) {
		if (!used[j]) {
			cout << j << ' ';
		}
	}

	if (check) {
		for (int j = 1; j <= n; j++) {
			if (used[j]) {
				int cnt = 0;

				for (int u : ed[j]) {
					if (used[u]) {
						cnt++;
					}
				}

				if (cnt % 3 != deg[j] % 3) {
					throw 1;
				}
			}
		}
	}

	cout << '\n';
}

bool good[maxn];

void add(int a) {
	memset(lnk, -1, (n + 1) * sizeof(int));
	memset(dst, -1, (n + 1) * sizeof(int));
	dst[a] = 0;
	lnk[a] = -1;
	queue <int> q;
	q.push(a);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (good[v] && dst[v] != 0) {
			while (v != -1) {
				c.push_back(v);
				v = lnk[v];
			}
			return;
		}

		for (int u : ed[v]) {
			if (dst[u] == -1 && used[u] == used[a]) {
				dst[u] = dst[v] + 1;
				q.push(u);
				lnk[u] = v;
			}
		}
	}

	assert(false);
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		int m;

		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			ed[i].clear();
		}

		for (int i = 0; i < m; i++) {
			int x, y;

			cin >> x >> y;
			ed[x].push_back(y);
			ed[y].push_back(x);
		}

		if (n == 1) {
			cout << "No\n";
			continue;
		}

		for (int i = 1; i <= n; i++) {
			deg[i] = (int)ed[i].size();
		}

		int buf = 0;

		for (int i = 1; i <= n; i++) {
			if (deg[i] == 1) {
				buf++;
			}
		}

		if (m == n - 1 && buf == 2) {
			cout << "No\n";
			continue;
		}

		bool ok = false;

		for (int i = 1; i <= n; i++) {
			if (deg[i] % 3 == 0) {
				cout << "Yes\n";
				cout << n - 1 << '\n';

				for (int j = 1; j <= n; j++) {
					if (j != i) {
						cout << j << ' ';
					}
				}

				cout << '\n';
				ok = true;
				break;
			}
		}

		if (ok) {
			continue;
		}

		c.clear();
		memset(used, -1, (n + 1) * sizeof(int));
		posit = 0;

		for (int i = 1; i <= n; i++) {
			if (used[i] == -1 && deg[i] % 3 == 2) {
				if (dfs(i)) {
					print(c, false);
					ok = true;
					break;
				}
				posit++;
			}
		}

		if (ok) {
			continue;
		}

		vector <int> g;

		for (int i = 1; i <= n; i++) {
			if (deg[i] % 3 == 1) {
				g.push_back(i);
			}
		}

		if (g.empty()) {
			cout << "No\n";
			continue;
		}

		for (int i = 0; i < posit; i++) {
			num[i].clear();
			vt[i].clear();
		}

		for (int v : g) {
			for (int u : ed[v]) {
				if (deg[u] % 3 == 1) {
					cout << "Yes\n";
					cout << n - 2 << '\n';
					for (int i = 1; i <= n; i++) {
						if (i != v && i != u) {
							cout << i << ' ';
						}
					}
					cout << '\n';
					ok = true;
					break;
				}
				else {
					if (num[used[u]].empty() || num[used[u]].back() != v) {
						num[used[u]].push_back(v);
					}
				}
			}
			if (ok) {
				break;
			}
		}

		if (ok) {
			continue;
		}

		for (int i = 0; i < posit; i++) {
			if ((int)num[i].size() >= 2) {
				bfs(num[i][0]);
				ok = true;
				break;
			}
		}

		if (ok) {
			continue;
		}

		c.clear();

		int v = g[0];

		int a = -1, b = -1;

		memset(good, 0, (n + 1) * sizeof(bool));

		for (int u : ed[v]) {
			vt[used[u]].push_back(u);
			good[u] = true;
			if (a == -1 || a == used[u]) {
				a = used[u];
			}
			else {
				b = used[u];
			}
		}

		if (b == -1 || (int)vt[a].size() < 2 || (int)vt[b].size() < 2) {
			throw 1;
		}

		if (vt[a].size() < vt[b].size()) {
			swap(a, b);
		}

		add(vt[a][0]);
		add(vt[b][0]);
		c.push_back(v);

		int cnt = 0;

		for (int x : c) {
			if (good[x]) {
				cnt++;
			}
		}

		if (cnt != 4) {
			throw 1;
		}

		if ((int)c.size() != n) {
			print(c);
			continue;
		}

		printf("No\n");
	}

	//system("pause");
	return 0;
}