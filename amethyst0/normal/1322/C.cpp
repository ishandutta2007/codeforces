#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

const int maxn = (int)5e5 + 10;
int t;
ll v[maxn];
vector <int> g[maxn];

int main() {
	cin >> t;

	while (t--) {
		int n, m;

		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++) {
			scanf("%lld", &v[i]);
		}

		for (int i = 0; i < n; i++) {
			g[i].clear();
		}

		for (int i = 0; i < m; i++) {
			int x, y;

			scanf("%d %d", &x, &y);
			x--;
			y--;
			g[y].push_back(x);
		}

		vector <int> p;

		for (int i = 0; i < n; i++) {
			if (!g[i].empty()) {
				sort(all(g[i]));
				p.push_back(i);
			}
		}

		sort(all(p), [&](int a, int b) {
			return g[a] < g[b];
		});

		int l = 0;

		ll ans = 0;

		while (l < (int)p.size()) {
			int r = l;

			ll sum = 0;

			while (r < (int)p.size() && g[p[l]] == g[p[r]]) {
				sum += v[p[r]];
				r++;
			}

			ans = gcd(ans, sum);
			l = r;
		}

		printf("%lld\n", ans);
	}
}