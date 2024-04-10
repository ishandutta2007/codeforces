#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int w[100010];
int m, n;
long long res;
int main()
{
	int i, a, C;
	scanf("%d%d", &m, &n);
	for (i = 1; i <= n; i++){
		scanf("%d%d", &a, &w[i]);
	}
	sort(w + 1, w + n + 1);
	for (i = 1; i <= n; i++){
		if (i % 2 == 1){
			C = i*(i - 1) / 2 + 1;
		}
		else{
			C = i*(i - 1) / 2 + 1 + i / 2 - 1;
		}
		if (C > m)break;
		res = res +  w[n + 1 - i];
	}
	printf("%lld\n", res);
}