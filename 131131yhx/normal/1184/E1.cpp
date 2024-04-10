#include <bits/stdc++.h>
#define M 2500010

using namespace std;

int n, m, L[M], R[M], V[M], Head[M], Next[M], Go[M], Val[M], Cnt = 0, tmp[M], Fa[M];

int qwq = 1e9;

int getf(int x) {return Fa[x] == x ? x : Fa[x] = getf(Fa[x]);}

bool cmp(int x, int y) {return V[x] < V[y];}

void addedge(int x, int y, int z) {
	Go[++Cnt] = y;
	Next[Cnt] = Head[x];
	Head[x] = Cnt;
	Val[Cnt] = z;
}

void DFS(int x, int f, int mx) {
	if(x == R[1]) {
		printf("%d\n", mx);
		exit(0);
	}
	for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f) DFS(Go[T], x, max(mx, Val[T]));
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) scanf("%d%d%d", &L[i], &R[i], &V[i]), tmp[i] = i;
	for(int i = 1; i <= n; i++) Fa[i] = i;
	sort(tmp + 2, tmp + m + 1, cmp);
	for(int i = 2; i <= m; i++) {
		int a = L[tmp[i]], b = R[tmp[i]], c = V[tmp[i]];
		if(getf(a) != getf(b)) addedge(a, b, c), addedge(b, a, c), Fa[getf(a)] = getf(b);
	}
	if(getf(L[1]) != getf(R[1])) {
		printf("%d\n", qwq);
		return 0;
	}
	DFS(L[1], 0, 0);
	return 0;
}