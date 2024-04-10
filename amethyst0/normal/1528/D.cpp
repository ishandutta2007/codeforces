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

const int maxn = 610;
int ed[maxn][maxn];

int n;
int dst[maxn];
bool used[maxn];
const int inf = (int)1e9 + maxn;

int red[maxn];

void solve(int v) {
	for (int i = 0; i < n; i++) {
		dst[i] = inf;
		used[i] = false;
	}

	dst[v] = 0;

	for (int it = 0; it < n - 1; it++) {
		int v = -1;
		for (int i = 0; i < n; i++) {
			red[i] = inf;
			if (!used[i] && (v == -1 || dst[v] > dst[i])) {
				v = i;
			}
		}

		int t = dst[v] % n;
		used[v] = true;
		int pos = t;
		int cost = inf;

		int j = 0;

		for (int i = 0; i < 2 * n; i++) {
			cost = min(cost, ed[v][j]);
			red[pos] = min(red[pos], cost);

			pos++;
			cost++;
			if (pos == n) {
				pos = 0;
			}

			j++;
			if (j == n) {
				j = 0;
			}
		} 

		for (int i = 0; i < n; i++) {
			dst[i] = min(dst[i], dst[v] + red[i]);
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", dst[i]);
	}
	printf("\n");
}

int main() {
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ed[i][j] = inf;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		ed[x][y] = w;
	}

	for (int i = 0; i < n; i++) {
		solve(i);
	}
}