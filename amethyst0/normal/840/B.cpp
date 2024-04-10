/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)3e5 + 10;

vector <pii> ed[maxn];
int used[maxn];
bool need[maxn];
vector <int> ver;
bool us[maxn];

int dfs(int v, int num) {
	us[v] = true;
	int ch = 0;

	if (need[v]) {
		ch ^= 1;
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].first;

		if (!us[u]) {
			ch ^= dfs(u, ed[v][i].second);
		}
	}

	if (ch) {
		used[num] = true;
	}

	return ch;
}

int d[maxn];

int main() {
	int n, m;

	cin >> n >> m;

	int g = -1;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);

		if (d[i] == -1) {
			g = i;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		ed[x].push_back(mp(y, i));
		ed[y].push_back(mp(x, i));
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] == -1) {

		} else if (d[i] != 0) {
			ver.push_back(i);
			need[i] = true;
		}
	}

	if (ver.size() % 2 == 1 && g == -1) {
		cout << -1 << endl;
		return 0;
	}

	dfs((g == -1 ? 1 : g), m);

	vector <int> ans;

	for (int i = 0; i < m; i++) {
		if (used[i]) {
			ans.push_back(i + 1);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;

	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}