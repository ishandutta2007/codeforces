#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>
#if __cplusplus > 199711L
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//	tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name;
//	order_of_key
//	find_by_order
#endif

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
	srand(time(0));
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

int solve();

void finish(int exitval) {
	fflush(stdout);
#ifdef SOL
	fprintf(stderr, "\nexit value: %d\ntime: %.3lf ms\n", exitval, 1000. * clock() / CLOCKS_PER_SEC);
#endif
}

int main() {
	initialization();
	int exitval = solve();
	finish(exitval);
	return (0);
}

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 300100;

pair<ll, ll> t[maxn];
long double fv1[maxn];
ll fv2[maxn];
pair<ll, int> p[maxn];

void add1(long double (&fv)[maxn], int pos, ll val) {
	for (; pos < maxn; pos |= pos + 1) {
		fv[pos] += val;
	}
}

long double get1(long double (&fv)[maxn], int pos) {
	long double ret = 0;
	for (; pos >= 0; pos &= pos + 1, pos--) {
		ret += fv[pos];
	}
	return (ret);
}

void add2(ll (&fv)[maxn], int pos, ll val) {
	for (; pos < maxn; pos |= pos + 1) {
		fv[pos] += val;
	}
}

ll get2(ll (&fv)[maxn], int pos) {
	ll ret = 0;
	for (; pos >= 0; pos &= pos + 1, pos--) {
		ret += fv[pos];
	}
	return (ret);
}

int solve() {

	ll t0;
	int n;
	scanf("%d%lld%*lld", &n, &t0);
	n--;
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &t[i].fs, &t[i].sc);
	}
	sort(&t[0], &t[n]);
	reverse(&t[0], &t[n]);
	t[n] = mp(0, 0);

	for (int i = 0; i < n; i++) {
		p[i] = mp(t[i].sc - t[i].fs + 1, i);
	}
	sort(&p[0], &p[n]);

	if (t0 >= t[0].fs) {
		printf("1\n");
		return (0);
	}

	ll ans = n + 1;
	for (int i = 0; i < n; i++) {
		int pos = lower_bound(&p[0], &p[n], mp(t[i].sc - t[i].fs + 1, i)) - &p[0];
		add1(fv1, pos + 1, t[i].sc - t[i].fs + 1);
		add2(fv2, pos + 1, 1);
		ll fr = t0 - t[i + 1].fs;
		if (fr < 0) {
			continue;
		}
		int l = 0, r = maxn;
		while (l + 1 < r) {
			int m = (l + r) >> 1;
			if (get1(fv1, m) <= fr) {
				l = m;
			} else {
				r = m;
			}
		}
		l = get2(fv2, l);
		ans = min(ans, i + 2ll - l);
	}
	cout << ans;

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

// by Andrey Kim