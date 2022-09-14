#pragma comment(linker, "/STACK:1000000000")
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
#include <cstdio>
#include <cassert>
#include <cstring>
#include <unordered_set>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)1e5 + 10;
int v[maxn];
int ans[maxn];

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, q;
		scanf("%d %d", &n, &q);

		multiset<int> s;

		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			v[i] = x;
		}

		int cur = 0;

		for (int i = n - 1; i >= 0; i--) {
			if (v[i] <= cur) {
				ans[i] = 1;
				continue;
			}

			if (cur != q) {
				ans[i] = 1;
				cur++;
				continue;
			}
			ans[i] = 0;
		}

		for (int i = 0; i < n; i++) {
			printf("%d", ans[i]);
		}

		printf("\n");
	}

	return 0;
}