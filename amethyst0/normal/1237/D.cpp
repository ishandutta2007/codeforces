//#pragma comment(linker, "/STACK:1000000000")
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
#define ld double

using namespace std;

const int maxn = (int)3e5 + 10;
int v[maxn];

struct vt {
	int x, y;
	int tm;
	int minx;
	int l, r;

	vt() {

	}

	vt(int x, int tm) : x(x), y(rand()), tm(tm), minx(tm), l(-1), r(-1) {

	}
};

vt mas[maxn];
int posit = 0;

int my_new(int x, int tm) {
	mas[posit] = vt(x, tm);
	return posit++;
}

const int inf = (int)1e9 + 10;

int minx(int t) {
	return (t == -1 ? inf : mas[t].minx);
}

void recalc(int t) {
	mas[t].minx = min(mas[t].tm, min(minx(mas[t].l), minx(mas[t].r)));
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

	if (mas[t].x > x) {
		split(mas[t].l, x, l, mas[t].l);
		recalc(t);
		r = t;
	}
	else {
		split(mas[t].r, x, mas[t].r, r);
		recalc(t);
		l = t;
	}
}

int add(int t, int x, int tm) {
	int l, r;

	split(t, x, l, r);
	return merge(merge(l, my_new(x, tm)), r);
}

int calc(int &t, int x) {
	int l, r;

	split(t, x, l, r);
	int ans = minx(l);
	t = merge(l, r);
	return ans;
}

int lnk[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = n; i < 3 * n; i++) {
		v[i] = v[i - n];
	}

	int m = n * 3;
	swap(n, m);
	int t = -1;

	for (int i = n - 1; i >= 0; i--) {
		int val = (v[i] + 1) / 2 - 1;

		int ans = calc(t, val);

		lnk[i] = ans;
		t = add(t, v[i], i);

		if (i != n - 1) {
			lnk[i] = min(lnk[i], lnk[i + 1]);
		}
	}

	for (int i = 0; i < m; i++) {
		if (lnk[i] == inf) {
			cout << -1 << ' ';
		}
		else {
			cout << lnk[i] - i << ' ';
		}
	}

	//system("pause");
	return 0;
}