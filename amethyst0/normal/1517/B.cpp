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

const int maxn = 110;
int v[maxn][maxn];
bool used[maxn][maxn];
int pos[maxn];
int res[maxn][maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector <pii> a;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &v[i][j]);
				used[i][j] = false;
				a.push_back(mp(i, j));
			}
			pos[i] = 0;
		}

		sort(all(a), [&](pii x, pii y) {
			return v[x.first][x.second] < v[y.first][y.second];
		});

		for (int i = 0; i < m; i++) {
			used[a[i].first][a[i].second] = true;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (j == a[i].first) {
					res[j][i] = v[a[i].first][a[i].second];
					continue;
				}

				while (pos[j] < m && used[j][pos[j]]) {
					pos[j]++;
				}

				used[j][pos[j]] = true;

				res[j][i] = v[j][pos[j]];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", res[i][j]);
			}
			printf("\n");
		}
	}
}