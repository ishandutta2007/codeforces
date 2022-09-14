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

const int maxn = 1e5 + 10;
int v[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);

		ll tot = 0;
		ll ans = 0;
		bool bad = true;

		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);

			if (i == 0 || i == n - 1) {
				continue;
			}

			if (v[i] != 1) {
				bad = false;
			}

			tot += v[i];
			ans += (v[i] + 1) / 2;
		}

		if (bad || (tot % 2 == 1 && n == 3)) {
			printf("-1\n");
		}
		else {
			printf("%lld\n", ans);
		}
	}
}