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
#define ld double

using namespace std;

const int maxn = (int)3e5 + 10;
vector <int> ed[maxn];
vector <int> ans;

int dst[maxn];
int lnk[maxn];

int bfs(int x, int y) {
	memset(dst, -1, sizeof dst);

	dst[x] = 0;

	queue <int>	q;

	q.push(x);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < (int)ed[v].size(); i++) {
			int u = ed[v][i];

			if (dst[u] == -1) {
				dst[u] = dst[v] + 1;
				q.push(u);
				lnk[u] = v;
			}
		}
	}

	if (dst[y] != -1) {
		ans.push_back(y);

		int z = y;

		while (y != x) {
			y = lnk[y];
			ans.push_back(y);
		}

		reverse(ans.begin(), ans.end());

		return dst[z];
	}
	else {
		return (int)1e9;
	}
}

bool used[maxn];

bool f[maxn];

int n;

void solve(int x) {
	used[x] = true;

	vector <int> ver;

	queue <int> q;

	q.push(x);

	while (!q.empty()) {
		int v = q.front();
		ver.push_back(v);
		q.pop();

		for (int i = 0; i < (int)ed[v].size(); i++) {
			int u = ed[v][i];

			if (!used[u]) {
				used[u] = true;
				q.push(u);
			}
		}
	}

	bool good = true;

	int best = x;

	for (int i = 0; i < (int)ver.size(); i++) {
		int v = ver[i];

		if ((int)ed[v].size() != (int)ver.size() - 1) {
			good = false;
			break;
		}
	}

	if (good) {
		return;
	}

	for (int i = 0; i < (int)ver.size(); i++) {
		int v = ver[i];

		if ((int)ed[v].size() > (int)ed[best].size()) {
			best = v;
		}
	}

	x = best;

	f[x] = true;

	for (int i = 0; i < (int)ed[x].size(); i++) {
		int u = ed[x][i];

		f[u] = true;
	}

	for (int i = 0; i < (int)ed[x].size(); i++) {
		int u = ed[x][i];

		for (int j = 0; j < (int)ed[u].size(); j++) {
			int to = ed[u][j];

			if (!f[to]) {
				printf("5 %d %d %d %d %d %d\n", 1, x, u, to, x, n);
				exit(0);
			}
		}
	}

	for (int i = 0; i < (int)ed[x].size(); i++) {
		int u = ed[x][i];

		if ((int)ed[u].size() == (int)ed[x].size()) {
			continue;
		}

		set <int> s;

		for (int j = 0; j < (int)ed[x].size(); j++) {
			s.insert(ed[x][j]);
		}

		s.erase(u);

		for (int j = 0; j < (int)ed[u].size(); j++) {
			int to = ed[u][j];

			s.erase(to);
		}

		if (s.empty()) {
			throw 1;
		}

		printf("5 %d %d %d %d %d %d\n", 1, u, x, *s.begin(), u, n);
		exit(0);
	}

	throw 1;
}

int main() {
	//freopen("output.txt", "w", stdout);
	int m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	int res = bfs(1, n);

	if (res <= 4) {
		cout << (int)ans.size() - 1 << endl;

		for (int i = 0; i < (int)ans.size(); i++) {
			cout << ans[i] << ' ';
		}

		return 0;
	} else {
		used[1] = true;

		for (int i = 0; i < (int)ed[1].size(); i++) {
			int u = ed[1][i];

			used[u] = true;
		}

		for (int i = 0; i < (int)ed[1].size(); i++) {
			int u = ed[1][i];

			for (int j = 0; j < (int)ed[u].size(); j++) {
				int to = ed[u][j];

				if (!used[to]) {
					printf("4 %d %d %d %d %d\n", 1, u, to, 1, n);
					return 0;
				}
			}
		}

		vector <int> ver;

		for (int i = 0; i < (int)ed[1].size(); i++) {
			int u = ed[1][i];

			ver.push_back(u);

			for (int j = 0; j < (int)ed[u].size(); j++) {
				int to = ed[u][j];

				if (to == 1) {
					swap(ed[u][j], ed[u].back());
					ed[u].pop_back();
				}
			}
		}

		memset(used, 0, sizeof used);

		for (int i = 0; i < (int)ver.size(); i++) {
			int x = ver[i];

			if (!used[x]) {
				solve(x);
			}
		}

		if (res < (int)1e9) {
			cout << (int)ans.size() - 1 << endl;

			for (int i = 0; i < (int)ans.size(); i++) {
				cout << ans[i] << ' ';
			}

			return 0;
		}
	}

	printf("-1\n");
}