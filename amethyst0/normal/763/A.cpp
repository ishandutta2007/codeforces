/*AMETHYSTS*/
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
#include <unordered_set>
#include <random>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10;

vector <int> ed[maxn];
int c[maxn];
int cl[maxn];
int cnt[maxn];
int sz[maxn];

int dfs(int v, int p = -1) {
	cl[v] = c[v];
	sz[v] = 1;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			sz[v] += dfs(u, v);

			if (cl[u] != cl[v]) {
				cl[v] = -1;
			}
		}
	}

	return sz[v];
}

void go(int v, int p = -1) {
	bool st = true;
	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p && cl[u] == -1) {
			st = false;
			break;
		}
	}

	if (st) {
		if (p == -1) {
			cout << "YES" << endl;
			cout << v << endl;
			exit(0);
		}

		int num = cnt[c[p]];

		for (int i = 0; i < (int)ed[v].size(); i++) {
			int u = ed[v][i];

			if (u != p && cl[u] == c[p]) {
				num -= sz[u];
			}
		}

		if (c[v] == c[p]) {
			num--;
		}

		if (num == sz[1] - sz[v]) {
			cout << "YES" << endl;
			cout << v << endl;
			exit(0);
		}
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			go(u, v);
		}
	}
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		ed[a].push_back(b);
		ed[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		cnt[c[i]]++;
	}

	dfs(1);

	go(1);

	cout << "NO" << endl;

	return 0;
}