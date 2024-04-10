#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector< vector<int> > gr, gr1, gr2;
vector<bool> used, used1;
vector<int> a;
int kol1[100000], kol2[100000];

int find(int x) {
	if (x == a[x]) {
		return x;
	}
	return a[x] = find(a[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (rand() & 1) {
		a[x] = y;
	}
	else {
		a[y] = x;
	}
}

void dfs(int v, int p) {
	used[v] = true;
	for (vector<int>::iterator it = gr[v].begin(); it != gr[v].end(); it++) {
		if (*it != p && kol2[*it] < kol1[*it] && kol2[v] < kol1[v]) {
			gr1[v].push_back(*it);
			gr2[*it].push_back(v);
			kol2[v]++;
			kol2[*it]++;
		}
		if (!used[*it]) {
			dfs(*it, v);
		}
	}
}

void dfs1(int v) {
	used[v] = true;
	for (vector<int>::iterator it = gr1[v].begin(); it != gr1[v].end(); it++) {
		if (!used[*it]) {
			dfs1(*it);
		}
	}
}

void dfs2(int v) {
	used[v] = true;
	for (vector<int>::iterator it = gr2[v].begin(); it != gr2[v].end(); it++) {
		if (!used[*it]) {
			dfs2(*it);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, x, y;
	cin >> n >> m;
	gr.resize(n);
	gr1.resize(n);
	gr2.resize(n);
	used.assign(n, false);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		gr[--x].push_back(--y);
		gr[y].push_back(x);
		kol1[x]++;
		kol1[y]++;
	}
	dfs(0, -1);
	used.assign(n, false);
	dfs1(0);
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			cout << 0;
			return 0;
		}
		used[i] = false;
	}
	dfs2(0);
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			cout << 0;
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (vector<int>::iterator it = gr1[i].begin(); it != gr1[i].end(); it++) {
			printf("%d %d\n", i + 1, *it + 1);
		}
	}



	return 0;
}//iikehw