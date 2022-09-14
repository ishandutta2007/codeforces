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
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>
#include <unordered_set>
#define ld double
#define mp make_pair
#define ll long long
#define pii pair <int, int>

using namespace std;

const int maxn = (int)1e5 + 10;
int v[maxn];

struct point {
	int x;
	int mins;
	int sz;
	bool rev;
	int y;
	int l, r;

	point() {

	}

	point(int x): x(x), mins(x), sz(1), rev(false), y(rand()), l(-1), r(-1) {

	}
};

point mas[maxn];
int posit = 0;

int my_new(int x) {
	mas[posit] = point(x);
	return posit++;
}

void sets(int it) {
	if (it == -1) {
		return;
	}

	mas[it].rev = !mas[it].rev;
	swap(mas[it].l, mas[it].r);
}

void push(int t) {
	if (t == -1) {
		return;
	}

	if (mas[t].rev) {
		sets(mas[t].l);
		sets(mas[t].r);
		mas[t].rev = false;
	}
}

int mins(int t) {
	if (t == -1) {
		return (int)1e9;
	}

	return mas[t].mins;
}

int size(int t) {
	if (t == -1) {
		return 0;
	}

	return mas[t].sz;
}

void recalc(int t) {
	if (t == -1) {
		return;
	}

	mas[t].mins = min(min(mas[t].x, mins(mas[t].l)), mins(mas[t].r));
	mas[t].sz = 1 + size(mas[t].l) + size(mas[t].r);
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
	} else {
		push(r);
		mas[r].l = merge(l, mas[r].l);
		recalc(r);
		return r;
	}
}

void split(int t, int sz, int &l, int &r) {
	push(t);
	if (t == -1) {
		l = -1;
		r = -1;
	} else if (size(mas[t].l) >= sz) {
		split(mas[t].l, sz, l, mas[t].l);
		recalc(t);
		r = t;
	} else {
		split(mas[t].r, sz - size(mas[t].l) - 1, mas[t].r, r);
		recalc(t);
		l = t;
	}
}

int pos_min(int t) {
	if (mins(mas[t].l) == mas[t].mins) {
		return pos_min(mas[t].l);
	}

	if (mas[t].x == mas[t].mins) {
		return size(mas[t].l);
	}

	return size(mas[t].l) + 1 + pos_min(mas[t].r);
}

void write(int t) {
	if (t == -1) {
		return;
	}

	write(mas[t].l);
	cout << mas[t].x << endl;
	write(mas[t].r);
}

int main() {
	int n;

	cin >> n;

	int t = -1;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);

		t = merge(t, my_new(v[i]));
	}

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		//write(t);
		//cout << endl;
		int w = pos_min(t);

		ans += w + 1;

		int l, m, r;

		split(t, w + 1, l, r);
		split(l, w, l, m);
		t = merge(r, l);
	}

	cout << ans << endl;

	return 0;
}