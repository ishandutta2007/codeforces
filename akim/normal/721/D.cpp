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

inline pair<pair<bool, bool>, string> useinout();

void init() {
#ifdef SOL
	if (useinout().fs.fs)
		freopen("input.txt", "r", stdin);
	if (useinout().fs.sc)
		freopen("output.txt", "w", stdout);
#else
	srand(time(0));
	const string file = useinout().sc;
	if (!file.empty()) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
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
	init();
	int exitval = solve();
	finish(exitval);
	return (0);
}

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 200100;

inline pair<pair<bool, bool>, string> useinout() {
	return (mp(mp(0, 0), ""));
}

set<pair<ll, int> > st;
ll a[maxn];

int solve() {

	int n, m, p = 0;
	ll x;
	vector<int> pos;
	scanf("%d%d%lld", &n, &m, &x);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		st.insert(mp(abs(a[i]), i));
		if (!a[i])
			pos.pb(i);
		p += a[i] < 0;
	}

	while (m && !pos.empty()) {
		if (!(p & 1)) {
			st.erase(mp(abs(a[pos.back()]), pos.back()));
			a[pos.back()] -= x;
			st.insert(mp(abs(a[pos.back()]), pos.back()));
			p++;
		} else {
			st.erase(mp(abs(a[pos.back()]), pos.back()));
			a[pos.back()] += x;
			st.insert(mp(abs(a[pos.back()]), pos.back()));
		}
		pos.ppb();
		m--;
	}

	while (m && !(p & 1)) {
		int pos = st.begin()->sc;
		st.erase(st.begin());
		if (a[pos] >= 0) {
			a[pos] -= x;
			if (a[pos] == 0 && m - 1) {
				a[pos] -= x;
				m--;
			}
			if (a[pos] < 0)
				p++;
		} else {
			a[pos] += x;
			if (a[pos] == 0 && m - 1) {
				a[pos] += x;
				m--;
			}
			if (a[pos] > 0)
				p--;
		}
		st.insert(mp(abs(a[pos]), pos));
		m--;
	}

	while (m) {
		int pos = st.begin()->sc;
		st.erase(st.begin());
		if (a[pos] >= 0) {
			a[pos] += x;
		} else {
			a[pos] -= x;
		}
		st.insert(mp(abs(a[pos]), pos));
		m--;
	}

	for (int i = 0; i < n; i++) {
		printf("%lld ", a[i]);
	}

	return (0);
}

// by Andrey Kim