#include <stdio.h>
#include <bits/stdc++.h>
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//																														tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name; order_of_key find_by_order

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

inline pair<pair<bool, bool>, pair<string, bool> > useinout();

void initialization() {
#ifdef SOL
	if (useinout().fs.fs)
		freopen("input.txt", "r", stdin);
	if (useinout().fs.sc)
		freopen("output.txt", "w", stdout);
#else
	srand(__rdtsc());
	const string file = useinout().sc.fs;
	if (!file.empty()) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	}
	if(useinout().sc.sc) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
#endif
}

int solution();

void finish(int exitval) {
	fflush(stdout);
#ifdef SOL
	fprintf(stderr, "\nexit value: %d\ntime: %.3lf ms\n", exitval, 1000. * clock() / CLOCKS_PER_SEC);
#endif
}

int main() {
	initialization();
	finish(solution());
	return (0);
}

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;
//const int maxn = 10;

int alv[4 * maxn], lfr[4 * maxn], x[maxn];

void update(int v, int tl, int tr) {
	lfr[v] = lfr[v * 2 + 1] + max(lfr[v * 2 + 2] - alv[v * 2 + 1], 0);
	alv[v] = alv[v * 2 + 2] + max(alv[v * 2 + 1] - lfr[v * 2 + 2], 0);
}

void upd(int pos, int val, int v = 0, int tl = 0, int tr = maxn - 1) {
	if (pos < tl || pos > tr) {
		return;
	}
	if (tl == tr) {
		x[tl] = val;
		if (val < 0) {
			lfr[v] = 1;
		} else {
			alv[v] = 1;
		}
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(pos, val, v * 2 + 1, tl, tm);
	upd(pos, val, v * 2 + 2, tm + 1, tr);
	update(v, tl, tr);
	return;
}

int get(int rmv = 0, int v = 0, int tl = 0, int tr = maxn - 1) {
	if (alv[v] == 0)
		return (-1);
	if (tl == tr) {
		return (x[tl]);
	}
	int tm = (tl + tr) >> 1;
	if (alv[v * 2 + 2] > rmv) {
		return (get(rmv, v * 2 + 2, tm + 1, tr));
	} else {
		return (get(rmv - alv[v * 2 + 2] + lfr[v * 2 + 2], v * 2 + 1, tl, tm));
	}
}

int solution() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int u, v, t;
		scanf("%d%d", &u, &t);
		u--;
		if (t) {
			scanf("%d", &v);
		} else {
			v = -1;
		}
		upd(u, v);
		printf("%d\n", get());
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

//by Andrey Kim