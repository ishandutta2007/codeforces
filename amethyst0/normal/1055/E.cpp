#pragma comment(linker, "/STACK:1000000000")
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
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>

using namespace std;

const int maxn = 1510;

int v[maxn];
pii f[maxn];
int sums[maxn];

int lnk[maxn];

bool cmp(pii a, pii b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}

	return a.second > b.second;
}

int get_sum(int l, int r) {
	return (l == 0 ? sums[r] : sums[r] - sums[l - 1]);
}

int dp[maxn][maxn];

int n;

int go(int l, int cnt) {
	if (dp[l][cnt] != -1) {
		return dp[l][cnt];
	}

	if (cnt == 0 || l == n) {
		return dp[l][cnt] = 0;
	}

	int ans = go(l + 1, cnt);

	int it = lnk[l];

	if (it != -1) {
		if (f[it].second >= l) {
			ans = max(ans, go(f[it].second + 1, cnt - 1) + get_sum(l, f[it].second));
		}
	}

	return dp[l][cnt] = ans;
}

int main() {
	int s, m, k;

	cin >> n >> s >> m >> k;

	vector <int> g;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		g.push_back(v[i]);
	}

	for (int i = 0; i < s; i++) {
		scanf("%d %d", &f[i].first, &f[i].second);
		f[i].first--;
		f[i].second--;
	}

	sort(f, f + s, cmp);

	int rm = -1;
	int pos = 0;

	for (int i = 0; i < s; i++) {
		if (f[i].second <= rm) {
			continue;
		}

		f[pos++] = f[i];
		rm = f[i].second;
	}

	s = pos;

	for (int i = 0; i < n; i++) {
		int it = lower_bound(f, f + s, mp(i + 1, -1)) - f;
		it--;

		lnk[i] = it;
	}

	sort(g.begin(), g.end());
	g.resize(unique(g.begin(), g.end()) - g.begin());

	int l = 0, r = (int)g.size();

	while (l != r) {
		int md = (l + r) >> 1;

		int now = 0;

		for (int i = 0; i < n; i++) {
			if (v[i] <= g[md]) {
				now++;
			}

			sums[i] = now;
		}

		memset(dp, -1, sizeof dp);

		int x = go(0, m);

		if (x >= k) {
			r = md;
		}
		else {
			l = md + 1;
		}
	}

	if (l == (int)g.size()) {
		cout << -1 << endl;
	}
	else {
		cout << g[l] << endl;
	}

	//system("pause");
}