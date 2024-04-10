#include<cstdio>
#include<map>
#define LL long long
#define mod 100000000
using namespace std;
int n,m,k,n1,n2;LL ans=0,res;
int px[8],py[8],lg[66];
LL fac[14],pw[14];bool vis[14]={};
bool u[14][14]={},f[66][8];
map<LL,int> mp;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void init()
{
	fac[0]=pw[0]=1,lg[0]=0;
	for(int i=1;i<n2;++i)lg[i]=lg[(i>>1)]+1;
	for(int i=1;i<=max(k,n1);++i)fac[i]=fac[i-1]*i;
	for(int i=1;i<=n;++i)pw[i]=pw[i-1]*6;
}
inline int lowbit(int x)
{
	return x&(-x);
}
inline void dfs1(int x,int y,int z)
{
	if(x>n1)
	{
		if(!mp.count(y))mp[y]=1,res=fac[k]/fac[k-z],ans+=res;
		return ;
	}
	for(int i=min(z+1,k);i;--i)dfs1(x+1,y+(pw[px[x]-1]+pw[py[x]-1])*i,max(i,z));
}
inline void solve()
{
	for(int i=1;i<n2;++i)
		for(int j=1;j<=n1;++j)
			f[i][j]=0;
	for(int i=1;i<n2;++i)
	{
		if(i==lowbit(i))f[i][lg[i]]=u[px[lg[i]]][py[lg[i]]];
		for(int j=1;j<=n1;++j)
			if(((i>>(j-1))&1) && f[i][j])
				for(int k=1;k<=n1;++k)
					if(!((i>>(k-1))&1) && ((u[px[j]][px[k]] && u[py[j]][py[k]]) || (u[px[j]][py[k]] && u[py[j]][px[k]])))
						f[i|(1<<(k-1))][k]=1;
	}
	for(int i=1;i<=n1;++i)
		if(f[n2-1][i])
		{
			dfs1(1,0,0);
			break;
		}
}
inline void dfs(int x,int y)
{
	if(y>n1){solve();return ;}
	while(vis[x])++x;vis[px[y]=x]=1;
	for(int i=x+1;i<=n;++i)if(!vis[i])vis[py[y]=i]=1,dfs(x+1,y+1),vis[i]=0;
	vis[x]=0;
}
int main()
{
	read(n),read(m),read(k),n2=(1<<(n1=(n>>1))),init();
	for(int i=1,x,y;i<=m;++i)read(x),read(y),u[x][y]=u[y][x]=1;
	dfs(1,1);return 0&printf("%lld",ans);
}