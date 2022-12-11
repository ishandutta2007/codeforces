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

void init() {
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
	init();
	int exitval = solve();
	finish(exitval);
	return (0);
}

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

map<int, vector<int> > mam, man;
int x[maxn], y[maxn], u[maxn];
ll ans[maxn];
set<pair<int, int> > used;

int solve() {

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i < k; i++) {
		scanf("%d%d", &x[i], &y[i]);
		ans[i] = -1;
		mam[x[i] - y[i]].pb(i);
		man[x[i] + y[i]].pb(i);
	}

	int dir = 1;
	ll px = 0, py = 0;
	ll t = 0;
	while (!used.count(mp(px, py))) {
//		cout << px << " " << py << " " << dir << endl;
		used.insert(mp(px, py));
		if (px == n && py == m)
			break;
		if (px == 0 && py == m)
			break;
		if (px == n && py == 0)
			break;

		while (!mam[px - py].empty()) {
			int id = mam[px - py].back();
			mam[px - py].ppb();
			if (u[id])
				continue;
			u[id] = 1;
			ans[id] = abs(px - x[id]) + t;
		}
		while (!man[px + py].empty()) {
			int id = man[px + py].back();
			man[px + py].ppb();
			if (u[id])
				continue;
			u[id] = 1;
			ans[id] = abs(px - x[id]) + t;
		}

		if (dir == 1) {
			if (n - px < m - py) {
				t += n - px;
				py += n - px;
				px += n - px;
				dir = 2;
			} else {
				t += m - py;
				px += m - py;
				py += m - py;
				dir = 4;
			}
		} else
		if (dir == 2) {
			if (px < m - py) {
				t += px;
				py += px;
				px -= px;
				dir = 1;
			} else {
				t += m - py;
				px -= m - py;
				py += m - py;
				dir = 3;
			}
		} else
		if (dir == 3) {
			if (px < py) {
				t += px;
				py -= px;
				px -= px;
				dir = 4;
			} else {
				t += py;
				px -= py;
				py -= py;
				dir = 2;
			}
		} else
		if (dir == 4) {
			if (n - px < py) {
				t += n - px;
				py -= n - px;
				px += n - px;
				dir = 3;
			} else {
				t += py;
				px += py;
				py -= py;
				dir = 1;
			}
		}
	}
//	cout << px << " " << py << " " << dir << endl;

	for (int i = 0; i < k; i++) {
		printf("%lld\n", ans[i]);
	}

	return (0);
}

// by Andrey Kim