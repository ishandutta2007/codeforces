#include<stdio.h>
int n, w[210], deg[210], D[210], Q[210], h, t, x, M;
bool v[210];
long long G = 1;
long long gcd(long long a, long long b){
	return b ? gcd(b, a%b) : a;
}
int main()
{
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		deg[w[i]]++;
	}
	for (i = 1; i <= n; i++){
		if (!deg[i])Q[++t] = i;
	}
	while (h < t){
		x = Q[++h];
		deg[w[x]]--;
		if (D[w[x]] < D[x] + 1)D[w[x]] = D[x] + 1;
		if (!deg[w[x]]){
			Q[++t] = w[x];
		}
	}
	for (i = 1; i <= n; i++)if (M < D[i])M = D[i];
	for (i = 1; i <= n; i++){
		if (deg[i] && !v[i]){
			x = i;
			t = 0;
			while (1){
				if (v[x])break;
				t++;
				v[x] = true;
				x = w[x];
			}
			G = G / gcd(G, t)*t;
		}
	}
	if (G < M){
		G = G*((M - 1) / G + 1);
	}
	printf("%lld\n", G);
}