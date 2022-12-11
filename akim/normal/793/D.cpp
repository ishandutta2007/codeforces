#include <stdio.h>
#include <bits/stdc++.h>
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name; order_of_key find_by_order

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

#ifdef SOL
double starttime;
#endif

void initialization() {
#ifdef SOL
	starttime = 1000. * clock() / CLOCKS_PER_SEC;
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
	} else
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
	fprintf(stderr, "\n-----------------\nexit value: %d\ntime: %.3lf ms\n-----------------\n", exitval, 1000. * clock() / CLOCKS_PER_SEC - starttime);
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

vector<pair<int, int> > rb[maxn];

bool was[85][85][2][85];
int dp[85][85][2][85];

int calc(int l, int r, int p, int k) {
	if(k == 0) return(0);
	if(was[l][r][p][k]) {
		return(dp[l][r][p][k]);
	}
	was[l][r][p][k] = 1;
	int &ans = dp[l][r][p][k];
	ans = mod;
	int cur = 0;
	if(p == 0) {
		cur = l;
	} else {
		cur = r;
	}
	for(pair<int, int> v : rb[cur]) {
		if(v.fs <= l || v.fs >= r) {
			continue;
		}
		ans = min(ans, v.sc + min(calc(l, v.fs, 1, k - 1), calc(v.fs, r, 0, k - 1)));
	}
	return(ans);
}

int solution() {

	int n, k, ans = mod;
	scanf("%d%d", &n, &k);
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		rb[u].pb(mp(v, c));
	}
	for(int i = 1; i <= n; i++) {
		ans = min(ans, calc(0, i, 1, k - 1));
		ans = min(ans, calc(i, n + 1, 0, k - 1));
	}
	printf("%d", ans == mod ? -1 : ans);

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim