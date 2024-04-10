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
ll v[maxn][maxn];
bool used[maxn][maxn];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				used[i][j] = false;
				scanf("%lld", &v[i][j]);
			}
		}

		ll ans = 0;

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!used[i - 1][j]) {
					ans ^= v[i][j];
					for (int it = 0; it < 4; it++) {
						int x = i + dx[it];
						int y = j + dy[it];
						if (0 <= x && x < n && 0 <= y && y < n) {
							used[x][y] = !used[x][y];
						}
					}
				}
			}
		}

		printf("%lld\n", ans);
	}
}