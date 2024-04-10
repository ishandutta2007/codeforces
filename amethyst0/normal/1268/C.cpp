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
#include <fstream>
#include <bitset>
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

mt19937 rr;

struct vt {
	int x;
	int y;
	int sz;
	ll sum;
	int l, r;

	vt() {

	}

	vt(int x) : x(x), y(rr()), sz(1), sum(x), l(-1), r(-1) {

	}
};

const int maxn = (int)2e5 + 10;

vt mas[maxn];
int posit = 0;

int my_new(int x) {
	mas[posit] = vt(x);
	return posit++;
}

int sz(int t) {
	return (t == -1 ? 0 : mas[t].sz);
}

ll sums(int t) {
	return (t == -1 ? 0 : mas[t].sum);
}

void recalc(int t) {
	mas[t].sz = 1 + sz(mas[t].l) + sz(mas[t].r);
	mas[t].sum = mas[t].x + sums(mas[t].l) + sums(mas[t].r);
}

int merge(int l, int r) {
	if (l == -1) {
		return r;
	}

	if (r == -1) {
		return l;
	}

	if (mas[l].y > mas[r].y) {
		mas[l].r = merge(mas[l].r, r);
		recalc(l);
		return l;
	}

	mas[r].l = merge(l, mas[r].l);
	recalc(r);
	return r;
}

void split(int t, int x, int &l, int &r) {
	if (t == -1) {
		l = -1;
		r = -1;
		return;
	}

	if (mas[t].x < x) {
		split(mas[t].r, x, mas[t].r, r);
		l = t;
		recalc(l);
	}
	else {
		split(mas[t].l, x, l, mas[t].l);
		r = t;
		recalc(r);
	}
}

void splitsz(int t, int k, int &l, int &r) {
	if (t == -1) {
		l = -1;
		r = -1;
		return;
	}

	if (sz(mas[t].l) >= k) {
		splitsz(mas[t].l, k, l, mas[t].l);
		r = t;
		recalc(r);
	}
	else {
		splitsz(mas[t].r, k - 1 - sz(mas[t].l), mas[t].r, r);
		l = t;
		recalc(l);
	}
}

void add(int &t, int x) {
	int l, r;

	split(t, x, l, r);
	t = merge(merge(l, my_new(x)), r);
}

int tr[maxn];

int go(int pos) {
	int ans = 0;

	for (; pos < maxn; pos |= pos + 1) {
		ans += tr[pos];
	}

	return ans;
}

void change(int pos, int x) {
	for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
		tr[pos] += x;
	}
}

int v[maxn];

ll f(int k) {
	return (ll)k * (k + 1) / 2;
}

int main() {
	int n;

	cin >> n;

	vector <int> p;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		v[i]--;
		p.push_back(i);
	}

	sort(all(p), [&](int a, int b) {
		return v[a] < v[b];
	});

	ll inv = 0;

	int t = -1;

	for (int ps : p) {
		inv += go(ps);
		change(ps, 1);

		add(t, ps);

		int num = mas[t].sz;

		int l, m, r;

		num /= 2;

		splitsz(t, num, l, r);
		splitsz(r, 1, m, r);

		ll cur = (sz(l) - sz(r)) * (ll)mas[m].x;
		cur += sums(r);
		cur -= sums(l);
		cur -= f(sz(l));
		cur -= f(sz(r));
		t = merge(merge(l, m), r);

		printf("%lld\n", cur + inv);
	}
}