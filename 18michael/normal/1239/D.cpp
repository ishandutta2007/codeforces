#include<bits/stdc++.h>
using namespace std;
int n,m,edge_t,dfn_t,rt_t,st_t,cnt,Test_num;
int la[1000002],dfn[1000002],low[1000002],rt[1000002],st[1000002],deg[1000002];
struct aaa
{
	int to,nx;
}edge[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y)
{
	if(x!=y)edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
}
inline void init()
{
	edge_t=dfn_t=rt_t=st_t=cnt=0;
	for(int i=1;i<=n;++i)la[i]=dfn[i]=rt[i]=deg[i]=0;
}
inline void Tarjan(int x)
{
	dfn[x]=low[x]=(++dfn_t),st[++st_t]=x;
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		v=edge[i].to;
		if(!dfn[v])Tarjan(v),low[x]=min(low[x],low[v]);
		else if(!rt[v])low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x])
	{
		++rt_t;
		do rt[st[st_t]]=rt_t,--st_t;while(st[st_t+1]!=x);
	}
}
inline void solve()
{
	read(n),read(m),init();
	for(int i=1,x,y;i<=m;++i)read(x),read(y),add_edge(x,y);
	for(int i=1;i<=n;++i)if(!dfn[i])Tarjan(i);
	if(rt_t==1){puts("No");return ;}puts("Yes");
	for(int i=1;i<=n;++i)for(int j=la[i];j;j=edge[j].nx)deg[rt[i]]+=(rt[i]!=rt[edge[j].to]);
	for(int i=1;i<=rt_t;++i)if(!deg[i]){rt_t=i;break;}
	for(int i=1;i<=n;++i)if(rt[i]==rt_t)++cnt;printf("%d %d\n",cnt,n-cnt);
	for(int i=1;i<=n;++i)if(rt[i]==rt_t)printf("%d ",i);puts("");
	for(int i=1;i<=n;++i)if(rt[i]!=rt_t)printf("%d ",i);puts("");
}
int main()
{
	read(Test_num);
	while(Test_num--)solve();
	return 0;
}