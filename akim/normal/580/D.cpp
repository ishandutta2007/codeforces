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

ll dp[3 * maxn][20];
bool pm[3 * maxn][20];
ll a[maxn];
ll ms[20][20];

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
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

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; i++) {
		scanf("%I64d", &a[i]);
	}
	for(; k > 0; k--) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		u--, v--;
		ms[u][v] = c;
	}

	ll ans = 0;

	pm[0][n] = 1;

	for(int i = 0; i < (1 << n); i++) {
		for(int f = 0; f <= n; f++) {
			if(!pm[i][f]) continue;
			for(int g = 0; g < n; g++) {
				if(i & (1 << g)) continue;
				int mask = i | (1 << g);
				pm[mask][g] = 1;
				dp[mask][g] = max(dp[mask][g], dp[i][f] + a[g] + ms[f][g]);
				if(__builtin_popcount(mask) == m) ans = max(dp[mask][g], ans);
			}
		}
	}

	printf("%I64d", ans);

	return(0);
}

// by Kim Andrey