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
 
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int
 
const int maxn = (int)1e5 + 10;
 
vector <int> ed[maxn];
 
mt19937 rr(1);
 
int used[maxn];
 
bool dfs(int v) {
	used[v] = 1;
 
	for (int u : ed[v]) {
		if (used[u] == 0) {
			if (!dfs(u)) {
				return false;
			}
		}
		else if (used[u] == 2) {
			return false;
		}
	}
 
	used[v] = 2;
 
	return true;
}
 
bool good[maxn];
 
int tin[maxn], tup[2][maxn];
int vert[maxn];
int tt = -1;
 
void rec(int v, int x) {
	if (x < tup[0][v]) {
		tup[1][v] = tup[0][v];
		tup[0][v] = x;
	}
	else if (x < tup[1][v]) {
		tup[1][v] = x;
	}
}
 
void build(int v) {
	tt++;
	tin[v] = tt;
	vert[tt] = v;
	tup[0][v] = tup[1][v] = tt;
 
	used[v] = 1;
 
	for (int u : ed[v]) {
		if (used[u] == 0) {
			build(u);
			rec(v, tup[0][u]);
			rec(v, tup[1][u]);
		}
		else {
			rec(v, tin[u]);
		}
	}
}
 
void fnd(int v) {
	if (tup[1][v] == tin[v]) {
		if (tup[0][v] != tin[v]) {
			good[v] = good[vert[tup[0][v]]];
		}
	}
 
	used[v] = 1;
 
	for (int u : ed[v]) {
		if (used[u] == 0) {
			fnd(u);
		}
	}
}
 
int main() {
	int k = 100;
 
	int t;
 
	cin >> t;
 
	while (t--) {
		int n, m;
 
		scanf("%d %d", &n, &m);
 
		for (int i = 0; i < n; i++) {
			ed[i].clear();
		}
 
		for (int i = 0; i < m; i++) {
			int x, y;
 
			scanf("%d %d", &x, &y);
			x--;
			y--;
			ed[x].push_back(y);
		}
 
		int v = -1;
 
		for (int it = 0; it < k; it++) {
			int u = rr() % n;
 
			for (int i = 0; i < n; i++) {
				used[i] = 0;
			}
 
			if (dfs(u)) {
				bool ok = true;
 
				for (int i = 0; i < n; i++) {
					if (used[i] == 0) {
						ok = false;
						break;
					}
				}
 
				if (ok) {
					v = u;
					break;
				}
			}
		}
 
		if (v == -1) {
			printf("-1\n");
			continue;
		}
 
		for (int i = 0; i < n; i++) {
			good[i] = false;
		}
 
		good[v] = true;
 
		tt = -1;
 
		for (int i = 0; i < n; i++) {
			used[i] = 0;
		}
 
		build(v);
 
		for (int i = 0; i < n; i++) {
			used[i] = 0;
		}
 
		fnd(v);
 
		vector <int> ans;
 
		for (int i = 0; i < n; i++) {
			if (good[i]) {
				ans.push_back(i);
			}
		}
 
		if (5 * (int)ans.size() < n) {
			printf("-1\n");
			continue;
		}
 
		sort(all(ans));
 
		for (int x : ans) {
			printf("%d ", x + 1);
		}
 
		printf("\n");
	}
}