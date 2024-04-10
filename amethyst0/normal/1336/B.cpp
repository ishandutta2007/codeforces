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
#include <unordered_map>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int maxn = (int)1e5 + 10;
vector <int> g[3];
int n[3];

ll sqr(int x) {
	return (ll)x * x;
}

ll go(int a, int b, int c) {
	int pb = 0;
	int pc = 0;

	ll ans = (ll)4e18;

	for (int i = 0; i < n[a]; i++) {
		while (pb < n[b] - 1 && g[b][pb + 1] <= g[a][i]) {
			pb++;
		}

		while (pc < n[c] && g[c][pc] < g[a][i]) {
			pc++;
		}

		if (pc == n[c]) {
			break;
		}

		ans = min(ans, sqr(g[a][i] - g[b][pb]) + sqr(g[a][i] - g[c][pc]) + sqr(g[c][pc] - g[b][pb]));
	}

	return ans;
}

int main() {
	int t;

	cin >> t;
	while (t--) {
		for (int i = 0; i < 3; i++) {
			scanf("%d", &n[i]);
		}

		for (int i = 0; i < 3; i++) {
			g[i].resize(n[i]);

			for (int j = 0; j < n[i]; j++) {
				scanf("%d", &g[i][j]);
			}

			sort(all(g[i]));
		}

		ll ans = go(0, 1, 2);
		ans = min(ans, go(0, 2, 1));
		ans = min(ans, go(1, 0, 2));
		ans = min(ans, go(1, 2, 0));
		ans = min(ans, go(2, 0, 1));
		ans = min(ans, go(2, 1, 0));

		printf("%lld\n", ans);
	}
}