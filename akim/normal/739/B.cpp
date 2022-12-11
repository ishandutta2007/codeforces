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

vector<pair<int, int> > rb[maxn];
ll a[maxn], ans[maxn];

multiset<ll> st[maxn];
multiset<ll>::iterator it;
ll ob[maxn];

void dfs(int u) {
	ob[u] = 0;
	st[u].insert(a[u]);
	for (pair<int, int> vv : rb[u]) {
		int v = vv.fs, c = vv.sc;
		dfs(v);
		ob[v] += c;

		if (st[v].size() > st[u].size()) {
			for (it = st[u].begin(); it != st[u].end(); it++) {
				st[v].insert(*it - ob[u] + ob[v]);
			}
			st[u].swap(st[v]);
			swap(ob[u], ob[v]);
		} else {
			for (it = st[v].begin(); it != st[v].end(); it++) {
				st[u].insert(*it - ob[v] + ob[u]);
			}
		}
	}
	while (*st[u].begin() < ob[u]) {
		st[u].erase(st[u].begin());
	}
	ans[u] = st[u].size() - 1;
}

int solution() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i < n; i++) {
		int p, w;
		scanf("%d%d", &p, &w);
		p--;
		rb[p].pb(mp(i, w));
	}

	dfs(0);

	for (int i = 0; i < n; i++) {
		printf("%lld ", ans[i]);
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}