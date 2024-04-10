#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
long long S, w[110], M;
int main()
{
	int n, m, i, a;
	scanf("%d%d", &n,&m);
	for (i = 1; i <= n; i++){
		scanf("%lld", &w[i]);
		S += w[i];
	}
	for (i = 1; i <= m; i++){
		scanf("%d", &a);
		S -= w[a];
		if (M < w[a]) M = w[a];
	}
	if (S < M) S = S + M, m--;
	while (m--){
		S = S * 2LL;
	}
	printf("%lld\n", S);
}