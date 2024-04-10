#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 501000
using namespace std;
vector<int>T[N_], E[N_];
int n, UF[N_], par[N_];
void DFS1(int a, int pp) {
	par[a] = pp;
	for (auto &x : E[a]) {
		if (x != pp)DFS1(x, a);
	}
}
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
void Merge(int a) {
	UF[a] = par[a];
}
struct point {
	int a, b, c, d;
};
vector<point>res;
void DFS2(int a, int pp) {
	for (auto &x : T[a]) {
		if(x!=pp)DFS2(x, a);
	}
	if (!pp)return;
	if (par[a] == pp) {
		Merge(a);
		return;
	}
	if (par[pp] == a) {
		Merge(pp);
		return;
	}
	res.push_back({ a, pp, Find(a), par[Find(a)] });
	Merge(Find(a));
}
int main() {
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		T[a].push_back(b);
		T[b].push_back(a);
	}
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for (i = 1; i <= n; i++)UF[i] = i;
	DFS1(1, 0);
	DFS2(1, 0);
	printf("%d\n", res.size());
	for (auto &t : res)printf("%d %d %d %d\n", t.a, t.b, t.c, t.d);
}