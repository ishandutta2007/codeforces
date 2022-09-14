#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


struct Card {
	int c;
	int a;
	int b;
};

const int MAXN = 16;


int dp[1 << MAXN][MAXN * MAXN + 1];

const int INF = 200;

int main() {
	int n;
	cin >> n;

	vector<Card> cards(n);

	int x = 0;

	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		cards[i].c = (c == 'R' ? 0 : 1);
		cin >> cards[i].a >> cards[i].b;
		x += cards[i].c;
	}

	for (int i = 0; i < (1 << n); ++i) {
		for (int k = 0; k <= n * n; ++k) {
			dp[i][k] = -1;
		}
	}

	dp[0][0] = 0;

	for (int i = 0; i < (1 << n) - 1; ++i) {
		int u = __builtin_popcount(i);

		int p = 0;
		int q = 0;

		for (int l = 0; l < n; ++l) {
			if (!(i & (1 << l)))
				continue;
			if (cards[l].c)
				++q;
			else 
				++p;
		}

		for (int k = 0; k <= n * n; ++k) {
			if (dp[i][k] == -1)
				continue;

			for (int l = 0; l < n; ++l) {
				if (i & (1 << l))
					continue;


				int x = i | (1 << l);
				int z = dp[i][k] + min(cards[l].a, p);
				int t = k + min(cards[l].b, q);

				dp[x][t] = max(dp[x][t], z);
			}
		}
	}

	int u = 0;
	int v = 0;
	for (int i = 0; i < n; ++i) {
		u += cards[i].a;
		v += cards[i].b;
	}

	int p = (1 << n) - 1;

	int ans = 1e9;

	for (int k = 0; k <= n * n; ++k) {
		if (dp[p][k] == -1)
			continue;

		int x = dp[p][k];
		int y = k;

		ans = min(ans, max(u - x, v - y));
	}

	ans += n;
	cout << ans << endl;


	return 0;
}