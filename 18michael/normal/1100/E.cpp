#include<bits/stdc++.h>
using namespace std;
int n,m,l=0,r,mid,e_t=0,p,dfn_t=0;
int la[100002]={},lae[100002]={},val[200002],deg[100002]={},dfn[100002],x[200002],y[200002],z[200002];
bitset<100002> vis,ins;
queue<int> q;
vector<int> ans;
struct aaa
{
	int to,nx,val;
}edge[200002],e[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_e(int x,int y)
{
	e[++e_t]=(aaa){y,lae[x]},lae[x]=e_t,++deg[y];
}
inline bool dfs(int x,int y)
{
	vis[x]=ins[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if(edge[i].val>y && ((!vis[v=edge[i].to] && dfs(v,y)) || (vis[v] && ins[v])))
			return 1;
	return ins[x]=0;
}
inline bool check(int x)
{
	for(int i=1;i<=n;++i)vis[i]=ins[i]=0;
	for(int i=1;i<=n;++i)if(!vis[i] && dfs(i,x))return 0;
	return 1;
}
inline void Topo()
{
	for(int i=1;i<=n;++i)if(!deg[i])q.push(i),vis[i]=1;else vis[i]=0;
	while(!q.empty())
	{
		p=q.front(),q.pop(),dfn[p]=(++dfn_t);
		for(int i=lae[p],v;i;i=e[i].nx)if(!(--deg[v=e[i].to]))q.push(v),vis[v]=1;
	}
	for(int i=1;i<=n;++i)if(!vis[i])dfn[i]=(++dfn_t);
}
int main()
{
	read(n),read(m),r=m;
	for(int i=1;i<=m;++i)read(x[i]),read(y[i]),read(z[i]),edge[i]=(aaa){y[i],la[x[i]],z[i]},la[x[i]]=i,val[i]=z[i];
	sort(val+1,val+m+1);
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(check(val[mid]))r=mid-1;
		else l=mid+1;
	}
	for(int i=1;i<=m;++i)if(z[i]>val[l])add_e(x[i],y[i]);
	Topo();for(int i=1;i<=m;++i)if(dfn[x[i]]>dfn[y[i]])ans.push_back(i);
	printf("%d %d\n",val[l],ans.size());
	for(int i=0;i<ans.size();++i)printf("%d ",ans[i]);
	return 0;
}