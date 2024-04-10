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

int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }, dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
bool pm[330][330], was[330][330][8];
int lev[330][330][8];
int a[30];

int solution() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	vector<pair<pair<int, int>, pair<int, int> > > vc;
	vc.pb(mp(mp(150, 150), mp(0, 0)));
	int ans = 0;
	for (int i = 0; i < (int) vc.size(); i++) {
		int x = vc[i].fs.fs, y = vc[i].fs.sc, l = vc[i].sc.fs, d = vc[i].sc.sc;
		if (was[x][y][d] && lev[x][y][d] == l) {
			continue;
		}
		was[x][y][d] = 1;
		lev[x][y][d] = l;
		for (int i = 0; i < a[l]; i++) {
			x += dx[d];
			y += dy[d];
			ans += !pm[x][y];
			pm[x][y] = 1;
		}
		if (l + 1 < n) {
			vc.pb(mp(mp(x, y), mp(l + 1, (d + 1) % 8)));
			vc.pb(mp(mp(x, y), mp(l + 1, (d + 7) % 8)));
		}
	}
	printf("%d", ans);


	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim