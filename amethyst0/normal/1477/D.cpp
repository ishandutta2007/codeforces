#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
#include <list>
#include <numeric>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)5e5 + 10;
set <int> red[maxn];
vector <int> ed[maxn];
int a[maxn], b[maxn];
bool good[maxn];
int deg[maxn];
bool used[maxn];

mt19937 rr;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++) {
			ed[i].clear();
			red[i].clear();
			good[i] = false;
			used[i] = false;
		}

		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			a--;
			b--;
			red[a].insert(b);
			red[b].insert(a);
		}

		int val = 0;

		for (int i = 0; i < n; i++) {
			if (good[i]) {
				continue;
			}

			int x = 0;

			while (x < n) {
				if (x != i && !red[i].count(x)) {
					ed[i].push_back(x);
					ed[x].push_back(i);
					good[i] = true;
					good[x] = true;
					break;
				}

				x++;
			}

			if (x == n) {
				a[i] = val;
				b[i] = val++;
			}
		}

		set <pii> s;

		for (int i = 0; i < n; i++) {
			if (!good[i]) {
				continue;
			}

			deg[i] = (int)ed[i].size();
			s.insert(mp((int)ed[i].size(), i));
		}

		while (!s.empty()) {
			int v = s.begin()->second;
			assert(s.begin()->first == 1);
			assert(deg[v] == 1);
			for (int u : ed[v]) {
				if (!used[u]) {
					v = u;
					break;
				}
			}

			int st = val;

			for (int u : ed[v]) {
				if (used[u]) {
					continue;
				}
				if (deg[u] == 1) {
					used[u] = true;
					s.erase(mp(deg[u], u));
					a[u] = st;
					b[u] = st + 1;
					st++;
				}
				else {
					s.erase(mp(deg[u], u));
					deg[u]--;
					s.insert(mp(deg[u], u));
				}
			}

			a[v] = st;
			b[v] = val;
			val = st + 1;
			s.erase(mp(deg[v], v));
			used[v] = true;
		}

		for (int i = 0; i < n; i++) {
			printf("%d ", a[i] + 1);
		}
		printf("\n");
		for (int i = 0; i < n; i++) {
			printf("%d ", b[i] + 1);
		}
		printf("\n");
	}
}