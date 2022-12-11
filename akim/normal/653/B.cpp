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

char c1[maxn], c2[maxn], c3[maxn];

int dp[maxn][32];

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

	int n, q;
	scanf("%d%d", &n, &q);

	dp[0][0] = 1;
	for(int i = 0; i < q; i++) {
		scanf("\n%c%c %c", &c1[i], &c2[i], &c3[i]);
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 6; j++) {
			for(int k = 0; k < q; k++) {
				if(c3[k] - 'a' != j) continue;
				dp[i + 1][c1[k] - 'a'] += dp[i][j];
			}
//			printf("%d ", dp[i][j]);
		}
//		printf("\n");
	}

	int ans = 0;
	for(int i = 0; i < 6; i++) {
		ans += dp[n - 1][i];
	}
	printf("%d", ans);


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