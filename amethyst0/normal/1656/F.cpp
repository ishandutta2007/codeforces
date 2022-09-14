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

const int maxn = (int)2e5 + 10;
int a[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		
		ll sum = 0;
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		
		sort(a, a + n);
		if (sum + (ll)(n - 2) * a[0] > 0) {
			printf("INF\n");
			continue;
		}
		
		if (sum + (ll)(n - 2) * a[n - 1] < 0) {
			printf("INF\n");
			continue;
		}
		
		vector<int> ts;
		
		for (int i = 1; i < n - 1; i++) {
			ts.push_back(-a[i]);
		}
		
		sort(all(ts));
		
		ll cur = 0;
		for (int i = 0; i < n - 1; i++) {
			cur += (ll)a[i] * a[n - 1];
		}
		
		ll ans = -(ll)8e18;
		
		if (n == 2) {
			ans = cur;
		}
		
		for (int i = 0; i < (int)ts.size(); i++) {
			ans = max(ans, cur + sum * ts[i] + (ll)i * a[0] * ts[i] + (ll)(n - 2 - i) * a[n - 1] * ts[i]);
			cur -= (ll)-ts[i] * a[n - 1];
			cur += (ll)-ts[i] * a[0];
		}
		
		printf("%lld\n", ans);
	}
}