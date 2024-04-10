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
#include <fstream>
#include <bitset>
#include <cstring>
#include <limits.h>
#include <unordered_map>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxn = 85, inf = (int)1e9 + 10;
int ed[maxn][maxn];

vector <pii> e[maxn][maxn];

vector <int> w;
int n;
bool in[maxn];

int solve(int pos, int k) {
	if (pos < k) {
		int ans = inf;
		for (int i = 0; i < n; i++) {
			bool nd = false;
			w.push_back(i);

			if (!in[i]) {
				nd = true;
				in[i] = true;
			}

			ans = min(ans, solve(pos + 2, k));

			if (nd) {
				in[i] = false;
			}

			w.pop_back();
		}

		return ans;
	}
	else {
		int ans = 0;
		for (int i = 0; i < (int)w.size(); i++) {
			int v = w[i];
			int u = w[i + 1 == (int)w.size() ? 0 : i + 1];

			for (auto[c, to] : e[v][u]) {
				if (in[to]) {
					continue;
				}

				ans += c;
				break;
			}
		}

		return ans;
	}
}

int main() {
	int k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ed[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (k == i || k == j) {
					continue;
				}

				e[i][j].push_back(mp(ed[i][k] + ed[k][j], k));
			}

			sort(all(e[i][j]));
		}
	}

	in[0] = true;
	w.push_back(0);
	cout << solve(2, k) << '\n';
}