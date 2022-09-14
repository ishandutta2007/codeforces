#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10, maxlog = 19;
pii t[4 * maxn];
int st[4 * maxn];

void sets(int it, int x) {
	st[it] += x;
	t[it].first += x;
}

void push(int it) {
	if (st[it] != 0) {
		sets(2 * it, st[it]);
		sets(2 * it + 1, st[it]);
		st[it] = 0;
	}
}

void change(int it, int l, int r, int lm, int rm, int x) {
	if (l == lm && r == rm) {
		sets(it, x);
	}
	else {
		push(it);
		int m = (l + r) >> 1;

		if (rm <= m) {
			change(2 * it, l, m, lm, rm, x);
		}
		else if (lm > m) {
			change(2 * it + 1, m + 1, r, lm, rm, x);
		}
		else {
			change(2 * it, l, m, lm, m, x);
			change(2 * it + 1, m + 1, r, m + 1, rm, x);
		}

		if (t[2 * it].first > t[2 * it + 1].first) {
			t[it] = t[2 * it];
		}
		else if (t[2 * it].first < t[2 * it + 1].first) {
			t[it] = t[2 * it + 1];
		}
		else {
			t[it] = t[2 * it];
			t[it].second += t[2 * it + 1].second;
		}
	}
}

vector <int> ed[maxn];
int tin[maxn], tout[maxn];
int tt = -1;

int p[maxlog][maxn];

void dfs(int v, int pr) {
	tt++;
	tin[v] = tt;
	p[0][v] = pr;

	for (int i = 1; i < maxlog; i++) {
		p[i][v] = p[i - 1][p[i - 1][v]];
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != pr) {
			dfs(u, v);
		}
	}

	tout[v] = tt;
}

bool is_anc(int x, int y) {
	return tin[x] <= tin[y] && tout[y] <= tout[x];
}

int up(int y, int x) {
	for (int i = maxlog - 1; i >= 0; i--) {
		if (is_anc(x, p[i][y]) && p[i][y] != x) {
			y = p[i][y];
		}
	}

	if (p[0][y] != x) {
		throw 1;
	}

	return y;
}

void build(int it, int l, int r) {
	t[it].second = r - l + 1;

	if (l != r) {
		int m = (l + r) >> 1;

		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);
	}
}

int main() {
	int n, q;

	cin >> n >> q;

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		//x = i + 1;
		//y = i + 2;
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	build(1, 0, n - 1);

	dfs(1, 1);

	set <pii> s;

	int sums = 0;

	while (q--) {
		int x, y;

		scanf("%d %d", &x, &y);

		int d = 1;

		if (s.count(mp(x, y))) {
			d = -1;
			s.erase(mp(x, y));
			s.erase(mp(y, x));
		}
		else {
			s.insert(mp(x, y));
			s.insert(mp(y, x));
		}

		sums += d;

		if (!is_anc(x, y)) {
			swap(x, y);
		}

		if (!is_anc(x, y)) {
			change(1, 0, n - 1, tin[x], tout[x], d);
			change(1, 0, n - 1, tin[y], tout[y], d);
		}
		else {
			change(1, 0, n - 1, tin[y], tout[y], d);
			change(1, 0, n - 1, 0, n - 1, d);
			
			int z = up(y, x);

			change(1, 0, n - 1, tin[z], tout[z], -d);
		}

		if (sums == t[1].first) {
			printf("%d\n", t[1].second);
		}
		else {
			printf("0\n");
		}
	}

	//system("pause");
}