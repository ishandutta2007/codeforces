/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>
#include <unordered_set>
#define ld double
#define mp make_pair
#define ll long long
#define pii pair <int, int>

using namespace std;

const int maxn = 2010;
int v[maxn];
int a[maxn];
ll dp[1010][maxn];

int n, k, r;

ll go(int pos, int p) {
	if (dp[pos][p] != -1) {
		return dp[pos][p];
	}

	if (pos == n) {
		return dp[pos][p] = 0;
	}

	ll ans = max(go(pos + 1, p + 1), (ll)abs(v[pos] - a[p]) + abs(a[p] - r));

	if (n - pos != k - p) {
		ans = min(ans, go(pos, p + 1));
	}

	return dp[pos][p] = ans;
}

int main() {
	cin >> n >> k >> r;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v, v + n);

	for (int i = 0; i < k; i++) {
		scanf("%d", &a[i]);
	}

	sort(a, a + k);

	memset(dp, -1, sizeof dp);

	cout << go(0, 0) << endl;

	return 0;
}