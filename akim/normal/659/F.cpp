#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

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

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 1110100;

ll a[1010][1010], n, m;
bool pm[1010][1010];
bool ans[1010][1010];
ll snm[maxn], sz[maxn];
pair<ll, pair<ll, ll> > pa[maxn];
ll cnt = 0;

ll getroot(int u) {
	return(u == snm[u] ? u : snm[u] = getroot(snm[u]));
}

void merge(int u, int v) {
	u = getroot(u);
	v = getroot(v);
	if(u == v) return;
	if(rand() & 1) {
		snm[u] = v;
		sz[v] += sz[u];
	} else {
		snm[v] = u;
		sz[u] += sz[v];
	}
}

void dfs(int x, int y) {
	ans[x][y] = 1;
	cnt--;
	if(cnt && x - 1 >= 0 && pm[x - 1][y] && ans[x - 1][y] == 0) {
		dfs(x - 1, y);
	}
	if(cnt && x + 1 < n && pm[x + 1][y] && ans[x + 1][y] == 0) {
		dfs(x + 1, y);
	}
	if(cnt && y - 1 >= 0 && pm[x][y - 1] && ans[x][y - 1] == 0) {
		dfs(x, y - 1);
	}
	if(cnt && y + 1 < m && pm[x][y + 1] && ans[x][y + 1] == 0) {
		dfs(x, y + 1);
	}
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	ll k;
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%lld", &a[i][j]);
			pa[i * m + j] = mp(a[i][j], mp(i, j));
			snm[i * m + j] = i * m + j;
			sz[i * m + j] = 1;
		}
	}
	int all = n * m;
	sort(&pa[0], &pa[all], greater<pair<ll, pair<ll, ll> > >());
	for(int i = 0; i < all; i++) {
		int x = pa[i].sc.fs, y = pa[i].sc.sc;
		pm[x][y] = 1;
		if(x && pm[x - 1][y]) {
			merge(x * m + y, (x - 1) * m + y);
		}
		if(y && pm[x][y - 1]) {
			merge(x * m + y, x * m + (y - 1));
		}
		if(x + 1 < n && pm[x + 1][y]) {
			merge(x * m + y, (x + 1) * m + y);
		}
		if(y + 1 < m && pm[x][y + 1]) {
			merge(x * m + y, x * m + (y + 1));
		}
		int root = getroot(x * m + y);


		if(sz[root] * 1ll * a[x][y] >= k && k % a[x][y] == 0) {
			cnt = k / a[x][y];
			dfs(x, y);

			printf("YES");
			for(int i = 0; i < n; i++) {
				printf("\n");
				for(int j = 0; j < m; j++) {
					printf("%lld ", ans[i][j] ? a[x][y] : 0);
				}
			}

			return(0);
		}
	}

	printf("NO\n");


	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim