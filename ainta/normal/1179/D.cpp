#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long C[501000];
int n;
long long D[501000], Res=1e18;
vector<int>E[501000];
struct point {
	long long A, B, C, D;
	bool operator <(const point &p)const {
		return C < p.C;
	}
};
point st[501000];
int top;
bool Over(point a, point b, point c) {
	return (b.B - a.B)*(a.A - c.A) <= (c.B - a.B)*(a.A - b.A);
}
void Put(point a) {
	while (top > 1 && Over(st[top - 1], st[top], a))top--;
	st[++top] = a;
}
long long Calc(point a, long long x) {
	return a.A*x + a.B;
}
void Calc(vector<point>&T) {
	if (T.size() < 2)return;
	sort(T.begin(), T.end());
	int sz = T.size(), i, j;
	top = 0;
	for (i = 0; i < sz; i++) {

		long long K = n - T[i].C;
		while (top > 1 && Calc(st[top], K) >= Calc(st[top - 1], K)) top--;
		if (top) {
			Res = min(Res,(Calc(st[top], K) + K * K + 2 * T[i].D) / 2);
		}

		Put(T[i]);
	}
}
void DFS(int a, int pp) {
	C[a] = 1;
	int ck = 0;
	D[a] = 1e18;
	for (auto &x : E[a]) {
		if (x == pp)continue;
		ck = 1;
		DFS(x, a);
		C[a] += C[x];
	}
	if (!ck) {
		D[a] = 0;
		return;
	}
	vector<point>TP;
	for (auto &x : E[a]) {
		if (x == pp)continue;
		long long t = C[a] - C[x];
		D[a] = min(D[a], D[x] + t * (t - 1) / 2);
		long long c = C[x] * (C[x] + 1) + 2 * D[x];
		TP.push_back({ -(C[x] + C[x] + 1), c,C[x], D[x] });
	}
	Calc(TP);
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
	Res = min(Res, D[1]);
	long long t = 1ll * n*(n - 1) / 2;
	printf("%lld\n", t * 2 - Res);
}