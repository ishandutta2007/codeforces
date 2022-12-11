#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")

#include <stdio.h>
#include <bits/stdc++.h>
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T1, typename T2> using ordered_map = tree<T1, T2, std::less<T1>, rb_tree_tag, tree_order_statistics_node_update>;

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
const int maxn = 200100;

int s[maxn], g[maxn], l[maxn], r[maxn], a[maxn];

int solution() {

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &s[i], &g[i]);
	}
	l[0] = s[0], r[0] = s[0] + g[0];
	for(int i = 1; i < n; i++) {
		l[i] = s[i], r[i] = s[i] + g[i];
		r[i] = min(r[i], r[i - 1] + 1);
		l[i] = max(l[i], l[i - 1] - 1);
		if(l[i] > r[i]) {
			printf("-1\n");
			return 0;
		}
	}
	ll ans = 0;
	int cur = r[n - 1];
	ans += cur - s[n - 1];
	a[n - 1] = cur;
	for(int i = n - 2; i >= 0; i--) {
		cur = min(cur + 1, r[i]);
		ans += cur - s[i];
		a[i] = cur;
	}
	printf("%lld\n", ans);
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim