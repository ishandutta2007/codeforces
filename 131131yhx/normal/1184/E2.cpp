#include <bits/stdc++.h>
#define M 2500010
#define PII pair <int, int>
#define x first
#define y second

using namespace std;

map <PII, int> mmp;

int n, m, L[M], R[M], V[M], Head[M], Next[M], Go[M], Val[M], Cnt = 0, tmp[M], Dep[M], fa[200010], Fa[200010][20], Len[200010][20];

int qwq = 1e9;

bool used[M];

int getf(int x) {return fa[x] == x ? x : fa[x] = getf(fa[x]);}

bool cmp(int x, int y) {return V[x] < V[y];}

void addedge(int x, int y, int z) {
	Go[++Cnt] = y;
	Next[Cnt] = Head[x];
	Head[x] = Cnt;
	Val[Cnt] = z;
}

void DFS(int x, int f, int fv, int d) {
	Fa[x][0] = f, Len[x][0] = fv, Dep[x] = d;
	for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f) DFS(Go[T], x, Val[T], d + 1);
}

int Solve(int x, int y) {
	if(Dep[x] < Dep[y]) swap(x, y);
	int mx = 0, det = Dep[x] - Dep[y];
	for(int i = 19; i >= 0; i--) if(det >> i & 1) mx = max(mx, Len[x][i]), x = Fa[x][i];
	if(x == y) return mx;
	for(int i = 19; i >= 0; i--) if(Fa[x][i] != Fa[y][i]) mx = max(mx, max(Len[x][i], Len[y][i])), x = Fa[x][i], y = Fa[y][i];
	return max(mx, max(Len[x][0], Len[y][0])); 
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) scanf("%d%d%d", &L[i], &R[i], &V[i]), tmp[i] = i, mmp[PII(L[i], R[i])] = i, mmp[PII(R[i], L[i])] = i;
	for(int i = 1; i <= n; i++) fa[i] = i;
	sort(tmp + 1, tmp + m + 1, cmp);
	for(int i = 1; i <= m; i++) {
		int a = L[tmp[i]], b = R[tmp[i]], c = V[tmp[i]];
		if(getf(a) != getf(b)) addedge(a, b, c), addedge(b, a, c), fa[getf(a)] = getf(b), used[tmp[i]] = 1;
	}
	DFS(1, 0, 1e9, 1);
	for(int i = 0; i < 19; i++)
		for(int j = 1; j <= n; j++) Fa[j][i + 1] = Fa[Fa[j][i]][i], Len[j][i + 1] = max(Len[j][i], Len[Fa[j][i]][i]);
	for(int i = 1; i <= m; i++) if(!used[i]) printf("%d\n", Solve(L[i], R[i]));
	return 0;
}