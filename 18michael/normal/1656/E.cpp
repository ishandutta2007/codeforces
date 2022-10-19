#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,edge_t,Test_num,mx;
int la[1000002],deg[1000002],ans[1000002];
struct aaa
{
	int to,nx;
}edge[2000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,++deg[x];
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t,++deg[y];
}
inline void dfs(int x,int f,int d)
{
	//printf("DFS %d %d %d\n",x,f,d);
	if(deg[x]==1)
	{
		ans[x]=d;
		return ;
	}
	ans[x]=d-(1-d)*(deg[x]-1);//
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x,1-d);
}
int main()
{
	//freopen("E.in","r",stdin);
	//freopen("E.out","w",stdout);
	read(Test_num);
	while(Test_num--)
	{
		read(n),edge_t=0,mx=1;
		for(int i=1;i<=n;++i)la[i]=deg[i]=0;
		for(int i=1,x,y;i<n;++i)read(x),read(y),add_edge(x,y);
		for(int i=2;i<=n;++i)if(deg[i]>deg[mx])mx=i;
		ans[mx]=deg[mx]+1;
		for(int i=la[mx];i;i=edge[i].nx)dfs(edge[i].to,mx,-1);
		for(int i=1;i<=n;++i)printf("%d%c",ans[i],i==n? '\n':' ');
	}
	return 0;
}