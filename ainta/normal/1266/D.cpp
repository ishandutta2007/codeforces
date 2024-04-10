#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 301000
using namespace std;
int n, m, vis[N_];
vector<int>E[N_], T;
long long S[N_];
void DFS(int a) {
	T.push_back(a);
	vis[a] = 1;
	for (auto &x : E[a]) {
		if (!vis[x])DFS(x);
	}
}
struct AA {
	int num;
	long long d;
	bool operator <(const AA &p)const {
		return d < p.d;
	}
}U[N_];
struct Edge {
	int a, b;
	long long c;
};
vector<Edge>Ed;
void Go() {
	int cc = 0;
	for (auto &t : T) U[cc++] = { t, S[t] };
	sort(U, U + cc);
	int pv = cc - 1;
	for (int i = 0; i < cc; i++) {
		if (U[i].d >= 0)continue;
		while (1) {
			long long t = min(-U[i].d, U[pv].d);
			if (t > 0) {
				Ed.push_back({ U[i].num, U[pv].num, t });
				U[i].d += t, U[pv].d -= t;
			}
			if (U[i].d >= 0)break;
			pv--;
		}
	}
}
int main() {
	int i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		E[a].push_back(b);
		E[b].push_back(a);
		S[a] -= c, S[b] += c;
	}
	for (i = 1; i <= n; i++) {
		if (!vis[i]) {
			T.clear();
			DFS(i);
			Go();
		}
	}
	printf("%d\n", Ed.size());
	for (auto &z : Ed) {
		printf("%d %d %lld\n", z.a, z.b, z.c);
	}
}