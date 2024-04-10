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
#include <unordered_map>
#include <iomanip>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int p = (int)1e9 + 7, q = 998244353;

int add(int x, int y, int mod) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
	return x;
}

int sub(int x, int y, int mod) {
	x -= y;
	if (x < 0) {
		x += mod;
	}
	return x;
}

int mul(int x, int y, int mod) {
	return (ll)x * y % mod;
}

pii operator +(pii a, pii b) {
	a.first = add(a.first, b.first, p);
	a.second = add(a.second, b.second, q);
	return a;
}

pii operator -(pii a, pii b) {
	a.first = sub(a.first, b.first, p);
	a.second = sub(a.second, b.second, q);
	return a;
}

pii operator *(pii a, pii b) {
	a.first = mul(a.first, b.first, p);
	a.second = mul(a.second, b.second, q);
	return a;
}

const int maxn = (int)1e5 + 10;

pii st[maxn];

const int maxm = (int)6e6 + 10;

mt19937 rr;

struct vt {
	int x;
	pii hsh;
	int sz;
	bool tp;
	int l, r;

	vt() {

	}

	vt(int x, int tp) : x(x), hsh(mp(x, x)), sz(1), tp(tp), l(-1), r(-1) {

	}
};

vt mas[maxm];
int posit = 0;

int my_new(int x, int tp) {
	mas[posit] = vt(x, tp);
	return posit++;
}

int sz(int t) {
	return (t == -1 ? 0 : mas[t].sz);
}

pii hsh(int t) {
	return (t == -1 ? mp(0, 0) : mas[t].hsh);
}

void recalc(int t) {
	mas[t].sz = 1 + sz(mas[t].l) + sz(mas[t].r);

	if (mas[t].tp) {
		mas[t].hsh = hsh(mas[t].l) * st[1] + mp(mas[t].x, mas[t].x);
		mas[t].hsh = mas[t].hsh * st[sz(mas[t].r)] + hsh(mas[t].r);
	}
	else {
		mas[t].hsh = hsh(mas[t].r) * st[1] + mp(mas[t].x, mas[t].x);
		mas[t].hsh = mas[t].hsh * st[sz(mas[t].l)] + hsh(mas[t].l);
	}
}

int lst;

int cpy(int t) {
	if (t >= lst) {
		assert(false);
		return t;
	}

	int nt = my_new(mas[t].x, mas[t].tp);
	mas[nt].hsh = mas[t].hsh;
	mas[nt].sz = mas[t].sz;
	mas[nt].l = mas[t].l;
	mas[nt].r = mas[t].r;
	return nt;
}

int merge(int l, int r) {
	if (l == -1) {
		return r;
	}

	if (r == -1) {
		return l;
	}

	if (mas[l].sz * (ll)UINT_MAX >= (ll)rr() * (mas[l].sz + mas[r].sz)) {
		l = cpy(l);
		mas[l].r = merge(mas[l].r, r);
		recalc(l);
		return l;
	}
	else {
		r = cpy(r);
		mas[r].l = merge(l, mas[r].l);
		recalc(r);
		return r;
	}
}

void split(int t, int k, int &l, int &r) {
	if (t == -1) {
		l = -1;
		r = -1;
		return;
	}

	t = cpy(t);

	if (sz(mas[t].l) >= k) {
		split(mas[t].l, k, l, mas[t].l);
		r = t;
		recalc(r);
	}
	else {
		split(mas[t].r, k - 1 - sz(mas[t].l), mas[t].r, r);
		l = t;
		recalc(l);
	}
}

pii t[4 * maxn];
bool ok[4 * maxn];

pair <pii, bool> merg(pii a, pii b) {
	int t1 = a.second;
	int t2 = b.first;

	int k = min(sz(t1), sz(t2));

	int l1 = -1, r1 = t1, l2 = t2, r2 = -1;

	if (k != sz(t1)) {
		lst = posit;
		split(t1, sz(t1) - k, l1, r1);
	}

	if (k != sz(t2)) {
		lst = posit;
		split(t2, k, l2, r2);
	}

	if (hsh(r1) != hsh(l2)) {
		return mp(mp(-1, -1), false);
	}

	lst = posit;
	return mp(mp(merge(a.first, r2), merge(l1, b.second)), true);
}

int s[maxn];

void build(int it, int l, int r) {
	if (l == r) {
		ok[it] = true;
		if (s[l] > 0) {
			t[it] = mp(-1, my_new(s[l], true));
		}
		else {
			t[it] = mp(my_new(-s[l], false), -1);
		}
	}
	else {
		int m = (l + r) >> 1;

		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);
		ok[it] = ok[2 * it] & ok[2 * it + 1];

		if (ok[it]) {
			auto f = merg(t[2 * it], t[2 * it + 1]);
			ok[it] = f.second;
			t[it] = f.first;
		}
	}
}

void change(int it, int l, int r, int pos) {
	if (l == r) {
		ok[it] = true;
		if (s[l] > 0) {
			t[it] = mp(-1, my_new(s[l], true));
		}
		else {
			t[it] = mp(my_new(-s[l], false), -1);
		}
	}
	else {
		int m = (l + r) >> 1;

		if (pos <= m) {
			change(2 * it, l, m, pos);
		}
		else {
			change(2 * it + 1, m + 1, r, pos);
		}

		ok[it] = ok[2 * it] & ok[2 * it + 1];

		if (ok[it]) {
			auto f = merg(t[2 * it], t[2 * it + 1]);
			ok[it] = f.second;
			t[it] = f.first;
		}
	}
}

pair <pii, bool> go(int it, int l, int r, int lm, int rm) {
	if (l == lm && r == rm) {
		return mp(t[it], ok[it]);
	}
	else {
		int m = (l + r) >> 1;

		if (rm <= m) {
			return go(2 * it, l, m, lm, rm);
		}
		else if (lm > m) {
			return go(2 * it + 1, m + 1, r, lm, rm);
		}
		else {
			auto a = go(2 * it, l, m, lm, m);
			auto b = go(2 * it + 1, m + 1, r, m + 1, rm);

			a.second = a.second & b.second;
			if (a.second) {
				a = merg(a.first, b.first);
			}

			return a;
		}
	}
}

int main() {
	st[0] = mp(1, 1);

	for (int i = 1; i < maxn; i++) {
		st[i] = st[i - 1] * mp(1234567, 1234657);
	}

	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
		/*if (i < n / 2) {
			s[i] = i + 1;
		}
		else {
			s[i] = -s[n - 1 - i];
		}*/
	}

	build(1, 0, n - 1);

	int q;

	cin >> q;

	while (q--) {
		int tp, l, r;

		scanf("%d %d %d", &tp, &l, &r);
		/*tp = 1;
		l = rand() % n + 1;
		r = rand() % n + 1;
		if (l > r) {
			swap(l, r);
		}*/

		if (posit > 4 * maxm / 5) {
			posit = 0;
			build(1, 0, n - 1);
		}

		if (tp == 1) {
			l--;
			s[l] = r;
			change(1, 0, n - 1, l);
		}
		else {
			l--;
			r--;

			auto f = go(1, 0, n - 1, l, r);

			if (f.second && f.first == mp(-1, -1)) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}
	}
}