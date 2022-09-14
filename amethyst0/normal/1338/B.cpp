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
#include <unordered_map>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int maxn = (int)1e5 + 10;
vector <int> ed[maxn];
int h[maxn];

int dfs(int v, int p, int hh) {
	h[v] = hh;

	int ans = 0;
	int num = 0;

	for (int u : ed[v]) {
		if (u != p) {
			ans += dfs(u, v, hh + 1);
			ans++;

			if ((int)ed[u].size() == 1) {
				num++;
			}
		}
	}

	if (num != 0) {
		ans -= num;
		ans++;
	}

	return ans;
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		x--;
		y--;
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	int v = 0;

	while ((int)ed[v].size() == 1) {
		v++;
	}

	int ans = dfs(v, -1, 0);

	int x = -1;
	bool ok = true;

	for (int i = 0; i < n; i++) {
		if ((int)ed[i].size() == 1) {
			if (x == -1) {
				x = i;
			}
			else if ((h[x] & 1) != (h[i] & 1)) {
				ok = false;
			}
		}
	}

	if (ok) {
		cout << 1 << ' ' << ans << '\n';
	}
	else {
		cout << 3 << ' ' << ans << '\n';
	}
}