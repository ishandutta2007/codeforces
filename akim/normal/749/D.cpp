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
const int maxn = 200100;

pair<int, int> deo[4 * maxn];

//void build(int v = 0, int tl = 0, int tr = maxn - 1) {
//	if (tl == tr) {
//		deo[v] = mp(tl ? -1 : 0, tr);
//		return;
//	}
//	int tm = (tl + tr) >> 1;
//	build(v * 2 + 1, tl, tm);
//	build(v * 2 + 2, tm + 1, tr);
//	return;
//}
//
//void upd(int pos, int val, int v = 0, int tl = 0, int tr = maxn - 1) {
//	if (pos < tl || pos > tr) {
//		return;
//	}
//	if (tl == tr) {
//		deo[v] = mp(val, pos);
//		return;
//	}
//	int tm = (tl + tr) >> 1;
//	upd(pos, val, v * 2 + 1, tl, tm);
//	upd(pos, val, v * 2 + 2, tm + 1, tr);
//	deo[v] = max(deo[v * 2 + 1], deo[v * 2 + 2]);
//	return;
//}
//
//int get(int pos, int v = 0, int tl = 0, int tr = maxn - 1) {
//	if (pos < tl || pos > tr) {
//		return (0);
//	}
//	if (tl == tr) {
//		return (deo[v].fs);
//	}
//	int tm = (tl + tr) >> 1;
//	int ret = max(get(pos, v * 2 + 1, tl, tm), get(pos, v * 2 + 2, tm + 1, tr));
//	return (ret);
//}

void build(int v = 0, int tl = 0, int tr = maxn - 1) {
	if (tl == tr) {
		deo[v] = mp(tl ? -1 : 0, tl);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2 + 1, tl, tm);
	build(v * 2 + 2, tm + 1, tr);
	deo[v] = max(deo[v * 2 + 1], deo[v * 2 + 2]);
	return;
}

void upd(int pos, int val, int v = 0, int tl = 0, int tr = maxn - 1) {
	if (pos < tl || pos > tr) {
		return;
	}

	if (tl == tr) {
		deo[v] = mp(val, pos);
		return;
	}

	int tm = (tl + tr) >> 1;
	upd(pos, val, v * 2 + 1, tl, tm);
	upd(pos, val, v * 2 + 2, tm + 1, tr);
	deo[v] = max(deo[v * 2 + 1], deo[v * 2 + 2]);
	return;
}

int get(int pos, int v = 0, int tl = 0, int tr = maxn - 1) {
	if (pos < tl || pos > tr) {
		return (-2);
	}

	if (tl == tr) {
		return (deo[v].fs);
	}

	int tm = (tl + tr) >> 1;
	int ret = max(get(pos, v * 2 + 1, tl, tm), get(pos, v * 2 + 2, tm + 1, tr));
	return (ret);
}

int get() {
	return (deo[0].sc);
}

int q[maxn], qq[maxn];
vector<int> vc[maxn];

int solution() {

	int n;
	scanf("%d", &n);
	build();
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		upd(x, y);
		vc[x].pb(y);
	}
	int m;
	scanf("%d", &m);
	for (; m--;) {
		int cnt;
		scanf("%d", &cnt);
		for (int i = 0; i < cnt; i++) {
			scanf("%d", &q[i]);
			qq[i] = get(q[i]);
			upd(q[i], -1);
		}
		int pos = get();
		if (pos == 0) {
			printf("0 0\n");
		} else {
			int val = get(pos);
			upd(pos, -1);
			int pos2 = get();
			int lt = 0;
			if (pos2 != 0) {
				lt = get(pos2);
			}
			upd(pos, val);
			int id = upper_bound(vc[pos].begin(), vc[pos].end(), lt) - vc[pos].begin();
			printf("%d %d\n", pos, vc[pos][id]);
		}
		for (int i = 0; i < cnt; i++) {
			upd(q[i], qq[i]);
		}
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

//by Andrey Kim