#include<cstdio>
#include<algorithm>
int w[1<<23], P[1<<23], UF[1<<23], Q[1<<22];
int n, m;
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
void Merge(int a, int b) {
	a = Find(a), b = Find(b);
	if (a != b)UF[a] = b;
}
int main() {
	int i, j;
	scanf("%d%d", &n,&m);
	for (i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
		UF[i] = i;
		P[(1 << n) - 1 - w[i]] = i;
		Q[w[i]] = i;
	}
	for (i = 0; i < (1 << n); i++) {
		if (Q[i])continue;
		for (j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				if (Q[i ^ (1 << j)])Q[i] = Q[i ^ (1 << j)];
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = (1 << n) - 1; j >= 0; j--) {
			if (!P[j])continue;
			if (Q[j])Merge(P[j], Q[j]);
			if ((j >> i) & 1) {
				int x = j ^ (1 << i);
				if (!P[x])P[x] = P[j];
				else if(Q[x]){
					Merge(P[x], P[j]);
				}
			}
		}
	}
	int res = 0;
	for (i = 1; i <= m; i++)if (Find(i) == i)res++;
	printf("%d\n", res);
}