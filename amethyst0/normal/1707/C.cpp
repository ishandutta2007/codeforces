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

const int maxn = (int)2e5 + 10, maxlog = 20;
int p[maxn];
pii e[maxn];
bool us[maxn];

int getp(int x) {
	return (p[x] == x ? x : p[x] = getp(p[x]));
}

int tin[maxn], tout[maxn];
int tt = -1;
int par[maxlog][maxn];
int h[maxn];
vector <int> ed[maxn];

void dfs(int v, int pr, int hh) {
	par[0][v] = pr;
	for (int i = 1; i < maxlog; i++) {
		par[i][v] = par[i - 1][par[i - 1][v]];
	}
	tt++;
	h[v] = hh;
	tin[v] = tt;
	for (int u : ed[v]) {
		if (u != pr) {
			dfs(u, v, hh + 1);
		}
	}
	tout[v] = tt;
}

int up(int x, int y) {
	int d = h[x] - h[y];
	d--;
	for (int i = 0; i < maxlog; i++) {
		if ((d >> i) & 1) {
			x = par[i][x];
		}
	}
	return x;
}

int cnt[maxn];

bool is_par(int x, int y) {
	return tin[x] <= tin[y] && tout[y] <= tout[x];
}

void dfs1(int v, int pr = -1, int s = 0) {
	s += cnt[v];
	cnt[v] = s;
	for (int u : ed[v]) {
		if (u != pr) {
			dfs1(u, v, s);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		p[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		e[i] = { x, y };
		int px = getp(x);
		int py = getp(y);
		if (px != py) {
			p[px] = py;
			ed[x].push_back(y);
			ed[y].push_back(x);
			us[i] = true;
		}
	}

	dfs(0, 0, 0);
	int tot = 0;

	for (int i = 0; i < m; i++) {
		if (us[i]) {
			continue;
		}

		auto[x, y] = e[i];
		tot++;
		if (!is_par(x, y)) {
			cnt[x]++;
		}
		else {
			int a = up(y, x);
			cnt[a]--;
			cnt[0]++;
		}

		if (!is_par(y, x)) {
			cnt[y]++;
		}
		else {
			int a = up(x, y);
			cnt[a]--;
			cnt[0]++;
		}
	}

	dfs1(0);

	for (int i = 0; i < n; i++) {
		if (cnt[i] == tot) {
			printf("1");
		}
		else {
			printf("0");
		}
	}
	printf("\n");

	return 0;
}