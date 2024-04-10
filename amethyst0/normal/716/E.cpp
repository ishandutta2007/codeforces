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
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll

using namespace std;

const int maxn = 400010;
vector <pii> ed[maxn];
ll st[maxn];
ll rst[maxn];
ll m;
ll phi = 0;
ll x[maxn], y[maxn];
int d[maxn];
ll o;

ll my_pow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}

	if (b & 1) {
		return (a * my_pow(a, b - 1)) % m;
	}

	ll t = my_pow(a, b >> 1);

	return (t * t) % m;
}

void make(int v, int p, ll a, ll b, int h) {
	x[v] = a;
	y[v] = b;
	d[v] = h;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].first;
		int c = ed[v][i].second;

		if (u == p) {
			continue;
		}

		make(u, v, (a + st[h] * c) % m, (b * 10 + c) % m, h + 1);
	}
}

map <pair <ll, int>, int> now[maxn];
int pos;

ll ans = 0;

int go(int v, int p) {
	int it[2];
	it[0] = pos++;
	now[it[0]][mp(x[v], 0)]++;
	now[it[0]][mp((y[v] * rst[d[v]]) % m, 1)]++;

	int f = 1;

	ll g = x[v] + y[v] * st[d[v]];
	g %= m;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].first;

		if (u == p) {
			continue;
		}

		it[f] = go(u, v);

		if (now[it[f]].size() > now[it[f ^ 1]].size()) {
			f ^= 1;
		}

		for (auto iter = now[it[f]].begin(); iter != now[it[f]].end(); iter++) {
			if (iter->first.second == 0) {
				ll gg = (g - iter->first.first) * rst[2 * d[v]];
				gg %= m;
				if (gg < 0) {
					gg += m;
				}

				if (now[it[f ^ 1]].count(mp(gg, 1))) {
					ans += (ll)iter->second * now[it[f ^ 1]][mp(gg, 1)];
				}
			} else {
				ll gg = (g - iter->first.first * st[2 * d[v]]);
				gg %= m;
				if (gg < 0) {
					gg += m;
				}

				if (now[it[f ^ 1]].count(mp(gg, 0))) {
					ans += (ll)iter->second * now[it[f ^ 1]][mp(gg, 0)];
				}
			}
		}

		for (auto iter = now[it[f]].begin(); iter != now[it[f]].end(); iter++) {
			now[it[f ^ 1]][iter->first] += iter->second;
		}

		now[it[f]].clear();
	}

	return it[f ^ 1];
}

int main() {
	int n;
	
	cin >> n >> m;

	st[0] = 1;

	for (int i = 1; i < maxn; i++) {
		st[i] = st[i - 1] * 10;
		st[i] %= m;
	}

	for (int i = 0; i < n - 1; i++) {
		int x, y, w;

		scanf("%d %d %d", &x, &y, &w);
		ed[x].push_back(mp(y, w));
		ed[y].push_back(mp(x, w));
	}
	
	if (m == 1) {
		printf("%lld\n", (ll)n * (n - 1));
		return 0;
	}

	phi = m;
	ll now = m;

	for (int i = 2; i * i <= now; i++) {
		if (now % i == 0) {
			phi /= i;
			phi *= i - 1;

			while (now % i == 0) {
				now /= i;
			}
		}
	}

	if (now != 1) {
		phi /= now;
		phi *= now - 1;
	}

	o = my_pow(10, phi - 1);
	rst[0] = 1;

	for (int i = 1; i < maxn; i++) {
		rst[i] = my_pow(o, i);
	}

	make(1, 1, 0, 0, 0);

	go(1, 1);
	cout << ans << endl;

	return 0;
}