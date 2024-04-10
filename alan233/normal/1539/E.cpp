// orz nb problem!
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef long long ll;

const int inf = (1 << 30) - 1;
const ll llinf = (1ll << 62) - 1;

const int N = 1e5 + 5;

int a[N];
int l[2][N], r[2][N];
int nxt[2][N];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d%d%d", &a[i], &l[0][i], &r[0][i], &l[1][i], &r[1][i]);
	}
	int last[2] = {n + 1, n + 1};
	int ml[2] = {-inf, -inf}, mr[2] = {inf, inf};
	bool flag[2] = {0, 0};
	for (int i = n; i; --i) {
		ml[0] = max(ml[0], l[0][i]);
		ml[1] = max(ml[1], l[1][i]);
		mr[0] = min(mr[0], r[0][i]);
		mr[1] = min(mr[1], r[1][i]);
		if (a[i] < l[0][i] || a[i] > r[0][i]) flag[0] = 1;
		if (a[i] < l[1][i] || a[i] > r[1][i]) flag[1] = 1;
		if (!flag[0] && ml[1] <= a[i - 1] && a[i - 1] <= mr[1]) {
			nxt[0][i] = last[1];
		}
		if (!flag[1] && ml[0] <= a[i - 1] && a[i - 1] <= mr[0]) {
			nxt[1][i] = last[0];
		}
		if (nxt[0][i]) {
			last[0] = i;
			flag[1] = 0;
			ml[0] = -inf;
			mr[0] = inf;
		}
		if (nxt[1][i]) {
			last[1] = i;
			flag[0] = 0;
			ml[1] = -inf;
			mr[1] = inf;
		}
	}
	if (nxt[0][1]) {
		printf("Yes\n");
		int x = 1;
		bool opt = 0;
		while (x < n + 1) {
			for (int i = x; i < nxt[opt][x]; ++i) {
				putchar(opt + '0');
				putchar(' ');
			}
			x = nxt[opt][x];
			opt ^= 1;
		}
	}
	else if (nxt[1][1]) {
		printf("Yes\n");
		int x = 1;
		bool opt = 1;
		while (x < n + 1) {
			for (int i = x; i < nxt[opt][x]; ++i) {
				putchar(opt + '0');
				putchar(' ');
			}
			x = nxt[opt][x];
			opt ^= 1;
		}
	}
	else {
		printf("No\n");
	}
}

int main() {
	srand(time(0));
//	int t;
//	scanf("%d", &t);
//	while (t--)
		solve();
}