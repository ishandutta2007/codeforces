#include<bits/stdc++.h>
using namespace std;
int n,m,mn=1,num_t=0,edge_t=0,ans;
int la[100002]={},num[100002]={},deg[100002]={},id[642],rt[642];
int E[642][642]={};
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
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,++deg[x];
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t,++deg[y];
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
int main()
{
	read(n),read(m);
	for(int i=1,x,y;i<=m;++i)read(x),read(y),add_edge(x,y);
	for(int i=2;i<=n;++i)if(deg[i]<deg[mn])mn=i;
	for(int i=la[mn];i;i=edge[i].nx)num[edge[i].to]=(++num_t),id[num_t]=edge[i].to,rt[num_t]=num_t;
	ans=num_t;
	for(int i=0;i<num_t;++i)
	{
		if(i)
		{
			for(int j=la[id[i]];j;j=edge[j].nx)E[i][num[edge[j].to]]=1;
			for(int j=i+1;j<=num_t;++j)
				if(!E[i][j])
				{
					getroot(i),getroot(j);
					if(rt[i]!=rt[j])rt[rt[i]]=rt[j],--ans;
				}
		}
		else
		{
			for(int j=i+1;j<=num_t;++j)E[i][j]=n-num_t;
			for(int k=1;k<=n;++k)if(!num[k])for(int j=la[k];j;j=edge[j].nx)--E[i][num[edge[j].to]];
			for(int j=i+1;j<=num_t;++j)
				if(E[i][j])
				{
					getroot(i),getroot(j);
					if(rt[i]!=rt[j])rt[rt[i]]=rt[j],--ans;
				}
		}
	}
	return 0&printf("%d",ans);
}