#include<cstdio>
#include<vector>
#define LL long long
using namespace std;
int n,m,l,mod,edge_t=0,st_t=0;LL ans=1;
int la[602]={},deg[602]={},deg1[602],st[602],id[602];
LL f[602][602]={},a[602][602],t[602][2];
vector<int> S,T;
struct aaa
{
	int to,nx;
}edge[100002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t,++deg[x],++deg1[y];
}
inline void Topo()
{
	for(int i=1;i<=n;++i)
	{
		if(!deg[i])st[++st_t]=i,T.push_back(i);
		if(!deg1[i])S.push_back(i);
		f[i][i]=1;
	}
	for(int p;st_t;)
	{
		p=st[st_t],--st_t;
		for(int i=la[p],v;i;i=edge[i].nx)
		{
			v=edge[i].to;
			for(int j=1;j<=n;++j)f[v][j]=(f[v][j]+f[p][j])%mod;
			if(!(--deg[v]))st[++st_t]=v;
		}
	}
}
inline void Work(int &x,int &y,int z)
{
	LL r,q;t[x][0]=t[y][0]=1,t[x][1]=t[y][1]=0;
	while(a[y][z])r=a[x][z]/a[y][z],a[x][z]=(a[x][z]-r*a[y][z])%mod,t[x][0]=(t[x][0]-r*t[y][1])%mod,t[x][1]=(t[x][1]-r*t[y][0])%mod,swap(x,y),ans*=-1;
	for(int i=z+1;i<=l;++i)r=a[x][i],q=a[y][i],a[x][i]=(t[x][0]*r+t[x][1]*q)%mod,a[y][i]=(t[y][0]*q+t[y][1]*r)%mod;
}
int main()
{
	scanf("%d%d%d",&n,&m,&mod);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	Topo(),l=S.size();
	for(int i=1;i<=l;++i)
	{
		id[i]=i;
		for(int j=1;j<=l;++j)
			a[i][j]=f[S[i-1]][T[j-1]];
	}
	for(int i=1;i<l;++i)
		for(int j=i+1;j<=l;++j)
			Work(id[i],id[j],i);
	for(int i=1;i<=l;++i)ans=(ans*a[id[i]][i])%mod;
	return 0&printf("%lld",(ans+mod)%mod);
}