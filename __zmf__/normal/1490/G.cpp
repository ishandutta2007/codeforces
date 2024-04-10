#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=200009;
long long taxi,cnt,n,m,maxn,a[N],x[N],sum[N],ans[N],tt[N];
struct point
{
	long long id,val;
}p[N];
inline long long work(long long pp)
{
	int pos1=lower_bound(tt+1,tt+cnt+1,pp)-tt;
	return p[pos1].id;
}
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		sum[0]=0,cnt=1,maxn=0;
		n=read(),m=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=m;i++)x[i]=read();
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i],maxn=max(maxn,sum[i]);
		p[1].id=1,p[1].val=sum[1];
		for(int i=2;i<=n;i++)
		{
			if(sum[i]>p[cnt].val)p[++cnt].id=i,p[cnt].val=sum[i];
		}
		for(int i=1;i<=cnt;i++)tt[i]=p[i].val;
		for(int i=1;i<=m;i++)
		{
			if(sum[n]<=0&&maxn<x[i])printf("-1 ");
			else if(maxn>=x[i])printf("%lld ",work(x[i])-1);
			else 
			{
				long long qwq=(x[i]-maxn+sum[n]-1)/sum[n];
				printf("%lld ",qwq*n+work(x[i]-qwq*sum[n])-1);
			}
		}
		puts("");
	}
	return 0;
}