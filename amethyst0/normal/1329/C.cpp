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

const int maxn = (1 << 23);

int v[maxn];
int pos[maxn];

void del(int it) {
	if (v[2 * it] == 0 && v[2 * it + 1] == 0) {
		v[it] = 0;
		return;
	}

	if (v[2 * it] > v[2 * it + 1]) {
		pos[v[2 * it]] = it;
		swap(v[2 * it], v[it]);
		del(2 * it);
	}
	else {
		pos[v[2 * it + 1]] = it;
		swap(v[2 * it + 1], v[it]);
		del(2 * it + 1);
	}
}

ll tot = 0;

int h, g;
bool used[maxn];

int dfs(int it, int gl, int x) {
	int ans = (int)1e9;

	if (v[it] > x) {
		ans = v[it];
	}

	if (gl == h) {
		return ans;
	}

	ans = min(ans, dfs(2 * it, gl + 1, x));
	ans = min(ans, dfs(2 * it + 1, gl + 1, x));
	return ans;
}

int go(int it, int gl) {
	if (gl == g) {
		int x = dfs(it, gl, 0);
		used[x] = true;
		tot += x;
		return x;
	}

	int x = go(2 * it, gl + 1);
	x = max(x, go(2 * it + 1, gl + 1));
	x = dfs(it, gl, x);
	used[x] = true;
	tot += x;
	return x;
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		scanf("%d %d", &h, &g);

		vector <int> f;

		for (int i = 1; i < (1 << h); i++) {
			scanf("%d", &v[i]);
			used[v[i]] = false;
			pos[v[i]] = i;
			f.push_back(v[i]);
		}

		sort(all(f));

		h--;
		g--;

		tot = 0;

		go(1, 0);

		printf("%lld\n", tot);

		for (int x : f) {
			if (!used[x]) {
				printf("%d ", pos[x]);
			}
		}

		printf("\n");
	}
}