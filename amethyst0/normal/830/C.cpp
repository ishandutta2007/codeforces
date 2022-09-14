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
#include <unordered_set>
#define ld double
#define mp make_pair
#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>

using namespace std;

const int maxn = 110;
int v[maxn];

vector <pair <pll, int> > g[maxn];
int pos[maxn];

int main() {
	int n;

	ll k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	ll ans = 1;
	
	for (int i = 2; i <= (int)5e5; i++) {
		ll now = 0;
		for (int j = 0; j < n; j++) {
			int x = (-v[j]) % i;

			if (x < 0) {
				x += i;
			}

			now += x;
		}

		if (now <= k) {
			ans = i;
		}
	}
	
	for (int i = 2000; i >= 1; i--) {
		for (int j = 0; j < n; j++) {
			ll lm = (v[j] + i - 1) / i;
			ll rm = (ll)1e13;

			if (i != 1) {
				rm = (v[j] - 1) / (i - 1);
			}

			if (lm > rm) {
				continue;
			}

			g[j].push_back(mp(mp(lm, rm), i));
		}
	}

	while (true) {
		ll lm = 0, rm = (ll)1e13;

		bool fl = false;

		int w = 0;

		for (int i = 0; i < n; i++) {
			if (pos[i] == (int)g[i].size()) {
				fl = true;
				break;
			}

			if (g[i][pos[i]].first.second < g[w][pos[w]].first.second) {
				w = i;
			}

			lm = max(lm, g[i][pos[i]].first.first);
			rm = min(rm, g[i][pos[i]].first.second);
		}

		if (fl) {
			break;
		}

		if (lm <= rm) {
			ll sums = 0;
			ll mins = 0;

			for (int i = 0; i < n; i++) {
				mins += (ll)g[i][pos[i]].second * lm - v[i];
				sums += g[i][pos[i]].second;
			}

			if (mins <= k) {
				ll z = (k - mins) / sums;

				ans = max(ans, min(lm + z, (ll)rm));
			}
		}

		pos[w]++;
	}

	cout << ans << endl;

	return 0;
}