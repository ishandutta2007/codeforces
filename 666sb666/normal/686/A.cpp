#include<cstdio>
long long n,x,ans;
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
	{
		char ch;
		int d;
		scanf(" %c",&ch);
		scanf("%d",&d);
		if(ch=='+')x+=d;
		else
		{
			if(x<d)ans++;
			else x-=d;
		}
	}
	printf("%lld %lld\n",x,ans);
	return 0;
}