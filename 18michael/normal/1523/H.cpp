#include<bits/stdc++.h>
#define K 30
#define Mx 14
#define eps 1e-9
using namespace std;
int n,q,ans;
bool ok;
int a[20002],to[K+2],tmp[K+2];
int g[Mx+2][20002];
int f[Mx+2][K+2][20002];
inline int merge(int x,int y)
{
	return x+a[x]>y+a[y]? x:y;
}
inline int getg(int l,int r)
{
	int len=log2(r-l+1)+eps;
	return merge(g[len][l],g[len][r-(1<<len)+1]);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]=min(a[i],n-i),g[0][i]=i;
	for(int i=1;i<=Mx;++i)for(int j=1;j+(1<<i)-1<=n;++j)g[i][j]=merge(g[i-1][j],g[i-1][j+(1<<(i-1))]);
	for(int i=0;i<=K;++i)for(int j=1;j<=n;++j)f[0][i][j]=min(max(i? f[0][i-1][j]+1:0,j+i<=n? j+i+a[j+i]:n),n);
	for(int i=0;i<=K;++i)for(int j=1;j<=n;++j)f[0][i][j]=getg(j,f[0][i][j]);
	for(int j=1,x;j<=Mx;++j)for(int i=0;i<=K;++i)for(int k=1;k<=n;++k)for(int l=0;l+i<=K;++l)f[j][l+i][k]=merge(f[j][l+i][k],f[j-1][i][f[j-1][l][k]]);
	for(int l,r,k;q--;printf("%d\n",ans))
	{
		scanf("%d%d%d",&l,&r,&k),ans=0;
		if(l==r)continue;
		++ans;
		if(l+a[l]+k>=r)continue;
		ok=1,++ans;
		for(int i=0;i<=k;++i)
		{
			to[i]=getg(l,min(l+a[l]+i,n));
			if(to[i]+a[to[i]]+k-i>=r)
			{
				ok=0;
				break;
			}
		}
		if(!ok)continue;
		for(int i=Mx;~i;--i)
		{
			if(to[k]+(1<<i)>=r)continue;
			ok=1;
			for(int j=0;j<=k;++j)
			{
				tmp[j]=0;
				for(int o=0;o<=j;++o)tmp[j]=merge(tmp[j],f[i][o][to[j-o]]);
			}
			for(int j=0;j<=k;++j)
				if(tmp[j]+a[tmp[j]]+k-j>=r)
				{
					ok=0;
					break;
				}
			if(!ok)continue;
			ans+=(1<<i);
			for(int j=0;j<=k;++j)to[j]=tmp[j];
		}
		++ans;
	}
	return 0;
}