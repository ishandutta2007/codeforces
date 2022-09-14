#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
#include <list>
#include <numeric>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)2e5 + 10;

ll x[maxn];

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		ll k;
		scanf("%d %lld", &n, &k);

		for (int i = 0; i < n; i++) {
			scanf("%lld", &x[i]);
		}

		if (n == 1) {
			if (x[0] == k) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
			continue;
		}

		sort(x, x + n);

		ll g = 0;

		for (int i = 1; i < n; i++) {
			g = gcd(g, x[i] - x[0]);
		}

		if (abs(k - x[0]) % g == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}