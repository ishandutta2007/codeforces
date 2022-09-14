//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

mt19937 rr(1);

struct vt {
	int x;
	int val;
	int st;
	int y;
	int sz;
	int l, r;

	vt() {

	}

	vt(int x, int val) : x(x), val(val), st(0), y(rr()), sz(1), l(-1), r(-1) {

	}
};

const int maxn = (int)1e6 + 10;

vt mas[maxn];
int posit = 0;

int my_new(int x, int val) {
	mas[posit] = vt(x, val);
	return posit++;
}

int sz(int t) {
	return (t == -1 ? 0 : mas[t].sz);
}

void recalc(int t) {
	mas[t].sz = 1 + sz(mas[t].l) + sz(mas[t].r);
}

void sets(int t, int x) {
	if (t != -1) {
		mas[t].x -= x;
		mas[t].st += x;
	}
}

void push(int t) {
	if (mas[t].st != 0) {
		sets(mas[t].l, mas[t].st);
		sets(mas[t].r, mas[t].st);
		mas[t].st = 0;
	}
}

void split(int t, int k, int &l, int &r) {
	if (t == -1) {
		l = -1;
		r = -1;
	}
	else if (sz(mas[t].l) >= k) {
		push(t);
		split(mas[t].l, k, l, mas[t].l);
		r = t;
		recalc(r);
	}
	else {
		push(t);
		split(mas[t].r, k - 1 - sz(mas[t].l), mas[t].r, r);
		l = t;
		recalc(l);
	}
}

void splitx(int t, int x, int &l, int &r) {
	if (t == -1) {
		l = -1;
		r = -1;
	}
	else if (mas[t].x > x) {
		push(t);
		splitx(mas[t].l, x, l, mas[t].l);
		r = t;
		recalc(r);
	}
	else {
		push(t);
		splitx(mas[t].r, x, mas[t].r, r);
		l = t;
		recalc(l);
	}
}

int merge(int l, int r) {
	if (l == -1) {
		return r;
	}

	if (r == -1) {
		return l;
	}

	if (mas[l].y > mas[r].y) {
		push(l);
		mas[l].r = merge(mas[l].r, r);
		recalc(l);
		return l;
	}

	push(r);
	mas[r].l = merge(l, mas[r].l);
	recalc(r);
	return r;
}

int minx(int t) {
	push(t);
	if (mas[t].l != -1) {
		return minx(mas[t].l);
	}

	return mas[t].x;
}

int maxx(int t) {
	push(t);
	if (mas[t].r != -1) {
		return maxx(mas[t].r);
	}

	return mas[t].x;
}

int go(int t, int x, bool fl = false) {
	int y = 0;

	while (sz(t) >= x) {
		y++;
		int l, r;
		int k = sz(t) - x;
		split(t, k, l, r);
		sets(r, 1);
		int m;
		splitx(r, 0, m, r);
		if (l == -1 || r == -1) {
			t = merge(l, r);
			continue;
		}

		int rx = minx(r);
		int lx = maxx(l);

		if (lx > rx) {
			split(r, rx, m, r);
			int md;
			split(l, lx, l, md);
			t = merge(merge(merge(l, m), md), r);
		}
		else {
			t = merge(l, r);
		}
	}

	return x * y;
}

int main() {
	int n;
	cin >> n;

	vector <int> g;

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);
		g.push_back(x);
	}

	sort(g.begin(), g.end());

	vector <pii> p;

	int l = 0;

	while (l < n) {
		int r = l;

		while (r < n && g[r] == g[l]) {
			r++;
		}

		p.push_back(mp(r - l, g[l]));
		l = r;
	}

	sort(p.begin(), p.end());

	int res = -1;
	int lx = -1;

	vector <pii> c = p;

	int tot = n;

	for (int x = n; x >= 1; x--) {
		for (int i = (int)c.size() - 1; i >= 0; i--) {
			if (c[i].first > x) {
				c[i].first--;
				tot--;
			}
			else {
				break;
			}
		}

		int y = tot / x;

		if (y >= x) {
			if (res < x * y) {
				res = x * y;
				lx = x;
			}
		}
	}

	cout << res << '\n';
	cout << lx << ' ' << res / lx << '\n';

	int a = lx;
	int b = res / lx;

	vector <vector <int> > f(lx, vector <int>(b, -1));

	int cnt = a * b;
	int x = 0;
	int y = 0;

	for (int i = (int)p.size() - 1; i >= 0; i--) {
		int cur = min(p[i].first, a);
		int val = p[i].second;

		while (cnt > 0 && cur > 0) {
			cnt--;
			cur--;

			f[x][y] = val;
			x++;
			y++;
			if (x == a) {
				x = 0;
				y -= a;
				y++;
			}

			y %= b;
			if (y < 0) {
				y += b;
			}
		}
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf("%d ", f[i][j]);
		}

		printf("\n");
	}

	//system("pause");
}