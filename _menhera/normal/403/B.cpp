#include<cstdio>
#include<algorithm>
using namespace std;
int a[5005];
int p[5005];
int gc[5005];
int N,M;
int koosaga(int a)
{
	int res=0;
	for(int i=0;i<M;i++)
		while(a%p[i]==0)
		{
			a/=p[i];
			res--;
		}
	for(int i=2;i*i<=a;i++)
	{
		while(a%i==0)
		{
			a/=i;
			res++;
		}
	}
	if(a!=1) res++;
	return res;
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%d",a+i);
	for(int i=0;i<M;i++)
		scanf("%d",p+i);
	int g=a[0];
	int ans=0;
	for(int i=0;i<N;i++)
	{
		g=__gcd(g,a[i]);
		gc[i]=g;
	}
	int x=1;
	for(int i=N-1;i>=0;i--)
	{
		//printf("%d %d\n",gc[i],x);
		if(koosaga(gc[i]/x)<0)
		{
			for(int j=0;j<=i;j++) a[j]/=(gc[i]/x);
			x=gc[i];
		}
	}
	for(int i=0;i<N;i++)
	{
		//printf("%d ",a[i]);
		ans+=koosaga(a[i]);
	}
	printf("%d",ans);
}