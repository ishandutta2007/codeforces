#include<cstdio>
int n,m,m1,m2,m3,t=0,edge_t=1,ans_t=1;
int la[1000002]={},deg[1000002]={};
struct aaa
{
	int to,nx,u,vis;
}edge[4000002];
struct bbb
{
	int num,t;
}ans[2000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x],1,0},la[x]=edge_t,++deg[x];
	edge[++edge_t]=(aaa){x,la[y],1,0},la[y]=edge_t,++deg[y];
}
inline void dfs(int x,int y)
{
	for(int i=la[x];i;i=la[x])
	{
		la[x]=edge[i].nx;
		if(!edge[i].vis)edge[i].vis=edge[(i^1)].vis=1,dfs(edge[i].to,i);
	}
	ans[m1]=(bbb){y/2,ans_t},--m1;
}
int main()
{
	read(n),read(m),m2=m3=m;
	for(int i=1,x,y;i<=m;++i)read(x),read(y),add_edge(x,y);
	for(int i=1;i<=n;++i)if(deg[i]&1)add_edge(0,i),++m;
	m1=m;
	if(deg[0])dfs(0,0);
	else for(int i=1;i<=n;++i)if(la[i])dfs(i,0),++m1,++ans_t;
	for(int i=1;i<m;++i)
	{
		if(ans[i].num>m2)t=0;
		else if(ans[i].t==ans[i+1].t && ans[i+1].num<=m2)
		{
			if(t)edge[2*ans[i].num].u=0,--m3;
			t^=1;
		}
	}
	printf("%d\n",m3);
	for(int i=1;i<=m2;++i)if(edge[2*i].u)printf("%d %d\n",edge[2*i].to,edge[2*i+1].to);
	return 0;
}