#include<cstdio>
#include<algorithm>
using namespace std;
int n, K, L[101000], R[101000], w[101000], res;
int main() {
	int i;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++)L[i] = 1e9, R[i] = -1;
	for (i = 1; i <= K; i++) {
		scanf("%d", &w[i]);
		R[w[i]] = i;
		if (L[w[i]] > K)L[w[i]] = i;
	}
	for (i = 1; i <= n; i++) {
		if (L[i] > K)res++;
		if (i > 1 && L[i] > R[i - 1])res++;
		if (i < n && L[i] > R[i + 1])res++;
	}
	printf("%d\n", res);
}