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

pair<int, pair<int, int> > p[maxn];

ll deo[4 * maxn];

ll getmx(int lf, int rg, int v = 0, int tl = 0, int tr = maxn - 1) {
	if (rg < tl || tr < lf) {
		return (0);
	}
	if (lf <= tl && tr <= rg) {
		return (deo[v]);
	}
	int tm = (tl + tr) >> 1;
	return (max(getmx(lf, rg, v * 2 + 1, tl, tm), getmx(lf, rg, v * 2 + 2, tm + 1, tr)));
}

void updmx(int pos, ll val, int v = 0, int tl = 0, int tr = maxn - 1) {
	if (pos < tl || tr < pos) {
		return;
	}
	if (tl == tr) {
		deo[v] = max(deo[v], val);
		return;
	}
	int tm = (tl + tr) >> 1;
	updmx(pos, val, v * 2 + 1, tl, tm);
	updmx(pos, val, v * 2 + 2, tm + 1, tr);
	deo[v] = max(deo[v * 2 + 1], deo[v * 2 + 2]);
	return;
}

int solution() {

	int n;
	scanf("%d", &n);
	vector<int> vc;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &p[i].sc.fs, &p[i].fs, &p[i].sc.sc);
		vc.pb(p[i].sc.fs);
		vc.pb(p[i].fs);
	}
	sort(vc.begin(), vc.end());
	vc.erase(unique(vc.begin(), vc.end()), vc.end());

	sort(&p[0], &p[n]);
	reverse(&p[0], &p[n]);

	for (int i = 0; i < n; i++) {
		p[i].fs = lower_bound(vc.begin(), vc.end(), p[i].fs) - vc.begin();
		p[i].sc.fs = lower_bound(vc.begin(), vc.end(), p[i].sc.fs) - vc.begin();
	}

	for (int i = 0; i < n; i++) {
		ll hh = getmx(0, p[i].fs - 1) + p[i].sc.sc;
		updmx(p[i].sc.fs, hh);
	}
	printf("%lld", getmx(0, vc.size() - 1));

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim