#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,Test_num,edge_t;
int a[100002],b[100002],id[100002],la[100002];
bool u[100002];
struct aaa
{
	int to,nx;
}edge[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	return a[x]>a[y]? 1:0;
}
inline bool cmp1(int x,int y)
{
	return b[x]>b[y]? 1:0;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
}
inline void dfs(int x)
{
	u[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)if(!u[v=edge[i].to])dfs(v);
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),edge_t=0;
		for(int i=1;i<=n;++i)read(a[i]),la[id[i]=i]=u[i]=0;
		for(int i=1;i<=n;++i)read(b[i]);
		sort(id+1,id+n+1,cmp);for(int i=2;i<=n;++i)add_edge(id[i],id[i-1]);
		sort(id+1,id+n+1,cmp1);for(int i=2;i<=n;++i)add_edge(id[i],id[i-1]);
		dfs(id[1]);for(int i=1;i<=n;++i)printf("%d",u[i]);puts("");
	}
	return 0;
}