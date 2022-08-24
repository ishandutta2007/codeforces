#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[101000], res, L, K;
int U[101000];
int main() {
	int i;
	scanf("%d%d%d", &n, &L, &K);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (i = 1; i < n; i++)U[i] = w[i + 1] - w[i] - 1;
	sort(U + 1, U + n);
	res = n;
	for (i = 1; i <= n-K; i++) {
		res += U[i];
	}
	printf("%d\n", res);
}