#include<cstdio>
int N,K;
int main()
{
	scanf("%d%d",&N,&K);
	if(K>=N*(N-1)/2)
	{
		puts("no solution");
		return 0;	
	}
	for(int i=0;i<N;i++)
		printf("0 %d\n",i);
	return 0;
}