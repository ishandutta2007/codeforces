#include<cstdio>
int N;
int main()
{
	scanf("%d",&N);
	if(N%2==0)
	{
		puts("-1");
		return 0;
	}
	for(int i=0;i<N;i++)
		printf("%d ",i);
	puts("");
	for(int i=0;i<N;i++)
	{
		printf("%lld ",(1LL*i*(N/2))%N);
	}
	puts("");
	for(int i=0;i<N;i++)
	{
		printf("%lld ",(1LL*i*(N/2+1))%N);
	}
	puts("");
	return 0;
}