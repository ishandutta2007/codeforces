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
const int maxn = 100100;

inline pair<pair<bool, bool>, string> useinout() {
	return (mp(mp(0, 0), ""));
}

int a[maxn];
int b[maxn];
int snm[maxn];
ll sum[maxn];
bool pm[maxn];

int getroot(int u) {
	return (u == snm[u] ? snm[u] : snm[u] = getroot(snm[u]));
}
void merge(int u, int v) {
	u = getroot(u), v = getroot(v);
	snm[v] = u;
	sum[u] += sum[v];
}

int solve() {

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		snm[i] = i;
		sum[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}

	ll mx = 0;

	vector<ll> ans;
	for (int i = n; i >= 1; i--) {
		ans.pb(mx);
		int p = b[i];
		pm[p] = 1;
		sum[p] = a[p];
		if (pm[p - 1]) {
			merge(p, p - 1);
		}
		if (pm[p + 1]) {
			merge(p, p + 1);
		}
		p = getroot(p);
		mx = max(mx, sum[p]);
	}

	for (int i = n - 1; i >= 0; i--) {
		printf("%lld\n", ans[i]);
	}


	return (0);
}