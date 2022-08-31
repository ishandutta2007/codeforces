#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, Num[101000], cnt, Dep[101000], Path[101000];
int chk[101000], ord[101000], par[101000], pL[101000];
long long R[101000], w[101000];
vector<int>E[101000], L[101000];
void DFS(int a) {
	Num[a] = ++cnt;
	ord[cnt] = a;
	int i;
	for (i = 0; i < E[a].size(); i++) {
		if (Num[E[a][i]])continue;
		chk[L[a][i]] = 1;
		Dep[E[a][i]] = Dep[a] + 1;
		par[E[a][i]] = a;
		pL[E[a][i]] = L[a][i];
		DFS(E[a][i]);
	}
}
struct Edge {
	int a, b;
}Ed[201000];
void Pro(int a, int b, int num, long long ss) {
	int i;
	R[num] -= ss / 2;
	while (a != b) {
		if (Dep[a] < Dep[b]) swap(a, b);
		R[pL[a]] -= ss / 2;
		w[a] += ss;
		a = par[a];
	}
	w[a] += ss;
}
void Make() {
	int i;
	for (i = n; i >= 2; i--) {
		long long tt = w[ord[i]];
		R[pL[ord[i]]] += tt;
		w[par[ord[i]]] -= tt;
	}
}
int main() {
	int i, j, a, b;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
	}
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
		L[a].push_back(i);
		L[b].push_back(i);
		Ed[i] = { a,b };
	}
	DFS(1);
	long long sum = 0;
	for (i = 1; i <= n; i++) {
		if (Dep[i] % 2 == 0)sum += w[i];
		else sum -= w[i];
	}
	if (abs(sum) % 2) {
		printf("NO\n");
		return 0;
	}
	if (sum == 0) {
		Make();
	}
	else {
		for (i = 0; i < m; i++) {
			if (!chk[i] && Dep[Ed[i].a] % 2 == Dep[Ed[i].b] % 2) {
				if (Dep[Ed[i].a] % 2) {
					Pro(Ed[i].a, Ed[i].b, i, sum);
					break;
				}
				else {
					Pro(Ed[i].a, Ed[i].b, i, -sum);
					break;
				}
			}
		}
		if (i == m) {
			printf("NO\n");
			return 0;
		}
		Make();
	}
	printf("YES\n");
	for (i = 0; i < m; i++)printf("%lld\n", R[i]);
}