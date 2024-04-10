#include<bits/stdc++.h>
#define B 256
#define Mx 15
using namespace std;
int n,q,edge_t=0,tr_t=0,now,now1,ans;
int a[50002],la[50002],fa[50002],dep[50002],rt[50002],st[50002],mx[B],Fa[50002];
int F[50002][B];
struct aaa
{
	int to,nx;
}edge[100002];
struct bbb
{
	int cnt;
	int to[2];
}tr[500002];
inline int copy(int x)
{
	return tr[++tr_t]=tr[x],tr_t;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f,int d)
{
	fa[x]=f,dep[x]=d,now=rt[x]=copy(now1=rt[f]),st[d]=x;
	for(int i=Mx,c;i>7;--i)c=(a[x]>>i)&1,++tr[now=tr[now].to[c]=copy(now1=tr[now1].to[c])].cnt;
	if(d>=B)
	{
		Fa[x]=st[d-B];
		for(int i=0;i<B;++i)mx[i]=0;
		for(int i=d-B+1;i<=d;++i)mx[a[st[i]]>>8]=max(mx[a[st[i]]>>8],(a[st[i]]^(d-i))&(B-1));
		for(int i=0,c;i<B;++i)
		{
			now=rt[x],now1=rt[Fa[x]];
			for(int j=Mx;j>7;--j)
			{
				c=(i>>(j-8))&1;
				if(tr[tr[now].to[c^1]].cnt^tr[tr[now1].to[c^1]].cnt)now=tr[now].to[c^1],now1=tr[now1].to[c^1],F[x][i]|=(1<<j);
				else now=tr[now].to[c],now1=tr[now1].to[c];
			}
			F[x][i]|=mx[(F[x][i]>>8)^i];
		}
	}
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f)dfs(v,x,d+1);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0,1);
	for(int x,y,z;q--;)
	{
		scanf("%d%d",&x,&y),ans=0;
		for(z=y;dep[z]-dep[x]>=B-1;z=Fa[z])ans=max(ans,F[z][(dep[y]-dep[z])>>8]);
		for(;dep[z]>=dep[x];z=fa[z])ans=max(ans,a[z]^(dep[y]-dep[z]));
		printf("%d\n",ans);
	}
	return 0;
}