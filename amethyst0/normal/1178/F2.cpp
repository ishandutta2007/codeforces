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

const int maxn = 510, maxm = (int)1e6 + 10, mod = 998244353;
int n, m;
int v[maxm];
int l[maxn];
int r[maxn];
int dp[maxn][maxn];

int t[4 * maxm];

void build(int it, int l, int r) {
	if (l == r) {
		t[it] = v[l];
	}
	else {
		int m = (l + r) >> 1;

		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);
		t[it] = min(t[2 * it], t[2 * it + 1]);
	}
}

int go(int it, int l, int r, int lm, int rm) {
	if (l == lm && r == rm) {
		return t[it];
	}
	else {
		int m = (l + r) >> 1;

		if (rm <= m) {
			return go(2 * it, l, m, lm, rm);
		}
		else if (lm > m) {
			return go(2 * it + 1, m + 1, r, lm, rm);
		}
		else {
			return min(go(2 * it, l, m, lm, m), go(2 * it + 1, m + 1, r, m + 1, rm));
		}
	}
}

vector <int> ps[maxn];

int go(int left, int right) {
	if (left > right) {
		return 1;
	}

	int lc = v[left];
	int rc = v[right];

	if (left != l[lc] || right != r[rc]) {
		return 0;
	}

	if (dp[lc][rc] != -1) {
		return dp[lc][rc];
	}

	int lm = l[lc];
	int rm = r[rc];

	int cur = go(1, 0, m - 1, lm, rm);

	for (int i = cur; i <= n; i++) {
		int li = l[i];
		int ri = r[i];

		if (li > rm) {
			continue;
		}

		if (ri < lm) {
			continue;
		}

		if (!(lm <= li && ri <= rm)) {
			return dp[lc][rc] = 0;
		}
	}

	int s = 0;
	int t = 0;

	int ans = 1;

	for (int i = 0; i < (int)ps[cur].size() - 1; i++) {
		int li = ps[cur][i] + 1;
		int ri = ps[cur][i + 1] - 1;

		if (li <= ri) {
			ans = (ll)ans * go(li, ri) % mod;
		}
	}

	int lcur = l[cur];
	int rcur = r[cur];

	if (ans == 0) {
		return dp[lc][rc] = 0;
	}

	if (lcur == lm) {
		s = 1;
	}
	else {
		s = go(lm, lcur - 1);
		for (int i = 1; i <= n; i++) {
			int li = l[i];
			int ri = r[i];

			if (li < lcur && li >= lm) {
				s = (s + (ll)go(li, lcur - 1) * go(lm, li - 1)) % mod;
			}
		}
	}

	if (rm == rcur) {
		t = 1;
	}
	else {
		t = go(rcur + 1, rm);
		for (int i = 1; i <= n; i++) {
			int li = l[i];
			int ri = r[i];

			if (ri > rcur && ri <= rm) {
				t = (t + (ll)go(rcur + 1, ri) * go(ri + 1, rm)) % mod;
			}
		}
	}

	return dp[lc][rc] = (((ll)ans * s) % mod) * t % mod;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		scanf("%d", &v[i]);
	}

	memset(l, -1, sizeof l);

	for (int i = 0; i < m; i++) {
		ps[v[i]].push_back(i);
		if (l[v[i]] == -1) {
			l[v[i]] = i;
		}

		r[v[i]] = i;
	}

	build(1, 0, m - 1);

	memset(dp, -1, sizeof dp);

	cout << go(0, m - 1) << endl;

	//system("pause");
}