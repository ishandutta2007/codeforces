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
#include <unordered_map>
#include <random>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10;

vector <int> pos[maxn];
vector <int> tr[maxn];

int getsum(int pos, int x) {
	int ans = 0;

	for ( ; x >= 0; x = (x & (x + 1)) - 1) {
		ans += tr[pos][x];
	}

	return ans;
}

int go(int pos, int l, int r) {
	if (l == 0) {
		return getsum(pos, r);
	} else {
		return getsum(pos, r) - getsum(pos, l - 1);
	}
}

void change(int pos, int x) {
	for ( ; x < (int)tr[pos].size(); x |= x + 1) {
		tr[pos][x]++;
	}
}

int main() {
	int n, k;

	cin >> n >> k;

	int l = 0;

	vector <pair <pii, int> > g;

	for (int i = 0; i < n; i++) {
		int x, r, f;

		scanf("%d %d %d", &x, &r, &f);

		g.push_back(mp(mp(r, x), f));

		pos[f].push_back(x);
	}

	sort(g.begin(), g.end());

	for (int i = 0; i < maxn; i++) {
		tr[i].resize(pos[i].size());
		sort(pos[i].begin(), pos[i].end());
	}

	ll ans = 0;

	for (int i = 0; i < (int)g.size(); i++) {
		int f = g[i].second;
		int r = g[i].first.first;
		int x = g[i].first.second;

		change(f, lower_bound(pos[f].begin(), pos[f].end(), x) - pos[f].begin());

		for (int j = f - k; j <= f + k; j++) {
			if (j < 0) {
				continue;
			}

			int lm = lower_bound(pos[j].begin(), pos[j].end(), x - r) - pos[j].begin();

			int rm = upper_bound(pos[j].begin(), pos[j].end(), x + r) - pos[j].begin() - 1;

			if (rm < lm) {
				continue;
			}

			ans += rm - lm + 1 - go(j, lm, rm);
		}
	}

	cout << ans << endl;

	return 0;
}