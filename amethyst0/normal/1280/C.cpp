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
vector <pii> ed[maxn];
int sz[maxn];

ll tot;

ll dfs1(int v, int p, ll d) {
	tot += d;
	ll ans = 0;
	sz[v] = 1;

	int cnt = 1;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].first;
		int w = ed[v][i].second;
		if (u == p) {
			continue;
		}

		ans += dfs1(u, v, d + w);
		sz[v] += sz[u];

		cnt += sz[u] & 1;
		if (cnt == 2) {
			ans += d;
			cnt = 0;
		}
	}

	return ans;
}

ll dfs2(int v, int p, ll d, int cnt) {
	vector <pii> g;
	
	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].first;

		if (u != p) {
			g.push_back(mp(sz[u], u));
		}
	}

	g.push_back(mp(1, -1));
	sort(g.begin(), g.end());

	int cur = g.back().first;

	int sum = 0;

	for (int i = 0; i < (int)g.size() - 1; i++) {
		sum += g[i].first;
	}

	ll ans = 0;

	if (cur > sum + cnt) {
		cur -= cnt;
		ans += (ll)sum * d;
		for (int i = 0; i < (int)ed[v].size(); i++) {
			int u = ed[v][i].first;

			if (u == g.back().second) {
				ans += dfs2(u, v, d + ed[v][i].second, cnt + sum);
			}
		}
	}
	else {
		cur = (sum + cur - cnt) / 2;
		ans += (ll)cur * d;
	}

	return ans;
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		tot = 0;
		int k;

		scanf("%d", &k);

		for (int i = 1; i <= 2 * k; i++) {
			ed[i].clear();
		}

		for (int i = 0; i < 2 * k - 1; i++) {
			int x, y, t;

			scanf("%d %d %d", &x, &y, &t);
			ed[x].push_back(mp(y, t));
			ed[y].push_back(mp(x, t));
		}

		ll a = dfs1(1, -1, 0);
		ll b = dfs2(1, -1, 0, 0);

		printf("%lld %lld\n", tot - 2 * a, tot - 2 * b);
	}

	//system("pause");
}