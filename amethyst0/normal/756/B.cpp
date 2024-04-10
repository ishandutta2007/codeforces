/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <unordered_map>
#include <random>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10;

int dp[maxn];
int t[maxn];

int main() {
	int n;

	cin >> n;

	dp[0] = 0;
	t[0] = -1000000;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);

		dp[i] = dp[i - 1] + 20;

		int pos = upper_bound(t, t + i, t[i] - 90) - t - 1;
		dp[i] = min(dp[i], dp[pos] + 50);

		pos = upper_bound(t, t + i, t[i] - 1440) - t - 1;
		dp[i] = min(dp[i], dp[pos] + 120);

		printf("%d\n", dp[i] - dp[i - 1]);
	}

	return 0;
}