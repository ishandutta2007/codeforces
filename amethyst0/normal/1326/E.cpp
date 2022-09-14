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

const int maxn = (int)3e5 + 10;
int v[maxn];

int t[maxn];

void change(int pos, int x) {
	for (; pos < maxn; pos |= pos + 1) {
		t[pos] += x;
	}
}

int go(int pos) {
	int ans = 0;

	for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
		ans += t[pos];
	}

	return ans;
}

int go(int l, int r) {
	return go(r) - go(l - 1);
}

int tr[4 * maxn];
int st[4 * maxn];

void sets(int it, int x) {
	tr[it] += x;
	st[it] += x;
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
		int m = (l + r) >> 1;
		push(it);

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

		tr[it] = max(tr[2 * it], tr[2 * it + 1]);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	vector <pii> g;

	for (int i = 0; i < n; i++) {
		g.push_back(mp(v[i], i));
	}

	const int inf = (int)1e9;

	for (int i = 0; i < 4 * maxn; i++) {
		tr[i] = -inf;
	}

	sort(all(g));
	reverse(all(g));
	int ps = 0;

	change(1, 0, n - 1, g[ps].second, g[ps].second, inf);
	change(1, 0, n - 1, 0, g[ps].second, 1);
	ps = 1;

	for (int i = 0; i < n; i++) {
		printf("%d ", g[ps - 1].first);

		int w;
		scanf("%d", &w);
		w--;

		change(1, 0, n - 1, 0, w, -1);

		while (ps < (int)g.size() && tr[1] <= 0) {
			int w = g[ps].second;

			change(1, 0, n - 1, w, w, inf);
			change(1, 0, n - 1, 0, w, 1);
			ps++;
		}
	}
}