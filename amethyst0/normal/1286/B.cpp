#pragma comment(linker, "/STACK:1000000000")
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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int maxn = 2010;

vector <int> ed[maxn];
int val[maxn];
int c[maxn];

bool cmp(int a, int b) {
	return val[a] < val[b];
}

vector <int> dfs(int v, int p) {
	vector <int> cur;

	for (int u : ed[v]) {
		if (u == p) {
			continue;
		}

		vector <int> a = dfs(u, v);

		for (int x : a) {
			cur.push_back(x);
		}
	}

	sort(cur.begin(), cur.end(), cmp);

	if (!cur.empty())
		val[cur[0]] = 2;
	for (int i = 1; i < (int)cur.size(); i++) {
		int x = cur[i];
		int y = cur[i - 1];

		val[x] = val[y] + 2;
	}

	if (c[v] > (int)cur.size()) {
		cout << "NO\n";
		exit(0);
	}

	if (c[v] == 0) {
		val[v] = 1;
	}
	else {
		val[v] = val[cur[c[v] - 1]] + 1;
	}

	cur.push_back(v);
	return cur;
}

int main() {
	int n;

	cin >> n;

	int r = -1;

	for (int i = 1; i <= n; i++) {
		int pr;

		scanf("%d %d", &pr, &c[i]);

		if (pr != 0)
			ed[pr].push_back(i);
		else
			r = i;
	}

	dfs(r, -1);

	printf("YES\n");

	for (int i = 1; i <= n; i++) {
		printf("%d ", val[i]);
	}

	return 0;
}