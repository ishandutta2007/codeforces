//#pragma comment(linker, "/STACK:1000000000")
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
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld long double

using namespace std;

const int maxn = 12, maxm = 2010;
int dp[2][1 << maxn];
int v[maxn][maxm];
int val[1 << maxn];
int cur[1 << maxn];
int fir[1 << maxn];

int main() {
	for (int i = 1; i < (1 << maxn); i++) {
		if (i & 1) {
			fir[i] = 0;
		}
		else {
			fir[i] = fir[i >> 1] + 1;
		}
	}

	int t;

	//t = 40;
	cin >> t;

	while (t--) {
		int n, m;

		cin >> n >> m;
		//n = 12;
		//m = 2000;

		vector <pii> g;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &v[i][j]);
				//v[i][j] = rand();
				g.push_back(mp(v[i][j], j));
			}
		}

		for (int i = 0; i < (1 << n); i++) {
			dp[0][i] = 0;
			dp[1][i] = 0;
		}

		sort(g.begin(), g.end());

		set <int> best;

		for (int i = (int)g.size() - 1; i >= 0; i--) {
			best.insert(g[i].second);
			if ((int)best.size() == n) {
				break;
			}
		}

		int it = 0;

		for (int j = 0; j < m; j++) {
			if (!best.count(j)) {
				continue;
			}

			for (int i = 0; i < (1 << n); i++) {
				val[i] = 0;
				dp[it ^ 1][i] = dp[it][i];
			}

			for (int i = 0; i < n; i++) {
				for (int ms = 1; ms < (1 << n); ms++) {
					int p = fir[ms];
					int ps = i + p;
					if (ps >= n) {
						ps -= n;
					}

					cur[ms] = cur[ms ^ (1 << p)] + v[ps][j];
					val[ms] = max(val[ms], cur[ms]);
				}
			}

			for (int ms = 0; ms < (1 << n); ms++) {
				for (int msk = ms; msk > 0; msk = (msk - 1) & ms) {
					dp[it ^ 1][ms ^ msk] = max(dp[it ^ 1][ms ^ msk], dp[it][ms] + val[msk]);
				}
			}

			it ^= 1;
		}

		cout << dp[it][0] << endl;
	}

	//system("pause");
}