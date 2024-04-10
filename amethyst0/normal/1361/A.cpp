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

const int maxn = (int)5e5 + 10;

vector <int> ed[maxn];
int t[maxn];
bool used[maxn];

int us[maxn];
int tt = 0;

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		x--;
		y--;
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	vector <int> p;

	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
		p.push_back(i);
	}

	sort(all(p), [&](int a, int b) {
		return t[a] < t[b];
	});

	for (int v : p) {
		used[v] = 1;

		tt++;

		for (int u : ed[v]) {
			if (!used[u]) {
				continue;
			}

			us[t[u]] = tt;
		}

		int ans = 1;

		while (us[ans] == tt) {
			ans++;
		}

		if (ans != t[v]) {
			printf("-1\n");
			return 0;
		}
	}

	for (int v : p) {
		printf("%d ", v + 1);
	}

	printf("\n");
}