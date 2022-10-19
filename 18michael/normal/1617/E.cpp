#include<cstdio>
#include<map>
#include<cmath>
#include<set>
#define inf 0x3f3f3f3f
using namespace std;
int n,t=0,edge_t=0,ans=0,num1,num2;
int la[6000002]={},a[6000002];
bool u[6000002]={};
map<int,int> to;
typedef pair<int,int> P;
set<P> s;
struct aaa
{
	int to,nx;
}edge[6000002];
struct bbb
{
	int val,num;
}mx[6000002];
inline int fa(int x)
{
	int res=(1<<(int)(log2(x)));
	while(res<x)res<<=1;
	return res-x;
}
inline void add_edge(int x,int y)
{
	if(!to.count(x))to[x]=(++t);
	if(!s.count(P(x,y)))edge[++edge_t]=(aaa){to[y],la[to[x]]},la[to[x]]=edge_t,s.insert(P(x,y));
}
inline void dfs(int x)
{
	if(a[x])mx[x].val=0,mx[x].num=x;
	else mx[x].val=-inf;
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		dfs(v=edge[i].to),++mx[v].val;
		if(mx[v].val+mx[x].val>ans)ans=mx[v].val+mx[x].val,num1=mx[v].num,num2=mx[x].num;
		if(mx[v].val>mx[x].val)mx[x]=mx[v];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		if(!to.count(x))a[to[x]=(++t)]=i;
		while(x)add_edge(fa(x),x),x=fa(x);
	}
	dfs(to[0]),printf("%d %d %d",a[num1],a[num2],ans);
	return 0;
}