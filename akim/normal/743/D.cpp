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

int a[maxn];
ll ans, w[maxn], mx[maxn];
bool pm[maxn];
vector<int> rb[maxn];

void dfs(int u) {
	pm[u] = 1;
	w[u] = a[u];
	vector<ll> vc;
	for (int v : rb[u]) {
		if (pm[v])
			continue;
		dfs(v);
		w[u] += w[v];
		vc.pb(mx[v]);
	}
	sort(vc.begin(), vc.end());
	reverse(vc.begin(), vc.end());
	if (vc.size() >= 2) {
		ans = max(ans, vc[0] + vc[1]);
	}
	mx[u] = w[u];
	if (vc.size()) {
		mx[u] = max(mx[u], vc[0]);
	}
//	cout << u << " " << mx[u] << " " << (vc.size() ? vc[0] : -2) << endl;
}

int solution() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		rb[u].pb(v);
		rb[v].pb(u);
	}

	ans = mod * -1ll * mod;
	dfs(0);
	if (ans == mod * -1ll * mod) {
		printf("Impossible\n");
	} else {
		printf("%lld\n", ans);
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim