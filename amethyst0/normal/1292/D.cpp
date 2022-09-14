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
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int maxn = (int)5001;
int d[maxn];
int cnt[maxn];
vector <int> g[maxn];
int gr[maxn];
ll dst[maxn];

int sum[maxn][maxn];

int ps[maxn];

int tot[maxn];
int cur[maxn];

int main() {
	d[1] = 1;

	for (int i = 2; i < maxn; i++) {
		for (int j = i; j < maxn; j += i) {
			if (d[j] == 0) {
				d[j] = i;
			}
		}
	}

	cnt[1] = 0;
	int s = 0;

	for (int i = 2; i < maxn; i++) {
		int x = i;

		while (x != 1) {
			g[i].push_back(d[x]);
			x /= d[x];
		}

		gr[i] = g[i].back();
	}

	dst[1] = 0;

	for (int i = 2; i < maxn; i++) {
		dst[i] = dst[i - 1] + (int)g[i].size();
	}

	for (int i = 2; i < maxn; i++) {
		for (int j = 2; j <= i; j++) {
			for (int x : g[j]) {
				sum[i][x]++;
			}

			ps[i] = max(ps[i], gr[j]);
		}
	}

	int n;

	scanf("%d", &n);

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x == 0 || x == 1) {
			x = 1;
		}

		ans += dst[x];
		cnt[x]++;
	}

	while (true) {
		memset(tot, 0, sizeof tot);

		for (int i = 1; i < maxn; i++) {
			if (cnt[i] == 0 || ps[i] == 0) {
				continue;
			}

			tot[ps[i]] += cnt[i];
			sum[i][ps[i]]--;
			cur[i] = ps[i];

			while (ps[i] > 0 && sum[i][ps[i]] == 0) {
				ps[i]--;
			}
		}

		bool ok = false;
		int x = -1;

		for (int i = 1; i < maxn; i++) {
			if (tot[i] * 2 > n) {
				ans -= tot[i] * 2 - n;
				x = i;
				ok = true;
			}
		}

		if (!ok) {
			break;
		}

		for (int i = 1; i < maxn; i++) {
			if (cur[i] != x) {
				cnt[i] = 0;
			}
		}
	}

	cout << ans << endl;
}