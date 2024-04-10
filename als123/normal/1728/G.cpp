#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int K=20;
const int MOD=998244353;
const int MAX=1e9;
typedef long long LL;
int add (int x,int y){x=x+y;return x>=MOD?x-MOD:x;}
int dec (int x,int y){x=x-y;return x<0?x+MOD:x;}
int mul (int x,int y)	{return (LL)x*y%MOD;}
int Pow (int x,int y)
{
	int t=1;
	while (y)
	{
		if (y&1) t=mul(t,x);
		y>>=1;x=mul(x,x);
	}
	return t;
}
int d,n,m;
int l[N],p[N];
int sum[K][K];
int f[K];
int main()
{
	scanf("%d%d%d",&d,&n,&m);
	for (int u=1;u<=n;u++)	scanf("%d",&l[u]);
	sort(l+1,l+1+n);
	for (int u=1;u<=m;u++) scanf("%d",&p[u]);p[m+1]=MAX;p[0]=-MAX;
	sort(p+1,p+1+m);
	
	for (int u=0;u<=m;u++)
	for (int i=u+1;i<=m+1;i++)
	{
		sum[u][i]=1;
		for (int j=1;j<=n;j++)
		{
			if (l[j]>p[u]&&l[j]<p[i]) sum[u][i]=mul(sum[u][i],min(d+1,min(l[j]-p[u],p[i]-l[j])));
		}
	}
	int Q;
	scanf("%d",&Q);
	while (Q--)
	{
		int D;
		scanf("%d",&D);
		for (int u=0;u<=m+1;u++) f[u]=0;
		f[0]=1;
		for (int u=1;p[u]<D;u++)
			for (int i=0;i<u;i++)
				f[u]=dec(f[u],mul(f[i],sum[i][u]));
		f[m+1]=1;
		for (int u=m;p[u]>D;u--)
			for (int i=m+1;i>u;i--)
				f[u]=dec(f[u],mul(f[i],sum[u][i]));
	//	for(int j=0;j<=m+1;j++)cerr<<"j="<<j<<' '<<f[j]<<endl;
		int ans=0;
		for (int u=0;p[u]<D;u++)
			for (int i=m+1;p[i]>D;i--)
			{
			//	printf("%d %d %d\n",u,i,sum[u][i]);
				ans=add(ans,mul(min(d+1,min(D-p[u],p[i]-D)),mul(mul(f[u],f[i]),sum[u][i])));
			}
		printf("%d\n",ans);
	}
	return 0;
}