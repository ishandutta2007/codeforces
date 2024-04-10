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
#include <unordered_map>
#include <random>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = 55;
vector <pii> ed[maxn];
int sz[maxn];
int yes[maxn];

void dfs(int v, int p) {
	sz[v] = yes[v];

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].first;

		if (u != p) {
			dfs(u, v);
			sz[v] += sz[u];
		}
	}
}

int dp[maxn][maxn][maxn][maxn];

const int inf = (int)1e9;

int m;

int go(int v, int p, int sz, int cnt) {
	if (dp[v][p][sz][cnt] != -1) {
		return dp[v][p][sz][cnt];
	}

	if (sz == 0 && cnt != 0) {
		return dp[v][p][sz][cnt] = inf;
	}

	if (sz == 0 && cnt == 0) {
		return dp[v][p][sz][cnt] = 0;
	}

	bool fl = false;
	int ans = 0;

	int l = 0, r = inf;

	while (l != r) {
		int m = (l + r + 1) >> 1;
	
		int cn = 0;

		for (int i = 0; i < (int)ed[v].size(); i++) {
			int u = ed[v][i].first;
			int w = ed[v][i].second;

			if (u != p) {
				fl = true;
			
				int lm = 0;
				int rm = sz;

				while (lm != rm) {
					int mm = (lm + rm + 1) >> 1;

					if (go(u, v, mm, cnt + sz - mm) + w >= m) {
						lm = mm;
					} else {
						rm = mm - 1;
					}
				}

				cn += lm;
			}
		}

		if (cn >= sz) {
			l = m;
		} else {
			r = m - 1;
		}
	}

	if (!fl) {
		return dp[v][p][sz][cnt] = go(v, v, cnt, 0);
	}

	return dp[v][p][sz][cnt] = l;
}

int main() {
	memset(dp, -1, sizeof dp);
	int n;

	cin >> n;

	for (int i = 1; i < n; i++) {
		int x, y, w;

		cin >> x >> y >> w;

		ed[x].push_back(mp(y, w));
		ed[y].push_back(mp(x, w));
	}

	int s;

	cin >> s;

	cin >> m;

	for (int i = 0; i < m; i++) {
		int x;

		cin >> x;

		yes[x]++;
	}

	int ans = (int)1e9;

	dfs(s, s);

	for (int i = 0; i < (int)ed[s].size(); i++) {
		ans = min(ans, go(ed[s][i].first, s, sz[ed[s][i].first], m - sz[ed[s][i].first]) + ed[s][i].second);
	}

	cout << ans << endl;

	return 0;
}