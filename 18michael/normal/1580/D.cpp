#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,st_t,rt;
int ls[4002]={},rs[4002]={},st[4002],siz[4002]={},fa[4002];
LL a[4002];
LL f[4002][4002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void dfs(int x)
{
	if(!x)return ;
	dfs(ls[x]),dfs(rs[x]),siz[x]=min(siz[ls[x]]+siz[rs[x]]+1,m);
	for(int i=0;i<=siz[ls[x]];++i)
		for(int j=0;j<=siz[rs[x]];++j)
			f[x][i+j]=max(f[x][i+j],f[ls[x]][i]+f[rs[x]][j]),f[x][i+j+1]=max(f[x][i+j+1],f[ls[x]][i]+f[rs[x]][j]);
	for(int i=0;i<=siz[x];++i)f[x][i]+=(a[x]-a[fa[x]])*i*(m-i);
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;++i)read(a[i]);
	st_t=0;
	for(int i=1;i<=n;++i)
	{
		while(st_t && a[i]<a[st[st_t]])ls[i]=st[st_t],--st_t;
		if(ls[i])fa[ls[i]]=i;
		st[++st_t]=i;
	}
	st_t=0;
	for(int i=n;i;--i)
	{
		while(st_t && a[i]<=a[st[st_t]])rs[i]=st[st_t],--st_t;
		if(rs[i])fa[rs[i]]=i;
		st[++st_t]=i;
	}
	for(int i=1;i<=n;++i)
		if(!fa[i])
		{
			rt=i;
			break;
		}
	dfs(rt),printf("%lld",f[rt][m]);
	return 0;
}