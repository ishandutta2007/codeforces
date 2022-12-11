#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

long long dp[5100][5100];
long long x[5100];

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);

	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%I64d", &x[i]);
		x[i] += x[i - 1];
	}
	for(int i = 1; i <= n; i++) {
		for(int f = 1; f <= k; f++) {
			dp[i][f] = max(dp[i - 1][f], ((i - m >= 0) ? (dp[i - m][f - 1] + x[i] - x[i - m]) : (0)));
			//printf("%I64d ", dp[i][f]);
		}//printf("\n");
	}

	printf("%I64d", dp[n][k]);

	return(0);
}

// by Kim Andrey