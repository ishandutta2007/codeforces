#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long

using namespace std;

const int maxn = 1010;
vector <int> ed[maxn];
set <int> a, b;
int p[maxn];

void dfs(int v, int pr) {
	p[v] = pr;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != pr) {
			dfs(u, v);
		}
	}
}

int go(char c, int x) {
	printf("%c %d\n", c, x);
	fflush(stdout);
	int ans;

	scanf("%d", &ans);

	return ans;
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n;

		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			ed[i].clear();
		}

		a.clear();
		b.clear();

		for (int i = 0; i < n - 1; i++) {
			int x, y;

			scanf("%d %d", &x, &y);

			ed[x].push_back(y);
			ed[y].push_back(x);
		}

		int k;

		scanf("%d", &k);

		for (int i = 0; i < k; i++) {
			int x;

			scanf("%d", &x);
			a.insert(x);
		}

		scanf("%d", &k);

		for (int i = 0; i < k; i++) {
			int x;

			scanf("%d", &x);
			b.insert(x);
		}

		int v = *a.begin();

		dfs(v, -1);

		int v1 = *b.begin();

		int ans = go('B', v1);

		while (!a.count(ans)) {
			ans = p[ans];
		}

		int res = go('A', ans);

		if (b.count(res)) {
			printf("C %d\n", ans);
		}
		else {
			printf("C -1\n");
		}

		fflush(stdout);
	}

	//system("pause");
}