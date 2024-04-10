#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
/*const int MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
int inv(int x){return qmi(x,MOD-2);}*/
const int MAXN=105,MAXE=100005,INF=0x3f3f3f3f;

int n,m,k,x[MAXN],y[MAXN],au[MAXE],av[MAXE];
struct Edge
{
	int v,f;
};
Edge e[MAXE];
vector<int> G[MAXN];
int etot;
void addEdge(int u,int v,int f)
{
	int p=etot++,q=etot++;
	e[p].v=v,e[p].f=f,G[u].pb(p);
	e[q].v=u,e[q].f=0,G[v].pb(q);
}
int src,sink,level[MAXN],q[MAXN];
bool bfs()
{
	memset(level,-1,sizeof(level));
	int front=1,rear=0;
	q[++rear]=src;level[src]=1;
	while(front<=rear)
	{
		int u=q[front++];
		for(auto i:G[u])
			if(e[i].f && level[e[i].v]==-1)
				level[e[i].v]=level[u]+1,q[++rear]=e[i].v;
		if(level[sink]>0)return 1;
	}
	return 0;
}
int dfs(int u,int key)
{
	if(u==sink)return key;
	int res=0;
	for(auto i:G[u])
		if(e[i].f && level[e[i].v]==level[u]+1)
		{
			int t=dfs(e[i].v,min(key,e[i].f));
			key-=t,res+=t;
			e[i].f-=t,e[i^1].f+=t;
			if(!key)break;
		}
	if(!res)level[u]=-1;
	return res;
}
vector<int> b;
vector<int> al[MAXN];
int cu[MAXN];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m),readint(k);
	for(int i=1;i<=m;++i)readint(au[i]),readint(av[i]);
	int g=INF;
	vector<int> b;
	for(int j=0;j<=2*n;++j)
	{
		cu[j]=1;
		etot=0;
		for(int i=1;i<=m;++i)addEdge(av[i],au[i]+n,INF);
		src=2*n+1,sink=2*n+2;
		for(int i=1;i<=n;++i)addEdge(src,i,1-cu[i]),addEdge(i+n,sink,1-cu[i+n]);
		int l=0;
		while(bfs())l+=dfs(src,INF);
		if(j)
		{
			if(l<g)b.pb(j<=n?-j:j-n),g=l;
			else cu[j]=0;
		}
		else g=l;
	}
	g=b.size();
	for(int i=1;i<=k;++i)readint(x[i]),readint(y[i]);
	ll best=-1;int pos=0;
	for(int i=1;i<=k+1;++i)
	{
		ll sum=0;int h=g,my=INF;
		for(int j=1;j<i;++j)
		{
			sum+=x[j];
			chkmin(my,y[j]);
			while(h>=n-j)--h,sum-=my;
		}
		for(int j=i+1;j<=k;++j)
			sum+=x[j];
		if(sum>best)best=sum,pos=i;
	}
	int h=g,my=INF,py=0;
	for(int j=1;j<pos;++j)
	{
		if(chkmin(my,y[j]))py=j;
		while(h>=n-j)--h,al[py].pb(b.back()),b.pop_back();
	}
	al[pos]=b;
	vector<int> res;
	for(int i=1;i<=k;++i)
	{
		for(auto j:al[i])res.pb(j);
		res.pb(0);
	}
	printf("%d\n",res.size());
	for(auto i:res)printf("%d ",i);
	return 0;
}