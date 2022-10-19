#include<bits/stdc++.h>
using namespace std;
int n,m,edge_t=0;
char c;
int la[102]={};
int ans[102][102][26];
struct aaa
{
	int to,nx;
	char ch;
}edge[10002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y,char c)
{
	edge[++edge_t]=(aaa){y,la[x],c},la[x]=edge_t;
}
inline bool solve(int x,int y,int z)
{
	if(~ans[x][y][z])return ans[x][y][z];
	if(!la[x])return ans[x][y][z]=0;
	for(int i=la[x];i;i=edge[i].nx)
		if(edge[i].ch-'a'>=z && !solve(y,edge[i].to,edge[i].ch-'a'))
			return ans[x][y][z]=1;
	return ans[x][y][z]=0;
}
int main()
{
	read(n),read(m);
	for(int i=1,x,y;i<=m;++i)
	{
		read(x),read(y);
		do c=getchar();while(c<'a' || c>'z');
		add_edge(x,y,c);
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=0;k<26;++k)
				ans[i][j][k]=-1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)putchar(solve(i,j,0)>0? 'A':'B');
		puts("");
	}
	return 0;
}