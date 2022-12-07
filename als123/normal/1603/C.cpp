#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100005;
const int MOD=998244353;
int add (int x,int y)   {x=x+y;return x>=MOD?x-MOD:x;}
int mul (int x,int y)   {return (LL)x*y%MOD;}
int dec (int x,int y)   {x=x-y;return x<0?x+MOD:x;}
int Pow (int x,int y)
{
	int now=1;
	while (y){if (y&1) now=mul(now,x);x=mul(x,x);y>>=1;}
	return now;
}
int a[N];
int n;
int b[N];
int sum1,sum2;
int mx (int x)	{return a[x]%b[x]==0?a[x]/b[x]:a[x]/b[x]+1;}
int mn (int x)  {return a[x]/b[x];}
void get_nxt (int x)
{
	sum2=dec(sum2,mul(b[x]-1,x));
	int p=mx(x);
	p--;
	b[x]=a[x]/p;
	if (b[x]*p<a[x]) b[x]++;
	sum2=add(sum2,mul(b[x]-1,x));
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		int ans=0;
		sum1=0;sum2=0;
		for (int u=1;u<=n;u++)
		{
			scanf("%d",&a[u]);
			b[u]=1;
			for (int i=u-1;i>=1;i--)
			{
				if (mx(i)<=mn(i+1)) break; 
				while (mx(i)>mn(i+1))	
				{
					get_nxt(i);				
				}
			}
			/*printf("%d %d\n",sum1,sum2);
			for (int i=1;i<=u;i++) printf("%d ",b[i]-1);
			printf("\n");
			ans=add(ans,dec(mul(u,sum1),sum2));*/
			ans=add(ans,sum2);
		}
		printf("%d\n",ans);
	}
	return 0;
}