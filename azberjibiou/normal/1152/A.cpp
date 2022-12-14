#include <bits/stdc++.h>
int A[100100]={}, B[100100]={};
int main()
{
	int i, j, N, M, a1=0, a2=0, b1=0, b2=0, ans=0;
	scanf("%d %d", &N, &M);
	for(i=0;i<N;i++)
	{
		scanf("%d", &A[i]);
		if(A[i]%2==0)
		a2++;
		else
		a1++;
	}
	for(i=0;i<M;i++)
	{
		scanf("%d", &B[i]);
		if(B[i]%2==0)
		b2++;
		else
		b1++;
	}
	if(a1>b2)
	ans+=b2;
	else
	ans+=a1;
	if(a2>b1)
	ans+=b1;
	else
	ans+=a2;
	printf("%d", ans);
}