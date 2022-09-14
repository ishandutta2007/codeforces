//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
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
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)2e5 + 10;
vector <int> ed[maxn];

int used[2][maxn];

int dfs(int v, int x, int y, int it, int cur) {
	used[it][v] = cur;
	int ans = (v != y ? 1 : 0);

	for (int u : ed[v]) {
		if (used[it][u] == -1 && u != x) {
			ans += dfs(u, x, y, it, cur);
		}
	}

	return ans;
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n, m, a, b;

		scanf("%d %d %d %d", &n, &m, &a, &b);

		for (int i = 1; i <= n; i++) {
			ed[i].clear();
			used[0][i] = used[1][i] = -1;
		}

		for (int i = 0; i < m; i++) {
			int x, y;

			scanf("%d %d", &x, &y);
			ed[x].push_back(y);
			ed[y].push_back(x);
		}

		ll ans = (ll)(n - 2) * (n - 3) / 2;

		int cur = 0;

		for (int i = 1; i <= n; i++) {
			if (i == a) {
				continue;
			}

			if (used[0][i] == -1) {
				int cnt = dfs(i, a, b, 0, cur);
				ans -= (ll)cnt * (cnt - 1) / 2;
				cur++;
			}
		}

		for (int i = 1; i <= n; i++) {
			if (i == b) {
				continue;
			}

			if (used[1][i] == -1) {
				int cnt = dfs(i, b, a, 1, cur);
				ans -= (ll)cnt * (cnt - 1) / 2;
				cur++;
			}
		}

		vector <pii> g;

		for (int i = 1; i <= n; i++) {
			if (i == a || i == b) {
				continue;
			}
				
			g.push_back(mp(used[0][i], used[1][i]));
		}

		sort(g.begin(), g.end());

		int l = 0;

		while (l < (int)g.size()) {
			int r = l;

			while (r < (int)g.size() && g[r] == g[l]) {
				r++;
			}

			int cnt = r - l;
			ans += (ll)cnt * (cnt - 1) / 2;
			l = r;
		}

		printf("%lld\n", ans);
	}

	//system("pause");
}