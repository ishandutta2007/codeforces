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
#include <limits.h>
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
#define ld double
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e6 + 10;
int v[maxn];

int gcd(int x, int y) {
	if (x < y) {
		swap(x, y);
	}
	
	if (y == 0) {
		return x;
	}
	
	return gcd(y, x % y);
}

ll go(int n, int pos, int d) {
	ll sum = 0;
	ll best = (ll)1e18;
	
	int tot = 0;
	
	for (int i = pos; i < n; i += d) {
		sum += abs(v[i]);
		best = min(best, (ll)abs(v[i]));
		if (v[i] < 0) {
			tot ^= 1;
		}
	}
	
	if (tot == 1) {
		return sum - 2 * best;
	}
	
	return sum;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}
		int g = 0;
		for (int i = 0; i < m; i++) {
			int x;
			scanf("%d", &x);
			g = gcd(g, x);
		}
		
		if (g == 1) {
			ll ans = 0;
			for (int i = 0; i < n; i++) {
				ans += abs(v[i]);
			}
			printf("%lld\n", ans);
			continue;
		}
		
		ll ans = -(ll)1e18;
		
		for (int it = 0; it < 2; it++) {
			for (int i = 0; i < g; i++) {
				v[i] *= -1;
			}
			
			ll sum = 0;
			
			for (int i = 0; i < g; i++) {
				sum += go(n, i, g);
			}
			
			ans = max(ans, sum);
		}
		
		printf("%lld\n", ans);
	}
}