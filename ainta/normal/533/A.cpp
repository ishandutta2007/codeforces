#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define N_ 1001000
#define SZ 1048576
#define pii pair<int,int>
using namespace std;
int n, w[N_], P[N_], H[N_];
int H1[N_], H2[N_], Num[N_];
int res = 2e9;
vector<int>E[N_], G[N_], Ch[N_];
void DFS(int a, int pp, int h1, int h2) {
	if (w[h1] >= w[a]) {
		h2 = h1;
		h1 = a;
	}
	else if (w[h2] >= w[a])h2 = a;
	H1[a] = w[h1];
	H2[a] = w[h2];
	Num[a] = h1;
	G[h1].push_back(a);
	for (auto &x : E[a]) {
		if (x == pp)continue;
		Ch[a].push_back(x);
		DFS(x, a, h1, h2);
	}
}
struct Tree {
	int L[SZ + SZ], S[SZ + SZ];
	void Add(int a, int b) {
		a += SZ;
		S[a] += b;
		L[a] = min(0, S[a]);
		while (a != 1) {
			a >>= 1;
			S[a] = S[a * 2] + S[a * 2 + 1];
			L[a] = min(L[a * 2], S[a * 2] + L[a * 2 + 1]);
		}
	}
}TT;
void Do(int a, int h) {
	int K = H[h] - H[w[a]];
	for (auto &x : G[a]) {
		TT.Add(H1[x], 1);
		TT.Add(min(H2[x], h), -1);
	}
	if (TT.L[1] >= 0)res = min(res, K);
	for (auto &x : G[a]) {
		TT.Add(H1[x], -1);
		TT.Add(min(H2[x], h), 1);
	}
}
int main() {
	int i, a, b, K;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	scanf("%d", &K);
	for (i = 1; i <= K; i++) {
		scanf("%d", &P[i]);
	}
	for (i = 1; i <= n; i++) {
		H[i] = w[i];
		H[n + i] = P[i];
	}
	sort(H + 1, H + n + n + 1);
	for (i = 1; i <= n; i++) {
		w[i] = lower_bound(H + 1, H + n + n + 1, w[i]) - H;
		P[i] = lower_bound(H + 1, H + n + n + 1, P[i]) - H;
	}
	w[0] = n + n;
	DFS(1, 0, 0, 0);
	sort(P + 1, P + n + 1);
	for (i = 1; i <= n; i++) {
		TT.Add(P[i], 1);
		TT.Add(H1[i], -1);
	}
	priority_queue<pii>PQ;
	PQ.push({ H1[1], 1 });
	for (i = n; i >= 1; i--) {
		if (PQ.empty() || PQ.top().first < P[i]) {
			while (!PQ.empty()) {
				Do(PQ.top().second, P[i]);
				PQ.pop();
			}
			break;
		}
		int x = PQ.top().second;
		PQ.pop();
		for (auto &y : Ch[x]) {
			PQ.push({ H1[y],y });
		}
	}
	if (i == 0) res = 0;
	if (res > 1.5e9)res = -1;
	printf("%d\n", res);
}