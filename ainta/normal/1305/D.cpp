#include<cstdio>
#include<algorithm>
#include<vector>
#include<random>
#include<ctime>
#include<iostream>
#include<cassert>
using namespace std;
int n, Num[1010],  Path[1010][1010], ord[1010][1010], cnt, ZZ[1010], U[1010], OK[1010], adj[1010][1010];
vector<int>E[1010];
void DFS1(int a, int pp, int rt) {
	Path[rt][a] = pp;
	ord[rt][++cnt] = a;
	for (auto &x : E[a]) {
		if (x == pp)continue;
		DFS1(x, a, rt);
	}
}
void Put(int a, int b, int L) {
	int i;
	for (i = 1; i <= n; i++)U[i] = 0;
	int x = b;
	while (x != a) {
		U[x] = x;
		x = Path[a][x];
	}
	U[a] = a;
	for (i = 1; i <= n; i++) {
		int x = ord[a][i];
		if (!U[x])U[x] = U[Path[a][x]];
	}
	for (i = 1; i <= n; i++) {
		if (U[i] != L)OK[i] = 0;
	}
}
void Solve() {
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)OK[i] = 1;
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		adj[a][b] = adj[b][a] = 1;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for (i = 1; i <= n; i++) {
		cnt = 0;
		DFS1(i, 0, i);
	}
	while (1) {
		vector<int>T;
		for (i = 1; i <= n; i++) {
			if (OK[i])T.push_back(i);
		}
		if (T.size() == 1) {
			printf("! %d\n", T[0]);
			fflush(stdout);
			return;
		}
		int aa, bb;
		if (T.size() == 2) {
			aa = T[0], bb = T[1];
		}
		else {
			for (i = 0; i < 3; i++) {
				for (int j = i + 1; j < 3; j++) {
					if (!adj[T[i]][T[j]]) {
						aa = T[i], bb = T[j];
					}
				}
			}
		}
		printf("? %d %d\n", aa, bb);
		fflush(stdout);
		scanf("%d", &a);
		Put(aa, bb, a);
	}
}
int main() {
	int TC = 1;
	while (TC--) {
		Solve();
	}
}