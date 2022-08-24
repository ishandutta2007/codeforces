#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 251000
#define pii pair<int,int>
using namespace std;
vector<int>E[N_];
int n, m, K, Num[N_], Ed[N_], cnt, par[N_], chk = 0, Dep[N_];
struct point {
	int a, b, c;
};
vector<point>U;
void DFS(int a, int pp, int d) {
	if (1LL * d*K >= n) {
		chk = a;
	}
	Num[a] = ++cnt;
	Dep[a] = d;
	par[a] = pp;
	int ck = 0;
	for (auto &x : E[a]) {
		if (Num[x])continue;
		DFS(x, a, d + 1);
		ck = 1;
	}
	if (!ck) {
		vector<int>T;
		for (auto &x : E[a]) {
			if (x != pp) {
				T.push_back(x);
			}
		}
		if ((Dep[a] - Dep[T[0]]) % 3 != 2) {
			U.push_back({ a,T[0],-1 });
		}
		else if ((Dep[a] - Dep[T[1]]) % 3 != 2) {
			U.push_back({ a,T[1],-1 });
		}
		else {
			if (Dep[T[0]] < Dep[T[1]])swap(T[0], T[1]);
			U.push_back({ T[0],T[1],a });
		}
	}
}
int main() {
	int i, a, b;
	scanf("%d%d%d", &n, &m,&K);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, 0, 1);
	if (!chk && U.size() < K) {
		while (1) {}
	}
	if (chk) {
		puts("PATH");
		vector<int>R;
		while (chk) {
			R.push_back(chk);
			chk = par[chk];
		}
		printf("%d\n", R.size());
		for (auto &t : R)printf("%d ", t);
		puts("");
		return 0;
	}
	puts("CYCLES");
	for (i = 0; i < K; i++) {
		int x = U[i].a, y = U[i].b, z = U[i].c;
		vector<int>R;
		R.push_back(x);
		while (x != y) {
			x = par[x];
			R.push_back(x);
		}
		if (z != -1) {
			R.push_back(z);
		}

		printf("%d\n", R.size());
		for (auto &t : R)printf("%d ", t);
		puts("");
	}
}