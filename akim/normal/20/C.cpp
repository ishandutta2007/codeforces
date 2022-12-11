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
const int maxn = 100100;

vector<pair<int, int> > rb[maxn];
int p[maxn];
bool pm[maxn];

void ret(int u) {
	if (p[u] == -1) {
		printf("%d ", u + 1);
		return;
	}
	ret(p[u]);
	printf("%d ", u + 1);
}

int solve() {

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		u--, v--;
		rb[u].pb(mp(v, c));
		rb[v].pb(mp(u, c));
	}
	priority_queue<pair<ll, pair<int, int> > > q;
	q.push(mp(0ll, mp(0, -1)));
	while (!q.empty()) {
		ll d = -q.top().fs;
		int u = q.top().sc.fs, par = q.top().sc.sc;
		q.pop();
		if (pm[u])
			continue;
		pm[u] = 1;
		p[u] = par;

		if (u == n - 1) {
			ret(u);
			return (0);
		}

		for (int i = 0; i < (int) rb[u].size(); i++) {
			int v = rb[u][i].fs, c = rb[u][i].sc;
			if (pm[v])
				continue;
			q.push(mp(-(d + c), mp(v, u)));
		}
	}
	printf("-1\n");

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

// by Andrey Kim