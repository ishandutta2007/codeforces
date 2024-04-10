#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define pii pair<int,int>
using namespace std;
vector<int>E[501000], F[501000];
int D[501000], w[501000], CK[501000];
priority_queue<pii>PQ;
int n, m, K;
void Put(int a, int d) {
	if (D[a] <= d)return;
	D[a] = d;
	PQ.push({ -d,a });
}
void Dijk(int a) {
	int i;
	for (i = 1; i <= n; i++)D[i] = 1e9;
	Put(a, 0);
	while (!PQ.empty()) {
		pii tp = PQ.top();
		PQ.pop();
		int x = tp.second;
		if (-tp.first != D[x])continue;
		for (auto &t : E[x]) {
			Put(t, D[x] + 1);
		}
	}
}
int main() {
	int i;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		E[b].push_back(a);
		F[a].push_back(b);
	}
	scanf("%d", &K);
	for (i = 1; i <= K; i++)scanf("%d", &w[i]);
	Dijk(w[K]);
	for (i = 1; i <= n; i++) {
		for (auto &x : F[i]) {
			if (D[i] == D[x] + 1)CK[i]++;
		}
	}
	int Mn = 0, Mx = 0;
	for (i = 2; i <= K; i++) {
		if (D[w[i]] + 1 != D[w[i - 1]]) {
			Mn++;
			Mx++;
		}
		else {
			if (CK[w[i - 1]]>1)Mx++;
		}
	}
	printf("%d %d\n", Mn, Mx);
}