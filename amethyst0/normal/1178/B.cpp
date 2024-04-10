#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)1e6 + 10;
char s[maxn];
int n;

ll dp[maxn][4];

ll go(int p, int t) {
	if (dp[p][t] != -1) {
		return dp[p][t];
	}

	if (t == 3) {
		return dp[p][t] = 1;
	}

	if (p == n) {
		return dp[p][t] = 0;
	}

	ll ans = go(p + 1, t);

	if (t == 1) {
		if (s[p] == 'o') {
			ans += go(p + 1, t + 1);
		}
	}
	else {
		if (p < n - 1 && s[p] == 'v' && s[p + 1] == 'v') {
			ans += go(p + 2, t + 1);
		}
	}

	return dp[p][t] = ans;
}

int main() {
	scanf("%s", s);

	n = strlen(s);

	memset(dp, -1, sizeof dp);

	cout << go(0, 0) << endl;

	//system("pause");
}