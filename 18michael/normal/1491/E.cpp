#include<bits/stdc++.h>
#define Mx 26
#define LL long long
using namespace std;
int n,edge_t=0,col_t=0,t=0;
int la[200002]={},col[200002]={},siz[200002],fa[200002],fib[27]={1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418};
struct aaa
{
	int to,nx;
}edge[400002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f,int c)
{
	siz[x]=1,fa[x]=f;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && col[v]==c)
			dfs(v,x,c),siz[x]+=siz[v];
}
inline int dfs1(int x,int f,int c,int t)
{
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && col[v]==c)
		{
			if(siz[v]==fib[t-1] || siz[v]==fib[t-2])return v;
			if(v=dfs1(v,x,c,t))return v;
		}
	return 0;
}
inline void dfs2(int x,int f,int c1,int c2)
{
	col[x]=c2;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && col[v]==c1)
			dfs2(v,x,c1,c2);
}
inline bool check(int x,int c,int t)
{
	if(t<=3)return 1;
	int ct=c,c_t1,v,t1=t-1,t2=t-1;
	dfs(x,0,ct),v=dfs1(x,0,ct,t);
	if(!v)return 0;
	dfs2(v,fa[v],ct,(c_t1=(++col_t)));
	if(siz[v]==fib[t-1])--t1;
	else --t2;
	if(!check(x,ct,t1))return 0;
	if(!check(v,c_t1,t2))return 0;
	return 1;
}
int main()
{
	read(n);
	for(int i=1,x,y;i<n;++i)read(x),read(y),add_edge(x,y);
	for(int i=1;i<=Mx;++i)if(n==fib[i]){t=i;break;}
	if(!t)return 0&puts("NO");
	puts(check(1,0,t)? "YES":"NO");
	return 0;
}