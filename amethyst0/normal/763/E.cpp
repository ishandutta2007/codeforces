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

const int maxn = (int)1e5 + 10;

vector <int> ed[maxn];
int l[maxn], r[maxn];
int ans[maxn];

struct point {
	int x;
	int l, r;

	point() {

	}

	point(int x, int l, int r): x(x), l(l), r(r) {

	}
};

point mas[200 * maxn];
int posit = 0;

int my_new(int x, int l, int r) {
	if (posit == 120 * maxn) {
		posit = 0;
	}

	mas[posit] = point(x, l, r);
	return posit++;
}

void make(int it, int lm, int rm) {
	if (mas[it].l == -1) {
		mas[it].l = my_new(lm, -1, -1);
		mas[it].r = my_new(rm, -1, -1);
	}
}

int cop(int it) {
	return my_new(mas[it].x, mas[it].l, mas[it].r);
}

int change(int it, int l, int r, int pos, int z, bool st = true) {
	if (l == r) {
		if (st) {
			it = cop(it);
		}

		mas[it].x = z;
		//cout << "C " << it << ' ' << pos << ' ' << z << endl;
		
		return it;
	} else {
		make(it, l, r);
		if (st) {
			it = cop(it);
		}

		int m = (l + r) >> 1;

		if (pos <= m) {
			mas[it].l = change(mas[it].l, l, m, pos, z, st);
		} else {
			mas[it].r = change(mas[it].r, m + 1, r, pos, z, st);
		}

		return it;
	}
}

int go(int it, int l, int r, int pos) {
	if (l == r) {
		//cout << "G " << it << ' ' << pos << ' ' << mas[it].x << endl;
		return mas[it].x;
	} else {
		make(it, l, r);
		int m = (l + r) >> 1;

		if (pos <= m) {
			return go(mas[it].l, l, m, pos);
		} else {
			return go(mas[it].r, m + 1, r, pos);
		}
	}
}

int tp[maxn];
int cnt[maxn];

int getp(int it, int l, int r, int pos) {
	int p = go(it, l, r, pos);

	if (p == pos) {
		return p;
	}

	p = getp(it, l, r, p);
	change(it, l, r, pos, p, false);

	return p;
}

int getp(int it, int l, int r, int nit, int nl, int nr, int pos) {
	int p = ((l <= pos && pos <= r) ? go(it, l, r, pos) : go(nit, nl, nr, pos));

	if (p == pos) {
		return p;
	}

	p = getp(it, l, r, nit, nl, nr, p);
	
	return p;
}

void go(int lm, int rm, vector <int> &a) {
	vector <int> b;
	vector <int> c;
	vector <int> d;

	int m = (lm + rm) >> 1;

	if (lm != rm) {
		for (int i = 0; i < (int)a.size(); i++) {
			int pos = a[i];

			if (r[pos] <= m) {
				c.push_back(pos);
			} else if (l[pos] > m) {
				d.push_back(pos);
			} else {
				b.push_back(pos);
			}
		}
	} else {
		for (int i = 0; i < (int)a.size(); i++) {
			ans[a[i]] = 1;
		}

		return;
	}

	if (!c.empty()) {
		go(lm, m, c);
	}

	if (!d.empty()) {
		go(m + 1, rm, d);
	}

	int now = my_new(lm, -1, -1);
	int cn = 0;

	for (int i = m; i >= lm; i--) {
		cn++;
		for (int j = 0; j < (int)ed[i].size(); j++) {
			int u = ed[i][j];
			
			if (!(i <= u && u <= m)) {
				continue;
			}
			
			int a = getp(now, lm, m, i);
			int b = getp(now, lm, m, u);

			if (a != b) {
				now = change(now, lm, m, a, b);
				cn--;
			}
		}

		tp[i] = now;
		cnt[i] = cn;
	}

	now = my_new(m + 1, -1, -1);
	cn = 0;

	for (int i = m + 1; i <= rm; i++) {
		cn++;

		for (int j = 0; j < (int)ed[i].size(); j++) {
			int u = ed[i][j];
			
			if (!(m + 1 <= u && u <= i)) {
				continue;
			}
			
			int a = getp(now, m + 1, rm, i);
			int b = getp(now, m + 1, rm, u);

			if (a != b) {
				cn--;
				now = change(now, m + 1, rm, a, b);
			}
		}

		tp[i] = now;
		cnt[i] = cn;
	}

	for (int i = 0; i < (int)b.size(); i++) {
		int pos = b[i];

		int lmm = l[pos];
		int rmm = r[pos];

		int now1 = tp[lmm];
		int now2 = tp[rmm];
		cn = cnt[lmm] + cnt[rmm];

		for (int j = m + 1; j <= min(rmm, m + 5); j++) {
			for (int k = 0; k < (int)ed[j].size(); k++) {
				int u = ed[j][k];

				if (!(lmm <= u && u <= m)) {
					continue;
				}

				int a = getp(now1, lm, m, now2, m + 1, rm, u);
				int b = getp(now2, m + 1, rm, now1, lm, m, j);

				if (a != b) {
					cn--;
					if (lm <= a && a <= m) {
						now1 = change(now1, lm, m, a, b);
					} else {
						now = change(now2, m + 1, rm, a, b);
					}
				}
			}
		}

		ans[pos] = cn;
	}
}

int main() {
	int n, k, m;

	cin >> n >> k >> m;

	for (int i = 0; i < m; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		ed[a].push_back(b);
		ed[b].push_back(a);
	}

	int q;

	cin >> q;

	vector <int> a;

	for (int i = 0; i < q; i++) {
		scanf("%d %d", &l[i], &r[i]);

		a.push_back(i);
	}

	go(1, n, a);

	for (int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}