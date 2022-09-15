#include<cstdio>
#define MAXN 5000000
int div[5000100];
long long inc[5000100];
int main()
{
	for(int i=2;i<=MAXN;i++)
	{
		if(div[i]==0)
		{
			for(int j=i;j<=MAXN;j+=i)
			{
				int t=j;
				while(t%i==0)
				{
					div[j]++;
					t/=i;
				}
			}
		}
	}
	for(int i=1;i<=MAXN;i++)
		inc[i]=inc[i-1]+div[i];
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%lld\n",inc[a]-inc[b]);
	}
	return 0;
}