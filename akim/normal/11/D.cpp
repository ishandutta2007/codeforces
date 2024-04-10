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
const int maxn = 100100;

int ms[20][20];
ll dp[(1 << 20)][20];

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

	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		ms[u][v] = ms[v][u] = 1;
	}

	for(int i = 0; i < n; i++) {
		dp[1 << i][i] = 1;
	}

	ll ans = 0;
	for(int mask = 0; mask < (1 << n); mask++) {
		for(int i = 0, beg = -1; i < n; i++) {
			if(!(mask & (1 << i))) continue;
			if(beg == -1) {
				beg = i;
			}
			if(ms[beg][i]) {
				ans += dp[mask][i];
			}
			for(int j = beg; j < n; j++) {
				if((mask & (1 << j))) continue;
				if(ms[i][j]) {
					dp[mask | (1 << j)][j] += dp[mask][i];
				}
			}
		}
//		cout << mask << " " << dp[mask][0] << " " << dp[mask][1] << " " << dp[mask][2] << endl;
	}

	cout << (ans - m) / 2;

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