#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, K;
struct Edge {
	int a, b, c;
	bool operator < (const Edge &p)const {
		return c < p.c;
	}
}w[301000];
int UF[201000], chk[201000];
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
int main() {
	int i, a;
	scanf("%d%d%d", &n, &m, &K);
	for (i = 0; i < K; i++) {
		scanf("%d", &a);
		chk[a] = 1;
	}
	for (i = 0; i < m; i++) {
		scanf("%d%d%d", &w[i].a, &w[i].b, &w[i].c);
	}
	for (i = 1; i <= n; i++)UF[i] = i;
	sort(w, w + m);
	int M = 0;
	for (i = 0; i < m; i++) {
		int a = Find(w[i].a), b = Find(w[i].b);
		if (a != b) {
			if(chk[a]&&chk[b])M = w[i].c;
			chk[b] |= chk[a];
			UF[a] = b;
		}
	}
	for (i = 0; i < K; i++)printf("%d ", M);
}