#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, K, i, BIT[1001000], st[1001000], top, w[1010000], L[1010000], R[1010000], ck[1010000];
void Add(int a){
	while (a <= n){
		BIT[a]++;
		a += (a&-a);
	}
}
int Sum(int a){
	int r = 0;
	while (a){
		r += BIT[a];
		a -= (a&-a);
	}
	return r;
}
int main()
{
	int a, B, E, M, r;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		ck[w[i]] = i;
	}
	for (i = 1; i <= K; i++){
		scanf("%d", &a);
		ck[a] = 0;
	}
	for (i = n; i >= 1; i--){
		if (!ck[w[i]]){
			while (top && w[st[top]] > w[i])top--;
			st[++top] = i;
		}
		else{
			if (!top || w[st[1]] > w[i]){
				R[i] = n;
				continue;
			}
			B = 1, E = top;
			while (B <= E){
				M = (B + E + 1) >> 1;
				if (w[st[M]] < w[i])r = st[M], B = M + 1;
				else E = M - 1;
			}
			R[i] = r - 1;
		}
	}
	top = 0;
	for (i = 1; i <= n; i++){
		if (!ck[w[i]]){
			while (top && w[st[top]] > w[i])top--;
			st[++top] = i;
		}
		else{
			if (!top || w[st[1]] > w[i]){
				L[i] = 1;
				continue;
			}
			B = 1, E = top;
			while (B <= E){
				M = (B + E + 1) >> 1;
				if (w[st[M]] < w[i])r = st[M], B = M + 1;
				else E = M - 1;
			}
			L[i] = r + 1;
		}
	}
	for (i = 1; i <= n; i++){
		if (!ck[w[i]]) Add(i);
	}
	long long res = 0;
	for (i = n; i >= 1; i--){
		if (!ck[i])continue;
		Add(ck[i]);
		res = res + Sum(R[ck[i]]) - Sum(L[ck[i]] - 1);
	}
	printf("%lld\n", res);
}