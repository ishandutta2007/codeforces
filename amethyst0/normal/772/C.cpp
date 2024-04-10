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
//#include "sort.h"

#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair

using namespace std;

const int maxn = (int)2e5 + 10;
int pr[maxn];
vector <int> ed[maxn];
int phi[maxn];

void make_edge(int m) {
	phi[m] = m;
	int x = m;
	while (m != 1) {
		int g = pr[m];
		phi[x] /= g;
		phi[x] *= g - 1;

		ed[x].push_back(x / g);

		while (pr[m] == g) {
			m /= g;
		}
	}
}

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int v[maxn];
vector <int> z[maxn];
int lnk[maxn];
int cnt[maxn];
int dp[maxn];
vector <int> f[maxn];

int my_pow(int a, int b, int m) {
	if (b == 0) {
		return 1 % m;
	}

	if (b & 1) {
		return ((ll)my_pow(a, b - 1, m) * a) % m;
	}

	int z = my_pow(a, b >> 1, m);

	return (ll)z * z % m;
}

int main() {
	memset(pr, -1, sizeof pr);

	for (int i = 2; i < maxn; i++) {
		if (pr[i] == -1) {
			pr[i] = i;

			for (int j = i; (ll)i * j < maxn; j++) {
				if (pr[i * j] == -1) {
					pr[i * j] = i;
				} else {
					pr[i * j] = min(pr[i * j], i);
				}
			}
		}
	}

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		if (m % i == 0) {
			make_edge(i);
		}
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);

		z[gcd(v[i], m)].push_back(v[i]);
	}

	for (int i = 0; i < m; i++) {
		f[gcd(i, m)].push_back(i);

		if (i != 0 && m % i == 0) {
			sort(z[i].begin(), z[i].end());
		}
	}

	memset(lnk, -1, sizeof lnk);

	for (int i = m; i >= 1; i--) {
		if (m % i != 0) {
			continue;
		}

		dp[i] = cnt[i] + (int)f[i].size() - (int)z[i].size();

		for (int j = 0; j < (int)ed[i].size(); j++) {
			int u = ed[i][j];

			if (cnt[u] < dp[i]) {
				cnt[u] = dp[i];
				lnk[u] = i;
			}
		}
	}

	printf("%d\n", dp[1]);

	int last = 1;
	int cl = 1;

	int g = 1;

	while (true) {
		int pos = 0;

		for (int i = 0; i < (int)f[g].size(); i++) {
			if (pos < (int)z[g].size() && f[g][i] == z[g][pos]) {
				pos++;
				continue;
			}

			int now = f[g][i];

			int x = g / cl;

			if (m / g == 2) {

			} else if (m == g) {
				x = 0;
			} else {
				x = ((ll)x * (((ll)now / g * my_pow(last / cl, phi[m / g] - 1, m / g)) % (m / g))) % m;
			}

			printf("%d ", x);

			if (((ll)last * x) % m != now) {
				throw 1;
			}

			last = now;
			cl = g;
		}

		g = lnk[g];

		if (g == -1) {
			break;
		}
	}

	return 0;
}