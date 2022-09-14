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

const int maxn = 510, mod = 998244353;

int dp[maxn][maxn];
int v[maxn];
int n, m;

int go(int l, int r) {
	if (l > r) {
		return 1;
	}

	if (dp[l][r] != -1) {
		return dp[l][r];
	}

	int p = l;

	for (int i = l + 1; i <= r; i++) {
		if (v[i] < v[p]) {
			p = i;
		}
	}

	int s = 0;
	int t = 0;

	for (int i = p; i >= l; i--) {
		s = (s + (ll)go(l, i - 1) * go(i, p - 1)) % mod;
	}

	for (int i = p; i <= r; i++) {
		t = (t + (ll)go(p + 1, i) * go(i + 1, r)) % mod;
	}

	return dp[l][r] = (ll)s * t % mod;
}

int main() {
	memset(dp, -1, sizeof dp);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	cout << go(0, m - 1) << endl;

	//system("pause");
}