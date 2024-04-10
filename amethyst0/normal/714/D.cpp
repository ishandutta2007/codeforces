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
#include <unordered_map>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (ll)n; i++)
#define mp make_pair
#define ui unsigned ll

using namespace std;

int it = 0;
int lx[2], rx[2], ly[2], ry[2];
int n;

int get_ans(int a, int b, int c, int d) {
	printf("? %d %d %d %d\n", a, b, c, d);
	fflush(stdout);
	int x;

	scanf("%d", &x);

	if (it == 1) {
		if (a <= lx[0] && rx[0] <= c && b <= ly[0] && ry[0] <= d) {
			x--;
		}
	}

	return x;
}

int main() {
	cin >> n;

	int l = 1;
	int r = n;

	while (l != r) {
		int m = (l + r) >> 1;

		if (get_ans(1, 1, n, m) > 0) {
			r = m;
		} else {
			l = m + 1;
		}
	}

	int x, y, x1, y1;

	x = 1, y = 1, x1, y1 = l;

	l = 1;
	r = n;

	while (l != r) {
		int m = (l + r) >> 1;

		if (get_ans(1, 1, m, y1) > 0) {
			r = m;
		} else {
			l = m + 1;
		}
	}

	x1 = l;

	l = 1;
	r = y1;

	while (l != r) {
		int m = (l + r + 1) >> 1;

		if (get_ans(1, m, x1, y1) > 0) {
			l = m;
		} else {
			r = m - 1;
		}
	}

	y = l;

	l = 1;
	r = x1;

	while (l != r) {
		int m = (l + r + 1) >> 1;

		if (get_ans(m, y, x1, y1) > 0) {
			l = m;
		} else {
			r = m - 1;
		}
	}

	x = l;

	lx[0] = x;
	rx[0] = x1;
	ly[0] = y;
	ry[0] = y1;
	it++;

	//SECOND

	l = 1;
	r = n;

	while (l != r) {
		int m = (l + r) >> 1;

		if (get_ans(1, 1, n, m) > 0) {
			r = m;
		} else {
			l = m + 1;
		}
	}

	x, y, x1, y1;

	x = 1, y = 1, x1, y1 = l;

	l = 1;
	r = n;

	while (l != r) {
		int m = (l + r) >> 1;

		if (get_ans(1, 1, m, y1) > 0) {
			r = m;
		} else {
			l = m + 1;
		}
	}

	x1 = l;

	l = 1;
	r = y1;

	while (l != r) {
		int m = (l + r + 1) >> 1;

		if (get_ans(1, m, x1, y1) > 0) {
			l = m;
		} else {
			r = m - 1;
		}
	}

	y = l;

	l = 1;
	r = x1;

	while (l != r) {
		int m = (l + r + 1) >> 1;

		if (get_ans(m, y, x1, y1) > 0) {
			l = m;
		} else {
			r = m - 1;
		}
	}

	x = l;

	cout << "! " << lx[0] << ' ' << ly[0] << ' ' << rx[0] << ' ' << ry[0] << ' ' << x << ' ' << y << ' ' << x1 << ' ' << y1 << endl;

	fflush(stdout);

	return 0;
}