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
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll

using namespace std;

const int maxn = (int)3e5 + 10;
pair <ll, ll> v[maxn];
int num[maxn];

bool cmp(int x, int y) {
	if (v[x].first != v[y].first) {
		return v[x].first < v[y].first;
	}

	return x > y;
}

const ll inf = (ll)1e18 + 10;

struct point {
	ll x;
	int y;
	int sz;
	ll sum;
	int l, r;

	point() {

	}

	point(ll x): x(x), y(rand()), sz(1), sum(x), l(-1), r(-1) {

	}
};

point mas[maxn];
int posit = 0;

int my_new(ll x) {
	mas[posit] = point(x);
	return posit++;
}

ll sums(int t) {
	if (t == -1) {
		return 0;
	}

	return mas[t].sum;
}

int size(int t) {
	if (t == -1) {
		return 0;
	}

	return mas[t].sz;
}

void recalc(int t) {
	mas[t].sum = mas[t].x + sums(mas[t].l) + sums(mas[t].r);
	if (mas[t].sum > inf) {
		mas[t].sum = inf;
	}

	mas[t].sz = 1 + size(mas[t].l) + size(mas[t].r);
}

void split(int t, ll x, int &l, int &r) {
	if (t == -1) {
		l = -1;
		r = -1;
	} else if (mas[t].x > x) {
		split(mas[t].l, x, l, mas[t].l);
		r = t;
		recalc(r);
	} else {
		split(mas[t].r, x, mas[t].r, r);
		l = t;
		recalc(l);
	}
}

int merge(int l, int r) {
	if (l == -1) {
		return r;
	} else if (r == -1) {
		return l;
	} else if (mas[l].y > mas[r].y) {
		mas[l].r = merge(mas[l].r, r);
		recalc(l);
		return l;
	} else {
		mas[r].l = merge(l, mas[r].l);
		recalc(r);
		return r;
	}
}

int add(int t, ll x) {
	int l, r;

	split(t, x, l, r);

	return merge(merge(l, my_new(x)), r);
}

int go(int t, ll x) {
	if (t == -1) {
		return 0;
	} else if (sums(mas[t].l) >= x) {
		return go(mas[t].l, x);
	} else {
		int ans = size(mas[t].l);
		x -= sums(mas[t].l);

		if (x < mas[t].x) {
			return ans;
		}

		return ans + 1 + go(mas[t].r, x - mas[t].x);
	}
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%I64d %I64d", &v[i].first, &v[i].second);
		num[i] = i;
	}

	sort(num, num + n, cmp);

	int pos = 0;

	for (int i = 0; i < n; i++) {
		if (num[i] == 0) {
			pos = i;
		}
	}

	int ans = n - pos;

	int t = -1;

	for (int i = pos + 1; i < n; i++) {
		t = add(t, v[num[i]].second - v[num[i]].first + 1);
	}

	ll cnt = 0;

	for (int i = pos - 1; i >= 0; i--) {
		cnt = v[num[pos]].first - v[num[i]].first;

		ans = min(ans, n - i - 1 - go(t, cnt));
		t = add(t, v[num[i]].second - v[num[i]].first + 1);
	}

	cnt = v[num[pos]].first;

	ans = min(ans, n - go(t, cnt));

	cout << ans << endl;

	return 0;
}