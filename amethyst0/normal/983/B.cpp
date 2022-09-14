#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>
#include <ctime>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
#define mp make_pair

const int maxn = (int)5e3 + 10;
int v[maxn];

int dp[maxn][maxn];

int go(int pos, int cnt) {
	if (dp[pos][cnt] != -1) {
		return dp[pos][cnt];
	}

	if (cnt == 0) {
		return dp[pos][cnt] = v[pos];
	}

	return dp[pos][cnt] = go(pos, cnt - 1) ^ go(pos + 1, cnt - 1);
}

int res[maxn][maxn];

int gores(int l, int r) {
	if (res[l][r] != -1) {
		return res[l][r];
	}

	if (l == r) {
		return res[l][r] = dp[l][r - l];
	}

	return res[l][r] = max(max(dp[l][r - l], gores(l, r - 1)), gores(l + 1, r));
}

int main() {
	memset(dp, -1, sizeof dp);
	memset(res, -1, sizeof res);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	for (int cnt = 0; cnt < n; cnt++) {
		for (int i = 0; i < n - cnt; i++) {
			go(i, cnt);
		}
	}

	for (int cnt = 0; cnt < n; cnt++) {
		for (int i = 0; i < n - cnt; i++) {
			gores(i, i + cnt);
		}
	}

	int q;

	cin >> q;

	while (q--) {
		int l, r;

		cin >> l >> r;
		l--;
		r--;

		printf("%d\n", res[l][r]);
	}

	//system("pause");
}