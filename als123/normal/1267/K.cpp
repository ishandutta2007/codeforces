#include <iostream>
#include <cmath>
#include <cstdio>
#define LL long long

const int maxn=25;

using namespace std;

int T,m,d;
LL n,ans,sum;
int a[maxn];
LL c[maxn][maxn];

int main()
{
	c[0][0]=1;
	for (int i=1;i<=20;i++)
	{
		c[i][0]=1;
		for (int j=1;j<=i;j++) c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	scanf("%d",&T);
	while (T--)
	{
		for (int i=0;i<=20;i++) a[i]=0;
		scanf("%lld",&n);
		d=1;
		while (n)
		{
			d++;
			a[n%d]++;
			n/=d;
		}
		ans=0;
		for (int j=d-1;j>0;j--)
		{
			if (a[j])
			{
				sum=1;
				a[j]--;
				m=d-2;
				for (int i=d-1;i>=0;i--)
				{
					int p;
					if (i==0) p=m;
					     else p=m-i+1;
					if (p>=a[i]) sum=sum*c[p][a[i]];
					        else sum=0;
					m-=a[i];
				}
				a[j]++;
				ans+=sum;
			}
		}
		printf("%lld\n",ans-1);
	}
}