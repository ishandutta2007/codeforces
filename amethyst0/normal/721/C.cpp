/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <numeric>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define ui unsigned int
#define ld double
#define pll pair <ll, ll> 

using namespace std;

const int maxn = 5010;
vector <pii> ed[maxn];
int dst[maxn][maxn];
short int lnk[maxn][maxn];

const int inf = (int)1e9 + 10;

void write(int pos, int cnt) {
	if (pos != 1) {
		write(lnk[pos][cnt], cnt - 1);
	}

	printf("%d ", pos);
}

int main() {
	int n, m, t;

	cin >> n >> m >> t;

	for (int i = 0; i < m; i++) {
		int x, y, w;

		scanf("%d %d %d", &x, &y, &w);

		ed[x].push_back(mp(y, w));
	}

	memset(dst, -1, sizeof dst);
	dst[1][1] = 0;

	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			if (dst[i][j] == -1) {
				continue;
			}

			for (int k = 0; k < (int)ed[i].size(); k++) {
				int u = ed[i][k].first;
				int w = ed[i][k].second;

				if (dst[u][j + 1] == -1 || dst[u][j + 1] > dst[i][j] + w) {
					dst[u][j + 1] = dst[i][j] + w;
					lnk[u][j + 1] = i;
					if (dst[u][j + 1] > inf) {
						dst[u][j + 1] = inf;
					}
				}
			}
		}
	}

	int cnt = 0;

	for (int i = n; i >= 1; i--) {
		if (dst[n][i] <= t && dst[n][i] != -1) {
			cnt = i;
			break;
		}
	}

	int pos = n;

	cout << cnt << endl;

	write(pos, cnt);

	return 0;
}