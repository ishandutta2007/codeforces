#include<bits/stdc++.h>
#define Mx 29
#define LL long long
#define mod 1000000007
using namespace std;
int n,now,to_t=1,val=0;
LL res,m,tmp,ans=0;
int a[50002],cnt[1500002],t[50002],t1[50002],mx[1500002];
int to[1500002][2];
int pre[50002][32][2];
int main()
{
	scanf("%d%lld",&n,&m),m<<=1,tmp=m;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		now=t[i]=t1[i]=1;
		for(int j=Mx,c;~j;--j)
		{
			if(!to[now][c=((a[i]>>j)&1)])to[now][c]=(++to_t);
			++cnt[now=to[now][c]],mx[now]=i,pre[i][j][0]=pre[i-1][j][0],pre[i][j][1]=pre[i-1][j][1],++pre[i][j][(a[i]>>j)&1];
		}
	}
	for(int i=Mx;~i;--i)
	{
		res=0;
		for(int j=1;j<=n;++j)res+=cnt[to[t1[j]][((a[j]>>i)&1)^1]];
		if(tmp<=res)
		{
			val|=(1<<i);
			for(int j=1;j<=n;++j)t1[j]=to[t1[j]][((a[j]>>i)&1)^1];
		}
		else
		{
			tmp-=res;
			for(int j=1;j<=n;++j)t1[j]=to[t1[j]][(a[j]>>i)&1];
		}
		for(int j=1;j<=n;++j)t[j]=to[t[j]][(a[j]>>i)&1];
	}
	for(int i=1;i<=n;++i)t[i]=1;
	for(int i=Mx;~i;--i)
	{
		if(!((val>>i)&1))
		{
			for(int j=1,x;j<=n;++j)
			{
				m-=cnt[x=to[t[j]][((a[j]>>i)&1)^1]];
				for(int k=0;k<=i;++k)(ans+=((LL)(pre[mx[x]][k][((a[j]>>k)&1)^1]-pre[mx[x]-cnt[x]][k][((a[j]>>k)&1)^1])<<k))%=mod;
			}
		}
		else (ans+=((LL)m<<i))%=mod;
		for(int j=1;j<=n;++j)t[j]=to[t[j]][(((a[j]^val)>>i)&1)];
	}
	return 0&printf("%lld",(ans*(mod+1)/2)%mod);
}