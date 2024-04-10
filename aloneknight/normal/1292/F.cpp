#include<bits/stdc++.h>
using namespace std;
const int N=65,S=4096,P=1e9+7;
int n,m,a[N],id[N],fa[N],C[N][N],msk[N],g[S],f[N][S];
int fnd(int x){return fa[x]==x?x:fa[x]=fnd(fa[x]);}
inline int gts(int x)
{
	int ans=-1;
	for(int i=1;i<=n;i++)if(fa[i]==x)ans+=id[i]==-1;
	return max(ans,0);
}
inline int calc(int x)
{
	int cnt=gts(x)+1,m=0;if(cnt==1)return 1;
	for(int i=1;i<=n;i++)if(fa[i]==x&&~id[i])id[i]=++m,msk[i]=0;
	memset(f,0,sizeof(f));memset(g,0,sizeof(g));
	for(int i=1;i<=n;i++)if(fa[i]==x&&id[i]==-1)
	{
		for(int j=1;j<=n;j++)if(fa[j]==x&&~id[j]&&a[i]%a[j]==0)msk[i]|=1<<(id[j]-1);
		for(int j=0;j<(1<<m);j++)g[j]+=(msk[i]|j)==j;
	}
	for(int i=1;i<=n;i++)if(fa[i]==x&&id[i]==-1)f[1][msk[i]]++;
	for(int i=1;i<=cnt-1;i++)for(int j=0;j<(1<<m);j++)if(f[i][j])
	{
		int w=f[i][j];f[i+1][j]=(f[i+1][j]+1ll*w*(g[j]-i))%P;
		for(int k=1;k<=n;k++)if(fa[k]==x&&id[k]==-1&&(msk[k]&j)&&(msk[k]|j)!=j)f[i+1][j|msk[k]]=(f[i+1][j|msk[k]]+w)%P;
	}
	return f[cnt][(1<<m)-1];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),fa[i]=i;
	sort(a+1,a+n+1);
	for(int i=0;i<=n;i++)for(int j=C[i][0]=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
	for(int i=1;i<=n;i++)if(~id[i])
	{
		bool ff=0;
		for(int j=i+1;j<=n;j++)if(a[j]%a[i]==0){ff=1;id[j]=-1;fa[fnd(i)]=fnd(j);}
		if(ff)id[i]=++m;else id[i]=-1;
	}
	for(int i=1;i<=n;i++)fa[i]=fnd(i);
	int ans=1,cnt=0;
	for(int i=1;i<=n;i++)if(fa[i]==i){ans=1ll*ans*calc(i)%P*C[cnt+gts(i)][cnt]%P;cnt+=gts(i);}
	printf("%d\n",ans);return 0;
}