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

const int maxn = 310;
int p[maxn];
int n;
int d[maxn][maxn];
const int inf = 1000000;
int m;

ld go(int v) {
	for (int i = 0; i <= m; i++) {
		d[0][i] = -inf;
	}

	d[0][v] = 0;

	ld ans = 0;

	for (int it = 0; it <= m; it++) {
		for (int i = 0; i <= m; i++) {
			d[it + 1][i] = -inf;
		}

		for (int i = 0; i <= m; i++) {
			for (int j = min(i, n); j >= 0; j--) {
				if (i - j + (n - j) > m) {
					break;
				}

				int c = i - j + (n - j);

				if (d[it][i] != -inf) {
					d[it + 1][c] = max(d[it + 1][c], d[it][i] + p[j]);
				}
			}
		}

		if (d[it + 1][v] != -inf) {
			ans = max(ans, (ld)d[it + 1][v] / (it + 1));
		}
	}

	return ans;
}

bool used[maxn];

void bfs(int x) {
	queue <int> q;
	q.push(x);
	used[x] = true;

	while (!q.empty()) {
		x = q.front();
		q.pop();

		for (int i = 0; i <= min(x, n); i++) {
			if (x - i + (n - i) > m) {
				continue;
			}

			int c = x - i + (n - i);
			
			if (!used[c]) {
				used[c] = true;
				q.push(c);
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i <= n; i++) {
		ld x;
		scanf("%lf", &x);
		p[i] = (int)(x * 1000000 + 0.5);
	}

	m = n * 2;

	ld ans = 0;

	bfs(0);

	for (int i = 0; i <= m; i++) {
		if (used[i]) {
			ans = max(ans, go(i));
		}
	}

	printf("%.10lf\n", ans / 1000000);

	return 0;
}