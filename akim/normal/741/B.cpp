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
const int maxn = 100100;

int w[maxn], b[maxn], snm[maxn];

int getroot(int u) {
	return (snm[u] == u ? u : snm[u] = getroot(snm[u]));
}

void merge(int u, int v) {
	u = getroot(u), v = getroot(v);
	snm[u] = v;
}

int sw[1010], sb[1010];
vector<pair<int, int> > g[1010];
int dp[1010];

int solution() {

	int n, m, we;
	scanf("%d%d%d", &n, &m, &we);
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n; i++) {
		snm[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		merge(u, v);
	}
	for (int i = 0; i < n; i++) {
		getroot(i);
		sw[snm[i]] += w[i];
		sb[snm[i]] += b[i];
		g[snm[i]].pb(mp(w[i], b[i]));
	}
	for (int i = 0; i < n; i++) {
		g[i].pb(mp(sw[i], sb[i]));
	}
	for (int j = 0; j < n; j++) {
		for (int i = we; i >= 0; i--) {
			for (int k = 0; k < (int) g[j].size(); k++) {
				if (i + g[j][k].fs <= we) {
					dp[i + g[j][k].fs] = max(dp[i + g[j][k].fs], dp[i] + g[j][k].sc);
				}
			}
		}
	}
	printf("%d", dp[we]);

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim