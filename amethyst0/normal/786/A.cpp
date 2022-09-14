/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair

using namespace std;

const int maxn = (int)7010;

int k[2];
int v[2][maxn];
int ans[2][maxn];
int cnt[2][maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < 2; i++) {
		scanf("%d", &k[i]);

		for (int j = 0; j < k[i]; j++) {
			scanf("%d", &v[i][j]);
		}
	}

	memset(ans, -1, sizeof ans);

	for (int i = 0; i < n; i++) {
		cnt[0][i] = k[0];
		cnt[1][i] = k[1];
	}

	ans[0][0] = 0;
	ans[1][0] = 0;

	queue <pii> q;

	q.push(mp(0, 0));
	q.push(mp(1, 0));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < k[x ^ 1]; i++) {
			int s = y - v[x ^ 1][i];

			if (s < 0) {
				s += n;
			}

			if (ans[x ^ 1][s] == -1) {
				if (ans[x][y] == 0) {
					ans[x ^ 1][s] = 1;
					q.push(mp(x ^ 1, s));
				} else {
					cnt[x ^ 1][s]--;
					if (cnt[x ^ 1][s] == 0) {
						ans[x ^ 1][s] = 0;
						q.push(mp(x ^ 1, s));
					}
				}
			}
		}
	}

	for (int i = 1; i < n; i++) {
		if (ans[0][i] == -1) {
			printf("Loop ");
		} else if (ans[0][i] == 0) {
			printf("Lose ");
		} else {
			printf("Win ");
		}
	}

	printf("\n");

	for (int i = 1; i < n; i++) {
		if (ans[1][i] == -1) {
			printf("Loop ");
		} else if (ans[1][i] == 0) {
			printf("Lose ");
		} else {
			printf("Win ");
		}
	}

	printf("\n");

	return 0;
}