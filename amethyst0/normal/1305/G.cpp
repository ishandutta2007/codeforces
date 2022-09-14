#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int maxn = (1 << 18) + 10, maxlog = 18;
int v[maxn];

vector <int> ed[1 << maxlog];
bool used[1 << maxlog];
int p[maxn];

int getp(int x) {
	return (x == p[x] ? x : p[x] = getp(p[x]));
}

pii wh[1 << maxlog];
bool ok[1 << maxlog];

void add(int pos, int u) {
	int x = getp(pos);
	int val = v[pos];

	if (wh[u].first == -1) {
		wh[u].first = pos;
	}
	else if (getp(wh[u].first) == x) {
		if (v[wh[u].first] < val) {
			wh[u].first = pos;
		}
	}
	else if (wh[u].second == -1) {
		wh[u].second = pos;
	}
	else if (v[wh[u].second] < val) {
		wh[u].second = pos;
	}

	if (wh[u].second != -1) {
		ok[u] = true;

		if (v[wh[u].second] > v[wh[u].first]) {
			swap(wh[u].first, wh[u].second);
		}
	}
}

void build(int v) {
	if (used[v]) {
		return;
	}

	used[v] = true;

	for (int u : ed[v]) {
		build(u);
		if (wh[u].first != -1) {
			add(wh[u].first, v);
		}

		if (wh[u].second != -1) {
			add(wh[u].second, v);
		}
	}
}

pii to[maxn];

int main() {
	int n;

	cin >> n;

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		ans -= v[i];
	}

	v[n++] = 0;

	for (int i = 0; i < (1 << maxlog); i++) {
		for (int j = 0; j < maxlog; j++) {
			if ((i >> j) & 1) {
				ed[i].push_back(i ^ (1 << j));
			}
		}
	}

	for (int i = 0; i < n; i++) {
		p[i] = i;
	}

	for (int it = 0; it < maxlog; it++) {
		memset(wh, -1, sizeof wh);
		memset(used, 0, sizeof used);
		memset(ok, 0, sizeof ok);
		memset(to, -1, sizeof to);

		for (int i = 0; i < n; i++) {
			add(i, v[i]);
		}

		build((1 << maxlog) - 1);

		for (int i = 0; i < n; i++) {
			int mask = ((1 << maxlog) - 1) ^ v[i];
			int pi = getp(i);

			if (ok[mask] || (wh[mask].first != -1 && getp(wh[mask].first) != pi)) {
				int np = wh[mask].first;

				if (getp(np) == pi) {
					np = wh[mask].second;
				}

				pii f = mp(v[i] + v[np], getp(np));

				if (f > to[pi]) {
					to[pi] = f;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			if (to[i].first == -1) {
				continue;
			}

			int j = to[i].second;
			if (getp(i) != getp(j)) {
				ans += to[i].first;
				p[getp(i)] = getp(j);
			}
		}
	}

	cout << ans << endl;
}