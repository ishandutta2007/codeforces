#include<cstdio>
#include<algorithm>
using namespace std;
struct A {
	int a, b;
	bool operator <(const A &p)const {
		return a < p.a;
	}
}P[101000], Q[101000];
int n, m, R[101000];
int main() {
	int i;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &P[i].a);
		P[i].b = i;
	}
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &Q[i].a, &Q[i].b);
	}
	sort(P + 1, P + n + 1);
	sort(Q + 1, Q + m + 1);
	int pv = 1, s = 0;
	for (i = 1; i <= n; i++) {
		while (pv <= m && Q[pv].a <= P[i].a) {
			s += Q[pv].b;
			pv++;
		}
		R[P[i].b] = s;
	}
	for (i = 1; i <= n; i++)printf("%d ", R[i]);
}