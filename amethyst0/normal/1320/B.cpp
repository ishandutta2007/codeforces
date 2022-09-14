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

const int maxn = (int)2e5 + 10;
vector <int> ed[maxn];
vector <int> red[maxn];

int dst[2][maxn];

void bfs(int tp, int v) {
	queue <int> q;
	q.push(v);
	memset(dst[tp], -1, sizeof dst[tp]);

	dst[tp][v] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (tp == 0) {
			for (int u : ed[v]) {
				if (dst[tp][u] == -1) {
					dst[tp][u] = dst[tp][v] + 1;
					q.push(u);
				}
			}
		}
		else {
			for (int u : red[v]) {
				if (dst[tp][u] == -1) {
					dst[tp][u] = dst[tp][v] + 1;
					q.push(u);
				}
			}
		}
	}
}

int main() {
	int n, m;

	cin >> n >> m;

	while (m--) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		ed[x].push_back(y);
		red[y].push_back(x);
	}

	vector <int> w;
	int k;
	cin >> k;
	w.resize(k);

	for (int i = 0; i < k; i++) {
		scanf("%d", &w[i]);
		w[i]--;
	}

	bfs(0, w[0]);
	bfs(1, w.back());

	int maxx = 0;
	int minx = 0;

	for (int i = 0; i < (int)w.size() - 1; i++) {
		int x = w[i];
		int y = w[i + 1];

		bool yes = false;

		for (int u : ed[x]) {
			if (u != y && dst[1][u] + 1 == dst[1][x]) {
				yes = true;
			}
		}

		if (dst[1][y] + 1 == dst[1][x]) {

		}
		else {
			minx++;
		}

		if (yes) {
			maxx++;
		}
	}

	cout << minx << ' ' << maxx << '\n';
}