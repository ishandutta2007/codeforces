#include<cstdio>
#include<bitset>
#include<algorithm>
#include<queue>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,p,edge_t=0,ans=inf;
int X[152],Y[152],Z[152],id[152],la[152]={},dis[152];
queue<int> q;
struct Vector
{
	bitset<152> a;
}V;
struct Matrix
{
	bitset<152> a[152];
	inline void init(bool x)
	{
		for(int i=1;i<=n;++i)a[i].reset(),a[i][i]=x;
	}
}M,tmp;
struct aaa
{
	int to,nx;
}edge[302];
inline bool cmp(int x,int y)
{
	return Z[x]<Z[y]? 1:0;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
}
inline Vector mulv(Vector a,Matrix b)
{
	Vector c;c.a.reset();
	for(int i=1;i<=n;++i)
		if(a.a[i])
			c.a|=b.a[i];
	return c;
}
inline Matrix mul(Matrix a,Matrix b)
{
	Matrix c;c.init(0);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(a.a[i][j])
				c.a[i]|=b.a[j];
	return c;
}
inline Matrix Pow(Matrix a,int b)
{
	tmp.init(1);
	while(b)
	{
		if(b&1)tmp=mul(tmp,a);
		a=mul(a,a),b>>=1;
	}
	return tmp;
}
int main()
{
	scanf("%d%d",&n,&m),V.a[1]=1;
	for(int i=1;i<=m;++i)scanf("%d%d%d",&X[i],&Y[i],&Z[i]),id[i]=i;
	sort(id+1,id+m+1,cmp);
	for(int i=1,j;i<=m;i=j)
	{
		V=mulv(V,Pow(M,Z[id[i]]-Z[id[i-1]]));
		for(j=i;j<=m && Z[id[j]]==Z[id[i]];++j)add_edge(X[id[j]],Y[id[j]]),M.a[X[id[j]]][Y[id[j]]]=1;
		for(int j=1;j<=n;++j)if(V.a[j])dis[j]=Z[id[i]],q.push(j);else dis[j]=-1;
		while(!q.empty())
		{
			p=q.front(),q.pop();
			for(int j=la[p],v;j;j=edge[j].nx)
				if(!(~dis[v=edge[j].to]))
					dis[v]=dis[p]+1,q.push(v);
		}
		if(~dis[n])ans=min(ans,dis[n]);
	}
	if(ans<inf)printf("%d",ans);
	else puts("Impossible");
	return 0;
}