#include <bits/stdc++.h>
#define M 2000010
#define PII pair <int, int>
#define x first
#define y second

using namespace std;

int n, m;

int Head[M], Next[M * 2], Go[M * 2], lst[M], deg[M], nw[M], Cnt = 1;

bool used[M];

vector <int> Ans(0);

vector <PII> rl(0);

void addedge(int x, int y) {
	Go[++Cnt] = y;
	Next[Cnt] = Head[x];
	Head[x] = Cnt;
}

void DFS(int x) {
	for(int &T = lst[x]; T; T = Next[T]) if(!used[T / 2]) {
		int tmp = T / 2;
		used[T / 2] = 1;
		DFS(Go[T]);
		Ans.push_back(tmp);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		addedge(a, b);
		addedge(b, a);
		deg[a]++, deg[b]++;
	}
	vector <int> V(0);
	for(int i = 1; i <= n; i++) if(deg[i] & 1) V.push_back(i);
	for(int i = 0; i < V.size(); i++) addedge(n + 1, V[i]), addedge(V[i], n + 1);
	for(int i = 1; i <= n + 1; i++) lst[i] = Head[i];
	for(int i = 1; i <= n + 1; i++) DFS(i);
	memset(used, 0, sizeof used);
	for(int i = 0; i < Ans.size(); i += 2) if(Ans[i] <= m) used[Ans[i]] = 1, nw[Go[Ans[i] * 2]]++, nw[Go[Ans[i] * 2 + 1]]++, rl.push_back(PII(Go[Ans[i] * 2], Go[Ans[i] * 2 + 1]));
	for(int i = 1; i <= n; i++) {
		int a = i;
		if(nw[a] * 2 >= deg[a]) continue;
		for(int T = Head[a]; T; T = Next[T]) if(!used[T / 2] && Go[T] != n + 1) {
			nw[a]++;
			nw[Go[T]]++;
			rl.push_back(PII(a, Go[T]));
			used[T / 2] = 1;
			break;
		}
	}
	printf("%d\n", rl.size());
	for(int i = 0; i < rl.size(); i++) printf("%d %d\n", rl[i].x, rl[i].y);
	return 0;
}