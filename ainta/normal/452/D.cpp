#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int K, w[10010];
int n[3], t[3], c;
int main()
{
	int i, j;
	scanf("%d", &K);
	for (i = 0; i < 3; i++)scanf("%d", &n[i]);
	for (i = 0; i < 3; i++)scanf("%d", &t[i]);
	for (i = 0; i < K; i++){
		c = 0;
		if (i >= n[0])c = max(c, w[i - n[0]] + t[0]);
		if (i >= n[1])c = max(c, w[i - n[1]] + t[1]);
		if (i >= n[2])c = max(c, w[i - n[2]] + t[2]);
		w[i] = c;
	}
	printf("%d\n", w[K - 1] + t[0] + t[1] + t[2]);
}