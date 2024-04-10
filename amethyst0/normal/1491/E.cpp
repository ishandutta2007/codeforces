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

const int maxlog = 30;

int f[maxlog];

const int maxn = (int)2e5 + 10;
vector <int> ed[maxn];

bool good[maxn];

int sz[maxn];
int p[maxn];
int posit = 0;

vector <int> vert;

void dfs(int v, int pr) {
	sz[v] = 1;
	p[v] = pr;
	vert.push_back(v);

	for (int u : ed[v]) {
		if (u != pr) {
			dfs(u, v);
			sz[v] += sz[u];
		}
	}
}

bool go(int v) {
	vert.clear();
	dfs(v, -1);
	if (!good[sz[v]]) {
		return false;
	}

	if (sz[v] == 1) {
		return true;
	}

	for (int a : vert) {
		if (a == v) {
			continue;
		}

		if (good[sz[a]] && good[sz[v] - sz[a]]) {
			int pr = p[a];
			ed[a].erase(find(all(ed[a]), pr));
			ed[pr].erase(find(all(ed[pr]), a));
			return go(a) & go(pr);
		}
	}

	return false;
}

int main() {
	f[0] = f[1] = 1;
	good[1] = true;

	for (int i = 2; i < maxlog; i++) {
		f[i] = f[i - 1] + f[i - 2];
		if (f[i] < maxn) {
			good[f[i]] = true;
		}
	}

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

	if (go(0)) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}