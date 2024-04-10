#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 201000
using namespace std;
vector<int>E[N_], G[N_];
int n, m, v[N_], Num[N_], w[N_], Q[N_], head, tail, Deg[N_], D[N_], cnt;
void Go(int a, int st) {
	if (D[a] != -1)return;
	int Mx = -1, pv = -2;
	if (Num[a] != -1)Mx = (Num[a] + cnt - st) % cnt, pv = Num[a];
	for (auto &x : G[a]) {
		Go(x, st);
		if (D[x] < 0)continue;
		if (Mx < (D[x] + cnt - st) % cnt)Mx = (D[x] + cnt - st) % cnt, pv = D[x];
	}
	D[a] = pv;
}
bool Cycle() {
	int i;
	for (i = 1; i <= n + n; i++)Deg[i] = 0;
	for (i = 1; i <= n + n; i++)for (auto &t : G[i])Deg[t]++;
	head = tail = 0;
	for (i = 1; i <= n + n; i++)if (!Deg[i])Q[++tail] = i;
	while (head < tail) {
		int x = Q[++head];
		for (auto &t : G[x]) {
			Deg[t]--;
			if (!Deg[t])Q[++tail] = t;
		}
	}
	return tail != n + n;
}
int S[N_], par[N_], cur[N_], chk;
void Put(int a, int x) {
	chk = 1;
	int t = a;
	while (1) {
		cnt++;
		if (t == x)break;
		t = par[t];
	}
	t = a;
	int cc = 0;
	while (1) {
		Num[t] = cnt - cc - 1;
		w[Num[t]] = t;
		cc++;
		if (t == x)break;
		t = par[t];
	}
}
void DFS(int a) {
	cur[a] = 1;
	v[a] = 1;
	for (auto &x : E[a]) {
		if (cur[x] == 1 && !chk) {
			Put(a, x);
		}
		if (!v[x]) {
			par[x] = a;
			DFS(x);
		}
	}
	cur[a] = 2;
}
int main() {
	int i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		E[n+a].push_back(b);
	}
	for (i = 1; i <= n; i++)E[i].push_back(n + i);
	for (i = 1; i <= n+n; i++)D[i] = Num[i] = -1;

	for (i = 1; i <= n; i++) {
		if (!v[i])DFS(i);
	}

	for (i = 1; i <= n + n; i++)for (int j = 0; j < E[i].size();j++) {
		if (Num[i]!=-1 && j == 0) continue;
		int t = E[i][j];
		G[i].push_back(t), Deg[t]++;
	}
	if (Cycle()) {
		printf("-1\n");
		return 0;
	}
	for (i = 0; i < cnt; i++) {
		if (D[w[i]] == -1)Go(w[i], i);
	}
	for (i = 0; i < cnt; i++) {
		int b = D[w[i]], e = i;
		if (b < e)S[b]++, S[e]--;
		else S[b]++, S[e]--, S[0]++;
	}
	int ck = 0;
	for (i = 0; i < cnt; i++) {
		if (i)S[i] += S[i - 1];
		if (S[i] == cnt) {
			if (!ck) {
				for (int j = 0; j < cnt; j++) {
					if (j != i)G[w[j]].push_back(w[(j + 1) % cnt]);
				}
				if (Cycle()) {
					printf("-1\n");
					return 0;
				}
			}
			ck = 1;
			if (w[(i + 1) % cnt] == w[i] + n) {
				printf("%d\n", w[i]);
				return 0;
			}
		}
	}
	puts("-1");
}