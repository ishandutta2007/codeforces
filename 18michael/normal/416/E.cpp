#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,edge_t=0,ans;
int X[125002],Y[125002],Z[125002],la[502]={};
int dis[502][502],cnt[502][502]={};
struct aaa
{
	int to,nx,val;
}edge[250002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void Floyd()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;++i)
	{
		dis[i][i]=0;
		for(int j=i+1;j<=n;++j)dis[i][j]=dis[j][i]=inf;
	}
	for(int i=1;i<=m;++i)read(X[i]),read(Y[i]),read(Z[i]),add_edge(X[i],Y[i],Z[i]),dis[X[i]][Y[i]]=dis[Y[i]][X[i]]=Z[i];
	Floyd();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=la[j],v;k;k=edge[k].nx)
			{
				v=edge[k].to;
				if(dis[i][v]+edge[k].val==dis[i][j])++cnt[i][j];
			}
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
		{
			ans=0;
			for(int k=1;k<=n;++k)
				if(dis[i][k]+dis[k][j]==dis[i][j])
					ans+=cnt[i][k];
			printf("%d ",ans);
		}
	return 0;
}