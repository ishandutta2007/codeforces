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
#include <cstdio>
#include <cassert>
#include <cstring>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = 1010;

pii v[maxn];
bool used[maxn];

int ins(int l, int r, int m) {
	return l < m && m < r;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(used, 0, sizeof used);
		int n, k;
		scanf("%d %d", &n, &k);

		for (int i = 0; i < k; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			if (x > y) {
				swap(x, y);
			}
			x--;
			y--;
			used[x] = used[y] = true;
			v[i] = mp(x, y);
		}

		vector <int> a;

		for (int i = 0; i < 2 * n; i++) {
			if (!used[i]) {
				a.push_back(i);
			}
		}

		for (int i = 0; i < n - k; i++) {
			v[k + i] = mp(a[i], a[i + n - k]);
		}

		int ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (ins(v[i].first, v[i].second, v[j].first) + ins(v[i].first, v[i].second, v[j].second) == 1) {
					ans++;
				}
			}
		}

		printf("%d\n", ans);
	}
}