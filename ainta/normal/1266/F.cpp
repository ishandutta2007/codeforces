#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#define N_ 501000
using namespace std;
vector<int>E[N_], Ch[N_];
vector<int>U[N_], G[N_];
int n, D[N_], Up[N_], par[N_];
void DFS(int a, int pp) {
	par[a] = pp;
	for (auto &x : E[a]) {
		if (x == pp)continue;
		DFS(x, a);
		Ch[a].push_back(x);
		D[a] = max(D[a], D[x] + 1);
	}
}
void Go(int a, int pp) {
	int M1 = Up[a], c1 = pp;
	int M2 = 0, c2 = 0;
	for (auto &x : Ch[a]) {
		if (M1 < D[x] + 1) {
			M2 = M1; c2 = c1;
			M1 = D[x] + 1;
			c1 = x;
		}
		else if (M2 < D[x] + 1) {
			M2 = D[x] + 1;
			c2 = x;
		}
	}
	for (auto &x : Ch[a]) {
		if (x == c1) {
			Up[x] = M2 + 1;
		}
		else Up[x] = M1 + 1;
		Go(x, a);
	}
}
int Ans[N_], Z[N_], MM[N_], CC[N_];
void Put(int d, int a) {
	Ans[d] = max(Ans[d], a);
}
int main() {
	int i, a, b, j;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for (i = 1; i <= n; i++) {
		Put(1, (int)E[i].size() + 1);
	}
	DFS(1, 0);
	Go(1, 0);
	for (i = 1; i <= n; i++) {
		for (auto &x : Ch[i]) {
			U[i].push_back(D[x] + 1);
		}
		if(Up[i])U[i].push_back(Up[i]);
	}
	int d = 0;
	for (i = 1; i <= n; i++) {
		d = max(d , max(D[i], Up[i]));
	}
	Put(n, 1);
	Put(d, 2);

	for (i = n - 1; i >= 1; i--)Ans[i] = max(Ans[i], Ans[i + 1]);

	for (i = 1; i <= n; i++) {
		sort(U[i].begin(), U[i].end());
		reverse(U[i].begin(), U[i].end());
		for (j = 0; j < U[i].size(); j++) {
			int d = U[i][j];
			CC[d]++;
			if (j > 0) {
				Put(d * 2 - 1, j + 1);
				Put(d * 2, j + 1);
				if (U[i][j - 1] > d) Put(d * 2 + 1, j + 1);
			}
			G[d].push_back(i);
		}
		for (auto &t : U[i])CC[t]--;
	}
	for (i = 1; i <= n; i++) {
		Z[i] = -1;
		MM[i] = -1e9;
	}
	for (i = 1; i <= n; i++) {
		for (auto &x : Ch[i]) {
			MM[i] = max(MM[i], Z[x]);
		}
	}
	for (i = n; i >= 1; i--) {
		for (auto &x : G[i]) {
			Z[x]++;
			Put(i * 2, MM[x] + Z[x]);
			if (par[x]) {
				MM[par[x]] = max(MM[par[x]], Z[x]);
				Put(i * 2, MM[par[x]] + Z[par[x]]);
			}
		}
	}
	for (i = n - 2; i >= 2; i--)Ans[i] = max(Ans[i], Ans[i + 2]);
	for (i = 1; i <= n; i++)printf("%d ", Ans[i]);
}