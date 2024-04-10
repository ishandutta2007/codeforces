#include <bits/stdc++.h>
#define MAXN 1005

using namespace std;

int main ()
{
	int N, K;
	scanf("%d %d",&N,&K);
	int A, B, C, D;
	scanf("%d %d %d %d",&A,&B,&C,&D);
	if ((N == 4) || (K < (N+1)))
	{
		printf("-1\n");
		return 0;
	}
	static char b[MAXN];
	memset(b,1,sizeof(b));
	b[A] = 0; b[B] = 0; b[C] = 0; b[D] = 0;
	int f = 1;
	while (!b[f]) f++;
	int l = N;
	while (!b[l]) l--;
	printf("%d %d",A,C);
	int i;
	for (i = 1; i <= N; i++)
	{
		if (b[i]) printf(" %d",i);
	}
	printf(" %d %d\n",D,B);
	printf("%d %d",C,A);
	for (i = 1; i <= N; i++)
	{
		if (b[i]) printf(" %d",i);
	}
	printf(" %d %d\n",B,D);
	return 0;	
}