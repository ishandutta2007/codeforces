//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <cstdio>
#include <cassert>
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

const int maxn = 110;
int a[maxn], b[maxn];
const int maxm = maxn * maxn;
bitset<maxm> g;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		g.reset();

		ll ans = 0;
		ll tot = 0;

		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			ans += (n - 2) * a[i] * a[i];
			tot += a[i];
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &b[i]);
			ans += (n - 2) * b[i] * b[i];
			tot += b[i];
		}

		if (n == 1) {
			printf("0\n");
			continue;
		}

		g[0] = 1;

		for (int i = 0; i < n; i++) {
			g = (g << a[i]) | (g << b[i]);
		}

		ll best = (ll)1e18;

		for (int i = 0; i < maxm; i++) {
			if (g[i]) {
				best = min(best, (ll)i * i + (ll)(tot - i) * (tot - i));
			}
		}

		printf("%lld\n", ans + best);
	}
}