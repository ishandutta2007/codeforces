/*AMETHYSTS*/
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
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
//#include <unordered_map>
//#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll

using namespace std;

const int maxn = (int)1e3 + 10;

bool used[maxn];
int p[maxn];
int cnt[maxn];
int num[maxn];

int getp(int x) {
	if (x == p[x]) {
		return x;
	}

	return p[x] = getp(p[x]);
}

int main() {
	int n, m, k;

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		p[i] = i;
		cnt[i] = 0;
		num[i] = 1;
	}

	for (int i = 0; i < k; i++) {
		int c;

		scanf("%d", &c);

		used[c] = true;
	}

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		x = getp(x);
		y = getp(y);

		if (x != y) {
			p[y] = x;
			cnt[x] += cnt[y];
			num[x] += num[y];
		}

		cnt[x]++;
	}

	for (int i = 1; i <= n; i++) {
		if (used[i]) {
			int x = getp(i);

			used[x] = true;
		}
	}

	int best = 1;

	for (int i = 1; i <= n; i++) {
		if (i == p[i] && num[i] > num[best] && used[i]) {
			best = i;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (i == p[i] && !used[i]) {
			p[i] = best;
			num[best] += num[i];
			cnt[best] += cnt[i];
		}
	}

	ll ans = 0;

	for (int i = 1; i <= n; i++) {
		if (p[i] == i) {
			ans += (ll)num[i] * (num[i] - 1) / 2 - cnt[i];
		}
	}

	cout << ans << endl;

	return 0;
}