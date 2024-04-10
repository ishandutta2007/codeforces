#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int maxn = 110;
int p[maxn];
int dp[maxn][maxn][3];

int n;

int score(int a, int b) {
	if (a == 2) {
		return 0;
	}

	if (a == b) {
		return 0;
	}

	return 1;
}

int go(int pos, int pre, int a, int b) {
	if (pos == n) {
		return 0;
	}

	if (dp[pos][a][pre] != -1) {
		return dp[pos][a][pre];
	}

	if (p[pos] != 0) {
		return dp[pos][a][pre] = go(pos + 1, p[pos] & 1, a, b) + score(pre, p[pos] & 1);
	}

	int ans = n + 1;

	if (a != 0) {
		ans = min(ans, go(pos + 1, 0, a - 1, b) + score(pre, 0));
	}

	if (b != 0) {
		ans = min(ans, go(pos + 1, 1, a, b - 1) + score(pre, 1));
	}

	return dp[pos][a][pre] = ans;
}

int main() {
	cin >> n;

	set <int> s;

	for (int i = 1; i <= n; i++) {
		s.insert(i);
	}

	for (int i = 0; i < n; i++) {
		cin >> p[i];
		s.erase(p[i]);
	}

	int a = 0, b = 0;

	for (int x : s) {
		if (x & 1) {
			b++;
		}
		else {
			a++;
		}
	}

	memset(dp, -1, sizeof dp);
	cout << go(0, 2, a, b) << '\n';

	return 0;
}