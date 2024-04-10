#include<cstdio>
#include<algorithm>
#define SZ 1048576
using namespace std;
struct SegTree {
	int Mn[SZ + SZ], K[SZ + SZ];
	void Add2(int nd, int x) {
		Mn[nd] += x;
		K[nd] +=x;
	}
	void Spread(int nd) {
		Add2(nd * 2, K[nd]);
		Add2(nd * 2 + 1, K[nd]);
		K[nd] = 0;
	}
	void UDT(int nd) {
		Mn[nd] = min(Mn[nd * 2], Mn[nd * 2 + 1]);
	}
	void Add(int nd, int b, int e, int s, int l, int x) {
		if (s > l)return;
		if (s <= b && e <= l) {
			Add2(nd, x);
			return;
		}
		int m = (b + e) >> 1;
		Spread(nd);
		if (s <= m)Add(nd * 2, b, m, s, l, x);
		if (l > m)Add(nd * 2 + 1, m + 1, e, s, l, x);
		UDT(nd);
	}
	int Calc(int nd, int b, int e) {
		if (b == e)return b;
		int m = (b + e) >> 1;
		Spread(nd);
		if (Mn[nd * 2 + 1] < 0)return Calc(nd * 2 + 1, m + 1, e);
		return Calc(nd * 2, b, m);
	}
}T;
int n, m, A[301000], B[301000], Q;
int main() {
	int i, a;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		T.Add(1, 0, SZ - 1, 0, A[i], -1);
	}
	for (i = 1; i <= m; i++) {
		scanf("%d", &B[i]);
		T.Add(1, 0, SZ - 1, 0, B[i], 1);
	}
	scanf("%d", &Q);
	while (Q--) {
		int ck, b;
		scanf("%d%d%d", &ck, &a, &b);
		if (ck == 1) {
			T.Add(1, 0, SZ - 1, 0, A[a], 1);
			A[a] = b;
			T.Add(1, 0, SZ - 1, 0, A[a], -1);
		}
		else {
			T.Add(1, 0, SZ - 1, 0, B[a], -1);
			B[a] = b;
			T.Add(1, 0, SZ - 1, 0, B[a], 1);
		}
		if (T.Mn[1] >= 0)puts("-1");
		else printf("%d\n", T.Calc(1, 0, SZ - 1));
	}
}