#include <algorithm>
#include <iostream>
#include <assert.h>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n, m;

vi adj[200500];
int a[200500], tin[200500], tout[200500], now;
int f[2][200500 * 4];
int dp[200500];

void dfs(int x, int z, int p) {
	tin[x] = now++;
	dp[x] = p ^= 1;
	for (int y : adj[x])
		if (y != z) 
			dfs(y, x, p);
	tout[x] = now++;
}

int main() {
    #ifdef LocalHost
    freopen("x.in", "r", stdin);
    #endif
    scanf("%d%d", &n, &m);
	REP (i, n) scanf("%d", a + i);
	FOR (i, 1, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x, --y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(0, -1, 0);
	REP (i, m) {
		int type, x;
		scanf("%d%d", &type, &x);
		--x;
		if (type == 2) {
			ll sum = a[x];
			int p = dp[x];
			for (x = tin[x] + now; x; x /= 2)
				sum += f[p][x] - f[p ^ 1][x];
			cout << sum << endl;
		} else {
			assert(type == 1);
			int val;
			scanf("%d", &val);
			int p = dp[x];
			for (int l = tin[x] + now, r = tout[x] + now; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) {
				if (l & 1) f[p][l] += val;
				if (~r & 1) f[p][r] += val;
			}
		}
	}
    return 0;
}