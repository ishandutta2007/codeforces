#include<cstdio>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
using namespace std;
vector<int>E[201000];
int D[201000][2], C[201000];
int n, w[201000], Dep[201000];
long long R[201000], Mod = 1000000007;
void DFS(int a, int pp) {
	int i;
	C[a] = 1;
	for (auto &x : E[a]) {
		if (x == pp)continue;
		Dep[x] = Dep[a] + 1;
		DFS(x, a);
		C[a] += C[x];
		D[a][0] += D[x][0];
		D[a][1] += D[x][1];
	}
	D[a][Dep[a] % 2]++;
}
void Do(int a, int pp) {
	int i;
	for (auto &x : E[a]) {
		if (x == pp)continue;
		Do(x, a);
	}
	vector<pii>TP;
	for (auto &x : E[a]) {
		int c1, c2, c;
		if (x == pp) {
			c1 = D[1][0] - D[a][0], c2 = D[1][1] - D[a][1];
			c = C[1] - C[a];
		}
		else {
			c1 = D[x][0], c2 = D[x][1];
			c = C[x];
		}
		int tt;
		if (Dep[a] % 2 == 0) tt = c1 - c2;
		else tt = c2 - c1;
		R[a] = (R[a] + 1ll * (tt+Mod) * (n - c)) % Mod;
	}
	R[a] = (R[a] + n) % Mod;
}
int main() {
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {

		scanf("%d", &w[i]);
		if (w[i] < 0)w[i] += Mod;
	}
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, 0);
	Do(1, 0);
	long long rr = 0;
	for (i = 1; i <= n; i++)rr = (rr + R[i] * w[i]) % Mod;
	printf("%lld\n", rr);
}