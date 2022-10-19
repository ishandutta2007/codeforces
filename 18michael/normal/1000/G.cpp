#include<cstdio>
#define Mx 18
#define LL long long
int n,q,edge_t=0,lax,lay;LL ans;
int a[300002],la[300002]={},dep[300002],vf[300002],siz[300002],son[300002],top[300002];
LL F[300002]={},G[300002]={},pre[300002]={};
int fa[300002][22];
struct aaa
{
	int to,nx,val;
}edge[600002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL max(LL x,LL y)
{
	return x>y? x:y;
}
inline void swap(int &x,int &y)
{
	int z=x;x=y,y=z;
}
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void dfs(int x,int f,int d)
{
	fa[x][0]=f,dep[x]=d,siz[x]=1,pre[x]+=a[x];
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs(v,x,d+1),siz[x]+=siz[v],F[x]+=max(F[v]+a[v]-2*edge[i].val,0),pre[v]-=(vf[v]=edge[i].val);
			if(siz[v]>siz[son[x]])son[x]=v;
		}
}
inline void dfs1(int x,int f,int t)
{
	top[x]=t,G[x]=F[x]+max(G[f]-max(F[x]+a[x]-2*vf[x],0)+a[f]-2*vf[x],0);
	if(son[x])pre[x]+=F[x]-max(F[son[x]]+a[son[x]]-2*vf[son[x]],0),pre[son[x]]+=pre[x],dfs1(son[x],x,t);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && v!=son[x])
			dfs1(v,x,v);
}
inline void get_LCA()
{
	for(int i=1;i<=Mx;++i)
		for(int j=1;j<=n;++j)
			fa[j][i]=fa[fa[j][i-1]][i-1];
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=Mx;~i;--i)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)return x;
	for(int i=Mx;~i;--i)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main()
{
	read(n),read(q);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1,x,y,z;i<n;++i)read(x),read(y),read(z),add_edge(x,y,z);
	dfs(1,0,1),dfs1(1,0,1),get_LCA();
	for(int x,y,z,X,Y;q--;)
	{
		read(x),read(y),lax=X=x,lay=Y=y,z=LCA(x,y),ans=0;
		if(son[x] && x!=z)ans+=max(F[son[x]]+a[son[x]]-2*vf[son[x]],0);
		if(son[y] && y!=z && x!=y)ans+=max(F[son[y]]+a[son[y]]-2*vf[son[y]],0);
		while(top[x]!=top[z])
		{
			if(dep[fa[top[x]][0]]>dep[z])ans-=max(F[top[x]]+a[top[x]]-2*vf[top[x]],0),ans+=max(F[son[fa[top[x]][0]]]+a[son[fa[top[x]][0]]]-2*vf[son[fa[top[x]][0]]],0);
			ans+=pre[x],lax=x,x=fa[top[x]][0];
		}
		while(top[y]!=top[z])
		{
			if(dep[fa[top[y]][0]]>dep[z])ans-=max(F[top[y]]+a[top[y]]-2*vf[top[y]],0),ans+=max(F[son[fa[top[y]][0]]]+a[son[fa[top[y]][0]]]-2*vf[son[fa[top[y]][0]]],0);
			ans+=pre[y],lay=y,y=fa[top[y]][0];
		}
		for(int i=Mx;~i;--i)if(dep[fa[lax][i]]>dep[z])lax=fa[lax][i];
		for(int i=Mx;~i;--i)if(dep[fa[lay][i]]>dep[z])lay=fa[lay][i];
		ans+=pre[x]-pre[z]+pre[y]-pre[z]+a[z]+G[z];
		if(lax!=z)ans-=max(F[lax]+a[lax]-2*vf[lax],0);
		if(lay!=z)ans-=max(F[lay]+a[lay]-2*vf[lay],0);
		printf("%lld\n",ans);
	}
	return 0;
}