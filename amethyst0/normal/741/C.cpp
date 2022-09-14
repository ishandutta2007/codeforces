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
#include <unordered_set>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10;

vector <int> ed[maxn];
pii f[maxn];

bool used[maxn];
int col[maxn];

void dfs(int v, int tp = 1) {
	col[v] = tp;
	used[v] = true;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (!used[u]) {
			dfs(u, 3 - tp);
		} else if (col[u] == tp) {
			throw 1;
		}
	}
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		ed[x].push_back(y);
		ed[y].push_back(x);

		f[i] = mp(x, y);
	}

	for (int i = 1; i <= 2 * n; i += 2) {
		ed[i].push_back(i + 1);
		ed[i + 1].push_back(i);
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (!used[i]) {
			dfs(i);
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", col[f[i].first], col[f[i].second]);
	}

	return 0;
}