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

char c[55][55];
bool pm[55][55];
int cnt;

int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

void dfs(int x, int y) {
	pm[x][y] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && c[xx][yy] == '.' && pm[xx][yy] == 0) {
			dfs(xx, yy);
		}
	}
}

void rem(int x, int y) {
	c[x][y] = '*';
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && c[xx][yy] == '.') {
			rem(xx, yy);
		}
	}
}

int solve() {

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("\n");
		for (int j = 0; j < m; j++) {
			c[i][j] = getchar();
		}
	}

	for (int i = 0; i < n; i++) {
		if (c[i][0] == '.')
			dfs(i, 0);
		if (c[i][m - 1] == '.')
			dfs(i, m - 1);
	}
	for (int i = 0; i < m; i++) {
		if (c[0][i] == '.')
			dfs(0, i);
		if (c[n - 1][i] == '.')
			dfs(n - 1, i);
	}

	vector<pair<int, pair<int, int> >> vc;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!pm[i][j] && c[i][j] == '.') {
				cnt = 0;
				dfs(i, j);
				vc.pb(mp(cnt, mp(i, j)));
			}
		}
	}
	sort(vc.begin(), vc.end());
	int ans = 0;
	for (int i = 0; i < (int) vc.size() - k; i++) {
		rem(vc[i].sc.fs, vc[i].sc.sc);
		ans += vc[i].fs;
	}

	printf("%d\n", ans);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c", c[i][j]);
		}
		printf("\n");
	}

	return (0);
}

// by Andrey Kim