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
#include <memory.h>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)3e5 + 10;
vector <int> els[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		int sq = 1;

		while (sq * sq < n) {
			sq++;
		}

		map<int, int> cnt;

		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			cnt[x]++;
		}

		for (int i = 0; i <= sq; i++) {
			els[i].clear();
		}

		auto it = cnt.begin();
		while (it != cnt.end()) {
			auto nit = next(it);
			if (it->second <= sq) {
				els[it->second].push_back(it->first);
				cnt.erase(it);
			}
			it = nit;
		}

		for (int i = 0; i <= sq; i++) {
			sort(all(els[i]));
			reverse(all(els[i]));
		}

		set<pii> bad;

		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			bad.insert(mp(x, y));
			bad.insert(mp(y, x));
		}

		ll ans = 0;

		for (auto[x, cx] : cnt) {
			for (auto[y, cy] : cnt) {
				if (x != y && !bad.count(mp(x, y))) {
					ans = max(ans, (ll)(x + y) * (cx + cy));
				}
			}

			for (int i = 0; i <= sq; i++) {
				for (int y : els[i]) {
					if (!bad.count(mp(x, y))) {
						ans = max(ans, (ll)(x + y) * (cx + i));
						break;
					}
				}
			}
		}

		for (int i = 0; i <= sq; i++) {
			if (els[i].empty()) {
				continue;
			}
			for (int j = 0; j <= i; j++) {
				if (els[j].empty()) {
					continue;
				}
				set<pair <ll, pii>> s;
				s.insert(mp(els[i][0] + els[j][0], mp(0, 0)));

				while (!s.empty()) {
					ll sc = s.rbegin()->first;
					auto[pi, pj] = s.rbegin()->second;
					s.erase(mp(sc, mp(pi, pj)));
					if (bad.count(mp(els[i][pi], els[j][pj])) || els[i][pi] == els[j][pj]) {
						if (pi + 1 != (int)els[i].size()) {
							s.insert(mp(els[i][pi + 1] + els[j][pj], mp(pi + 1, pj)));
						}
						if (pj + 1 != (int)els[j].size()) {
							s.insert(mp(els[i][pi] + els[j][pj + 1], mp(pi, pj + 1)));
						}
					}
					else {
						ans = max(ans, sc * (i + j));
						break;
					}
				}
			}
		}

		printf("%lld\n", ans);
	}
}