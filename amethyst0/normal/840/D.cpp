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
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)3e5 + 10;

struct point {
	int cnt, l, r;

	point(): cnt(0), l(-1), r(-1) {

	}
};

point mas[40 * maxn];
int posit = 0;

int my_new() {
	return posit++;
}

void make(int it) {
	if (mas[it].l == -1) {
		mas[it].l = my_new();
		mas[it].r = my_new();
	}
}

int cpy(int it) {
	int t = my_new();
	mas[t].l = mas[it].l;
	mas[t].r = mas[it].r;
	mas[t].cnt = mas[it].cnt;

	return t;
}

int change(int it, int l, int r, int pos) {
	it = cpy(it);

	if (l == r) {
		mas[it].cnt++;
	} else {
		make(it);
		int m = (l + r) >> 1;

		mas[it].cnt++;

		if (pos <= m) {
			mas[it].l = change(mas[it].l, l, m, pos);
		} else {
			mas[it].r = change(mas[it].r, m + 1, r, pos);
		}
	}

	return it;
}

int v[maxn];
int t[maxn];

int getcnt(int it) {
	if (it == -1) {
		return 0;
	}

	return mas[it].cnt;
}

int getl(int it) {
	if (it == -1) {
		return -1;
	}

	return mas[it].l;
}

int getr(int it) {
	if (it == -1) {
		return -1;
	}

	return mas[it].r;
}

int go(int it1, int it2, int l, int r, int d, int k) {
	if ((getcnt(it2) - getcnt(it1)) * k <= d) {
		return -1;
	}

	if (l == r) {
		return l;
	}

	int m = (l + r) >> 1;

	int ans = go(getl(it1), getl(it2), l, m, d, k);

	if (ans == -1) {
		ans = go(getr(it1), getr(it2), m + 1, r, d, k);
	}

	return ans;
}

int main() {
	int n, q;

	cin >> n >> q;

	int tr = my_new();

	t[0] = tr;

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);

		tr = change(tr, 1, n, x);
		t[i + 1] = tr;
	}

	while (q--) {
		int l, r, k;

		scanf("%d %d %d", &l, &r, &k);

		l--;

		int d = r - l;

		printf("%d\n", go(t[l], t[r], 1, n, d, k));
	}

	return 0;
}