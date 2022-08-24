#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 1048576
using namespace std;
int MM[SZ+1];
struct Tree {
	int IT[SZ + SZ], K[SZ + SZ];
	void UDT(int nd) {
		IT[nd] = max(IT[nd * 2], IT[nd * 2 + 1]);
	}
	void init(int nd, int b, int e) {
		K[nd] = 0;
		if (b == e) {
			IT[nd] = -MM[b];
			return;
		}
		int m = (b + e) >> 1;
		init(nd * 2, b, m);
		init(nd * 2 + 1, m + 1, e);
		UDT(nd);
	}
	void Add2(int nd, int x) {
		IT[nd] += x, K[nd] += x;
	}
	void Spread(int nd) {
		Add2(nd * 2, K[nd]);
		Add2(nd * 2 + 1, K[nd]);
		K[nd] = 0;
	}
	void Add(int nd, int b, int e, int s, int l, int x) {
		if (s > l)return;
		if (s <= b && e <= l) {
			Add2(nd, x);
			return;
		}
		Spread(nd);
		int m = (b + e) >> 1;
		if (s <= m)Add(nd * 2, b, m, s, l, x);
		if (l > m)Add(nd * 2 + 1, m + 1, e, s, l, x);
		UDT(nd);
	}
}T;
int n, m, K, M2[SZ+1];
struct AA {
	int x, c;
};
vector<AA>G[SZ];
int main() {
	int i;
	scanf("%d%d%d", &n, &m, &K);
	for (i = 0; i <= SZ; i++)M2[i] = MM[i] = 2e9;
	for (i = 1; i <= n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		MM[a] = min(MM[a], b);
	}
	for (i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		M2[a] = min(M2[a], b);
	}
	for (i = 1; i <= K; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		G[b].push_back({ a,c });
	}
	T.init(1, 1, SZ);
	long long res = -2e9;
	for (i = 1; i < SZ; i++) {
		if (M2[i] < 2e9) {
			long long s = T.IT[1];
			s -= M2[i];
			res = max(res, s);
		}
		for (auto &t : G[i]) {
			T.Add(1, 1, SZ, t.x + 1, SZ, t.c);
		}
	}
	printf("%lld\n", res);
}