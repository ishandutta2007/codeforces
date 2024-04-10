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
#include <array>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int

const int maxn = (int)2e5 + 10, inf = (int)1e9;

int pr[maxn];
pii g[maxn];
int tot[maxn];

int main() {
	for (int i = 2; i < maxn; i++) {
		if (!pr[i]) {
			pr[i] = i;

			for (int j = 2 * i; j < maxn; j += i) {
				pr[j] = max(pr[j], i);
			}
		}
	}

	int n;

	cin >> n;

	for (int i = 0; i < maxn; i++) {
		g[i] = mp(inf, inf);
	}

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);

		while (x != 1) {
			int y = pr[x];
			int cnt = 0;

			while (x % y == 0) {
				cnt++;
				x /= y;
			}

			if (g[y].first > cnt) {
				g[y].second = g[y].first;
				g[y].first = cnt;
			}
			else if (g[y].second > cnt) {
				g[y].second = cnt;
			}

			tot[y]++;
		}
	}

	ll ans = 1;

	for (int i = 0; i < maxn; i++) {
		if (tot[i] <= n - 2) {
			continue;
		}

		if (tot[i] == n - 1) {
			while (g[i].first--) {
				ans *= i;
			}

			continue;
		}

		while (g[i].second--) {
			ans *= i;
		}
	}

	cout << ans << '\n';
}