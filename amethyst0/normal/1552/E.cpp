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

const int maxn = 110;
int pos[maxn];

vector <pii> g[maxn];
pii ans[maxn];
int itr[maxn];
bool used[maxn];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	memset(pos, -1, sizeof pos);

	for (int i = 0; i < n * k; i++) {
		int x;
		scanf("%d", &x);
		x--;

		if (pos[x] != -1) {
			g[x].push_back(mp(pos[x], i));
		}

		pos[x] = i;
	}

	k--;
	for (int i = 0; i < n; i += k) {
		int r = min(i + k, n);

		for (int it = 0; it < r - i; it++) {
			int best = -1;

			for (int j = i; j < r; j++) {
				if (used[j]) {
					continue;
				}

				if (best == -1 || g[best][itr[best]].second > g[j][itr[j]].second) {
					best = j;
				}
			}

			assert(best != -1);
			used[best] = true;
			ans[best] = g[best][itr[best]];

			for (int j = i; j < r; j++) {
				if (g[j][itr[j]].first < g[best][itr[best]].second) {
					itr[j]++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	}
}