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
#include <ctime>
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)5e5 + 10;

vector <int> ed[maxn];
bool used[maxn];

vector <int> vert;

int n, m, k;

vector <int> l;
int pr[maxn];
int d[maxn];

void dfs(int v, int p, int g) {
	pr[v] = p;
	vert.push_back(v);
	d[v] = g;
	used[v] = true;

	if ((ll)g * k >= n) {
		printf("PATH\n");
		printf("%d\n", (int)vert.size());

		while (!vert.empty()) {
			printf("%d ", vert.back());
			vert.pop_back();
		}

		printf("\n");

		//system("pause");
		exit(0);
	}

	bool yes = false;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (!used[u]) {
			yes = true;
			dfs(u, v, g + 1);
		}
	}

	if (!yes) {
		l.push_back(v);
	}

	vert.pop_back();
}

void write(int x, int y) {
	vector <int> ans;

	while (x != y) {
		ans.push_back(x);
		x = pr[x];
	}

	ans.push_back(y);

	printf("%d\n", (int)ans.size());

	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d ", ans[i]);
	}

	printf("\n");
}

void write(int v, int x, int y) {
	vector <int> ans;

	ans.push_back(v);

	while (x != y) {
		ans.push_back(x);
		x = pr[x];
	}

	ans.push_back(y);

	printf("%d\n", (int)ans.size());

	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d ", ans[i]);
	}

	printf("\n");
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	dfs(1, -1, 0);

	if ((int)l.size() < k) {
		throw 1;
	}

	printf("CYCLES\n");

	for (int i = 0; i < k; i++) {
		int v = l[i];

		int x = -1, y = -1;

		for (int j = 0; j < (int)ed[v].size(); j++) {
			int u = ed[v][j];

			if (u != pr[v]) {
				if (x == -1) {
					x = u;
				}
				else {
					y = u;
				}
			}
		}

		if (y == -1) {
			throw 1;
		}

		if (d[x] > d[y]) {
			swap(x, y);
		}

		int len1 = d[v] - d[x];
		int len2 = d[v] - d[y];

		if (len1 % 3 != 2) {
			write(v, x);
		}
		else if (len2 % 3 != 2) {
			write(v, y);
		}
		else {
			write(v, y, x);
		}
	}

	//system("pause");
}