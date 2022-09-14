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
#include <fstream>
#include <bitset>
#include <cstring>
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int maxn = (int)1e5 + 10;
ll v[maxn];

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n;
		ll x;

		scanf("%d %lld", &n, &x);

		for (int i = 0; i < n; i++) {
			scanf("%lld", &v[i]);
		}

		sort(v, v + n);

		ll ans = -1;

		for (int i = 0; i < n; i++) {
			if (v[i] == x) {
				ans = 1;
			}
		}

		if (ans != 1) {
			ans = (x + v[n - 1] - 1) / v[n - 1];
			ans = max(ans, 2ll);
		}

		printf("%lld\n", ans);
	}
	
	return 0;
}