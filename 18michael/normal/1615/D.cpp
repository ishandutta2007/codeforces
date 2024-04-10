#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,n2,m,Test_num,edge_t,e_t,dfn_t,st_t,rt_t;
int X[400002],Y[400002],Z[400002],A[400002],B[400002],C[400002],la[400002],lae[400002],val[400002],dfn[400002],low[400002],rt[400002],st[400002];
bool ins[400002];
struct aaa
{
	int to,nx,val;
}edge[1000002];
struct bbb
{
	int to,nx;
}e[2000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int lowbit(int x)
{
	return x&(-x);
}
inline int calc(int x)
{
	int y=0;
	while(x)y^=1,x^=lowbit(x);
	return y;
}
inline int num(int x,int y)
{
	return x+y*n;
}
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void add_e(int x,int y,int z)
{
	e[++e_t]=(bbb){y,lae[x]},lae[x]=e_t;
	if(z)e[++e_t]=(bbb){x,lae[y]},lae[y]=e_t;
}
inline void dfs(int x,int f)
{
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			if(~edge[i].val)add_e(num(x,0),num(v,edge[i].val),1),add_e(num(x,1),num(v,edge[i].val^1),1);
			dfs(v,x);
		}
}
inline void Tarjan(int x)
{
	dfn[x]=low[x]=(++dfn_t),st[++st_t]=x,ins[x]=1;
	for(int i=lae[x],v;i;i=e[i].nx)
	{
		if(!dfn[v=e[i].to])Tarjan(v),low[x]=min(low[x],low[v]);
		else if(ins[v])low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x])
	{
		++rt_t;
		while(ins[x])rt[st[st_t]]=rt_t,ins[st[st_t]]=0,--st_t;
	}
}
inline void dfs1(int x,int f)
{
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			if(!(~Z[(i+1)>>1]))Z[(i+1)>>1]=(val[x]^val[v]);
			dfs1(v,x);
		}
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m),n2=(n<<1),edge_t=e_t=dfn_t=st_t=rt_t=0;
		for(int i=1;i<=n;++i)la[i]=0;
		for(int i=1;i<=n2;++i)lae[i]=ins[i]=dfn[i]=0;
		for(int i=1;i<n;++i)read(X[i]),read(Y[i]),read(Z[i]),add_edge(X[i],Y[i],(~Z[i])? calc(Z[i]):-1);
		dfs(1,0),add_e(num(1,1),num(1,0),0);
		for(int i=1;i<=m;++i)read(A[i]),read(B[i]),read(C[i]),add_e(num(A[i],0),num(B[i],C[i]),1),add_e(num(A[i],1),num(B[i],C[i]^1),1);
		for(int i=1;i<=n2;++i)if(!dfn[i])Tarjan(i);
		for(int i=1;i<=n;++i)
		{
			if(rt[i]==rt[i+n]){puts("NO");goto QAQ;}
			val[i]=(rt[i]>rt[i+n]);
		}
		for(int i=1;i<=m;++i)if((val[A[i]]^val[B[i]])!=C[i]){puts("NO");goto QAQ;}
		puts("YES");
		dfs1(1,0);for(int i=1;i<n;++i)printf("%d %d %d\n",X[i],Y[i],Z[i]);
		QAQ:;
	}
	return 0;
}