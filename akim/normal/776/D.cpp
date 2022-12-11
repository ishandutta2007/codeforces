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

bool was[maxn];
int pa[maxn], c[maxn];

vector<pair<int, int> > rb[maxn];

bool ok = 1, pm[maxn];
int cl[maxn];

void dfs(int u, int co = 0) {
	pm[u] = 1;
	cl[u] = co;
	for (pair<int, int> v : rb[u]) {
		if (pm[v.fs]) {
			if (cl[v.fs] != (co ^ v.sc)) {
				ok = 0;
			}
			continue;
		}
		dfs(v.fs, co ^ v.sc);
	}
}

int solution() {

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}

	for (int i = 0; i < m; i++) {
		int sz;
		scanf("%d", &sz);
		for (; sz--;) {
			int a;
			scanf("%d", &a);
			a--;
			if (was[a]) {
				rb[pa[a]].pb(mp(i, !c[a]));
				rb[i].pb(mp(pa[a], !c[a]));
			} else {
				was[a] = 1;
				pa[a] = i;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		if (!pm[i]) {
			dfs(i);
		}
	}

	if (ok) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim