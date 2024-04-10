#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define pii pair<int,int>
int n, C[1010], D[1010], cur, dd;
vector<int>E[1010];
void DFS(int a, int pp) {
	C[a] = 1;
	for (auto &x : E[a]) {
		if (x == pp)continue;
		DFS(x, a);
		C[a] += C[x];
	}
}
void Put(int a, int pp) {
	cur+=dd;
	printf("%d %d %d\n", a, pp, cur - D[pp]);
	D[a] = cur;
	for (auto &x : E[a]) {
		if (x != pp)Put(x, a);
	}
}
int main() {
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, 0);
	int Mn = 1e9, mid = -1;
	for (i = 1; i <= n; i++) {
		if (C[i] * 2 > n&&Mn > C[i]) {
			Mn = C[i];
			mid = i;
		}
	}
	DFS(mid, 0);
	vector<pii>T;
	for (auto &x : E[mid]) {
		T.push_back({ C[x],x });
	}
	sort(T.begin(), T.end());
	int sum = 0, sz = T.size(), pv = -1;
	Mn = 1e9;
	for (i = 0; i < sz; i++) {
		sum += T[i].first;
		if (abs(sum - n / 2) < Mn) {
			Mn = abs(sum - n / 2);
			pv = i;
		}
	}
	dd = 1;
	for (i = 0; i <= pv; i++) {
		Put(T[i].second, mid);
	}
	dd = cur + 1;
	cur = 0;
	for (i = pv + 1; i < sz; i++) {
		Put(T[i].second, mid);
	}
}