#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int w[100010], n, a;
long long D[100010];
int main()
{
	int i;
	scanf("%d", &n);
	while (n--){
		scanf("%d", &a);
		w[a]++;
	}
	
	for (i = 100000; i >= 1; i--){
		if (w[i]){
			D[max(i - 1, 1)] = max(D[max(i - 1, 1)], max(D[i + 2], D[i + 1]) + (long long)w[i] * i);
		}
		D[i] = max(D[i], D[i + 1]);
	}
	printf("%lld\n", D[1]);
}