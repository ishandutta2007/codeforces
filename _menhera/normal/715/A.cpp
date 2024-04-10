#include<cstdio>
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1; i<=N; i++)
	{
		long long ans = 1LL*i*(i+1)*(i+1)-(i-1);
		if(i==1) ans = 2;
		printf("%lld\n",ans);
	}
}