#include<cstdio>
#include<algorithm>
using namespace std;
int n, K, w[101000], Mn = 1e9, pv;
int main() {
	int i, j;
	scanf("%d%d", &n,&K);
	for (i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	for (i = 0; i < K; i++) {
		int s = 0;
		for (j = i; j < n; j += K) {
			s += w[j];
		}
		if (Mn > s)Mn = s, pv = i;
	}
	printf("%d\n", pv + 1);
}