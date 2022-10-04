#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
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
const int MAXN=205,MAXV=40505,MAXE=1000505,DIR[4][2]={0,1,1,0,0,-1,-1,0},INF=0x3f3f3f3f;

int n,a[MAXN][MAXN];
bool bl(int x,int y){return x==1 || x==n || y==1 || y==n;}
int src,sink;
struct Edge{int v,f;};
int etot;
Edge e[MAXE];
vector<int> G[MAXV];
void addEdge(int u,int v,int f)
{
	int p=etot++,q=etot++;
	e[p].v=v,e[p].f=f,G[u].pb(p);
	e[q].v=u,e[q].f=0,G[v].pb(q);
}
int level[MAXV],q[MAXV];
bool bfs()
{
	memset(level,-1,sizeof(int)*(sink+5));
	int front=1,rear=0;
	level[src]=1;q[++rear]=src;
	while(front<=rear)
	{
		int u=q[front++];
		for(auto i:G[u])
			if(e[i].f && level[e[i].v]<0)
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
			if(t)
			{
				key-=t,res+=t;
				e[i].f-=t,e[i^1].f+=t;
				if(!key)break;
			}
		}
	if(!res)level[u]=-1;
	return res;
}
int dinic()
{
	int res=0;
	while(bfs())res+=dfs(src,INF);
	return res;
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	vector<pii> p;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			readint(a[i][j]);
			if(bl(i,j))p.pb(mp(i,j));
		}
	sort(p.begin(),p.end(),[&](pii u,pii v){return a[u.x][u.y]<a[v.x][v.y];});
	ll res=0;
	for(int j=1;j<n;++j)res+=abs(a[1][j+1]-a[1][j]);
	for(int i=1;i<n;++i)res+=abs(a[i+1][n]-a[i][n]);
	for(int j=1;j<n;++j)res+=abs(a[n][j+1]-a[n][j]);
	for(int i=1;i<n;++i)res+=abs(a[i+1][1]-a[i][1]);
	etot=0;src=n*n+1,sink=n*n+2;
	for(int i=1;i<=n*n+2;++i)G[i].clear();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			if(a[i][j]==-1)continue;
			for(int d=0;d<4;++d)
			{
				int x=i+DIR[d][0],y=j+DIR[d][1];
				if(x<=0 || x>n || y<=0 || y>n || a[x][y]==-1)continue;
				if(!bl(i,j) || !bl(x,y))addEdge(i*n+j-n,x*n+y-n,1);
			}
			if(bl(i,j))addEdge(i*n+j-n,sink,INF);
		}
	int cur=0;
	for(int k=0;k<p.size()-1;++k)
	{
		int i=p[k].x,j=p[k].y;
		addEdge(src,i*n+j-n,INF);
		addEdge(src,i*n+j-n,INF);
/*for(int i=1;i<=sink;++i)
{
	cerr<<i<<": ";
	for(auto j:G[i])cerr<<"("<<e[j].v<<","<<e[j].f<<") ";
	cerr<<endl;
}*/
		cur+=dinic()-INF;
		res+=1ll*cur*(a[p[k+1].x][p[k+1].y]-a[p[k].x][p[k].y]);
	}
	printf("%lld\n",res);
	return 0;
}