#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, U[24], Full, rr, MM = 1e9, M[2100000];
void Do(int pv, int cur, int mask) {
	int i;
	if (pv == n + 1) {
		if (mask != Full)return;
		int near = (cur & (-cur)), vis = 0;
		while (near != vis) {
			int vv = M[((near^vis)&(-(near^vis)))>>1];
			vis |= (1 << vv);
			near |= (U[vv] & cur);
		}
		if (vis == cur) {
			int c = 0;
			for (i = 1; i <= n; i++)if ((cur >> i) & 1)c++;
			if (MM > c)MM = c, rr = cur;
		}
		return;
	}
	Do(pv + 1, cur, mask);
	Do(pv + 1, cur | (1 << pv), mask | U[pv]);
}
int main() {
	int i, a, b;
	scanf("%d%d", &n,&m);
	if (m == n*(n - 1) / 2) {
		printf("0\n");
		return 0;
	}
	for (i = 0; i <= 21; i++)M[1 << i] = i + 1;
	for (i = 1; i <= n; i++)U[i] |= (1<<i);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		U[a] |= (1 << b);
		U[b] |= (1 << a);
	}
	for (i = 1; i <= n; i++)Full |= (1 << i);
	Do(1,0,0);
	printf("%d\n", MM);
	int near = rr & (-rr), vis = 0, cur = rr;
	while (near != vis) {
		int vv = M[((near^vis)&(-(near^vis))) >> 1];
		printf("%d ", vv);
		vis |= (1 << vv);
		near |= (U[vv] & cur);
	}
}