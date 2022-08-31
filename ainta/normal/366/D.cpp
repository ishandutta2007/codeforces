#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, UF[3010], res;
struct point {
	int x, y, b, e;
	bool operator <(const point &p)const {
		return b != p.b ? b < p.b : e < p.e;
	}
}w[3010];
struct Seg {
	int e, a, b;
	bool operator < (const Seg &p)const {
		return e < p.e;
	}
}E[3010];
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d%d%d",&w[i].x,&w[i].y, &w[i].b, &w[i].e);
	}
	sort(w, w + m);
	for (i = 0; i < m; i++) {
		int cnt = 0;
		for (j = 1; j <= n; j++)UF[j] = j;
		for (j = 0; j <= i; j++)E[cnt++] = { w[j].e, w[j].x,w[j].y };
		sort(E, E + cnt);
		for (j = cnt - 1; j >= 0; j--) {
			int a = Find(E[j].a), b = Find(E[j].b);
			if (a != b)UF[a] = b;
			if (Find(1) == Find(n))break;
		}
		if (j != -1) {
			res = max(res, E[j].e - w[i].b + 1);
		}
	}
	if (!res) {
		puts("Nice work, Dima!");
		return 0;
	}
	printf("%d\n", res);
}