#pragma warning(disable:4996)
#include<stdio.h>
int n, par[1000010], D[1000010], D2[1000010], Last[21];
void Do(int M){
	int i, t;
	for (i = M; i != 1; i--){
		t = D[i];
		if (t < D2[i] + 1) t = D2[i] + 1;
		if (D[par[i]] < t)D2[par[i]]=D[par[i]], D[par[i]] = t;
		else if (D2[par[i]] < t)D2[par[i]] = t;
		D[i] = D2[i] = 0;
	}
}
int main()
{
	int i, j, B, E, M, pv;
	scanf("%d", &n);
	n++;
	for (i = 2; i <= n; i++){
		scanf("%d", &par[i]);
	}
	Last[0] = 1;
	for (i = 1;; i++){
		B = Last[i - 1] + 1, E = n;
		while (B <= E){
			M = (B + E) >> 1;
			Do(M);
			if (D[1] <= i){
				Last[i] = M;
				B = M + 1;
			}
			else E = M - 1;
			D[1] = D2[1] = 0;
		}
		if (Last[i] == n)break;
	}
	pv = 1;
	for (i = 2; i <= n; i++){
		while (Last[pv] < i)pv++;
		printf("%d ", pv);
	}
}