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
int v[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}

		ll ans = 0;

		for (int i = 0; i < n; i++) {
			int tot = 0;

			for (int j = i; j < n; j++) {
				if (v[j] == 0) {
					tot++;
				}
				ans += j - i + 1 + tot;
			}
		}

		printf("%lld\n", ans);
	}
}