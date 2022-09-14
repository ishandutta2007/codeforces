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

struct vt {
	int x;
	int sz;
	int l, r;

	vt() {

	}

	vt(int x) : x(x), sz(1), l(-1), r(-1) {

	}
};

const int maxm = (int)6e7 + 10;

vt mas[maxm];
int posit = 0;

int my_new(int x) {
	mas[posit] = vt(x);
	return posit++;
}

int cpy(int t) {
	int nt = my_new(mas[t].x);
	mas[nt].sz = mas[t].sz;
	mas[nt].l = mas[t].l;
	mas[nt].r = mas[t].r;

	return nt;
}

int sz(int t) {
	return (t == -1 ? 0 : mas[t].sz);
}

void recalc(int t) {
	mas[t].sz = sz(mas[t].l) + sz(mas[t].r) + 1;
}

void split(int t, int k, int &l, int &r) {
	if (t == -1) {
		l = -1;
		r = -1;
	}
	else if (sz(mas[t].l) >= k) {
		t = cpy(t);
		split(mas[t].l, k, l, mas[t].l);
		r = t;
		recalc(r);
	}
	else {
		t = cpy(t);
		split(mas[t].r, k - sz(mas[t].l) - 1, mas[t].r, r);
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

	if ((ll)rand() * (sz(l) + sz(r)) <= (ll)sz(l) * RAND_MAX) {
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

int go(int t, int ps) {
	if (t == -1) {
		cout << "ASS" << endl;
		throw 1;
	}

	if (sz(mas[t].l) > ps) {
		return go(mas[t].l, ps);
	}
	else if (sz(mas[t].l) == ps) {
		return mas[t].x;
	}
	else {
		return go(mas[t].r, ps - sz(mas[t].l) - 1);
	}
}

int n, m;

int get_seg(int t, int l, int r) {
	if (l < 0) {
		return merge(get_seg(t, l + n, n - 1), get_seg(t, 0, r));
	}
	else if (r >= n) {
		return merge(get_seg(t, l, n - 1), get_seg(t, 0, r - n));
	}
	else {
		int lm, m, rm;

		split(t, r + 1, lm, rm);
		split(lm, l, lm, m);
		return m;
	}
}

int rebuild(int t, int sd) {
	int nt = get_seg(t, sd, m - 1 + sd);
	nt = merge(nt, get_seg(t, m - sd, n - 1 - sd));

	return nt;
}

const int maxn = (int)1e5 + 10;

int lnk[maxn];

void build_lnk(int t, int sd) {
	if (t == -1) {
		return;
	}

	build_lnk(mas[t].l, sd);
	lnk[sd + sz(mas[t].l)] = mas[t].x;
	build_lnk(mas[t].r, sd + sz(mas[t].l) + 1);
}

int used[maxn];

void reduce(int &t) {
	if (posit > maxm / 2) {
		build_lnk(t, 0);

		posit = 0;
		t = -1;

		for (int i = 0; i < n; i++) {
			t = merge(t, my_new(lnk[i]));
		}
	}
}

int main() {
	cin >> n >> m;
	//n = (int)1e5;
	//m = n / 3;

	int s;
	ll t;

	cin >> s >> t;
	//s = 1;
	//t = (ll)1e12;
	s--;

	int cn = t % n;

	t /= n;

	int ans = -1;

	for (int i = 0; i < n; i++) {
		ans = merge(ans, my_new(i));
	}

	for (int i = 1; i < n; i++) {
		ans = rebuild(ans, i);
		if (sz(ans) != n) {
			cout << "BAD" << endl;
			throw 1;
		}
		if (i == cn) {
			s = go(ans, s);
		}

		reduce(ans);
	}

	memset(lnk, -1, sizeof lnk);

	build_lnk(ans, 0);

	for (int i = 0; i < n; i++) {
		if (lnk[i] == -1) {
			cout << "BAD1" << endl;
			throw 1;
		}
	}

	int it = 1;

	while (used[s] == 0 && t != 0) {
		used[s] = it++;
		t--;
		s = lnk[s];
	}

	t %= (it - used[s]);

	while (t--) {
		s = lnk[s];
	}

	cout << s + 1 << endl;

	//system("pause");
}