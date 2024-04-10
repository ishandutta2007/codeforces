//Mobius_Treap
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
const int N = int(1e5)+10;
VII g[N];
typedef pair<II,pair<II,II> > state;
int vis[N];
set<state> S;
int P[N];
int W[N];
#define prev prevv
int prev[N];
state mp(int nvertices,int ptime,int weight,int nedges,int node,int p)
{
	return MP(MP(nvertices,ptime),MP(MP(weight,nedges),MP(node,p)));
}
int dist[N];
int pp[N];
void bfs(int x)
{
	queue<int> Q;
	Q.push(x);
	dist[x]=0;
	pp[x]=x;
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		S.insert(mp(0,0,0,dist[u],u,pp[u]));
		for(int i=0;i<SZ(g[u]);i++)
		{
			int w = g[u][i].F;
			int weight = g[u][i].S;
			if(weight==0 && !vis[w])
			{
				dist[w]=dist[u]+1;
				vis[w]=1;
				pp[w]=u;
				Q.push(w);
			}
		}
	}
}
int main()
{
	int n,m;
	si(n);si(m);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		si(u);si(v);si(w);
		g[u].PB(MP(v,w));
		g[v].PB(MP(u,w));
	}
	int s=0,d=n-1;
	bfs(d);
	//state mp(int nvertices,int ptime,int weight,int nedges,int node,int p)
	int T=0;
	SET(vis,0);
	//prev[0]=d;
	int last=-1;
	while(!S.empty())
	{
		state top = *S.begin();
		S.erase(S.begin());
		int u = top.S.S.F;
		int p = top.S.S.S;
		int wt = top.S.F.F;
		int nvrtx = top.F.F;
		int ne = top.S.F.S;
		if(vis[u])continue;
		if(last == -1 || prev[P[last]]!=prev[p] || (prev[P[last]]==prev[p] && wt != W[last]))
			T++;
		last = u;
		vis[u]=1;
		P[u]=p;
		W[u]=wt;
		for(int i=0;i<SZ(g[u]);i++)
		{
			int w = g[u][i].F;
			int weight = g[u][i].S;
			S.insert(mp(nvrtx+1,T,weight,ne,w,u));
		}
	}
	VI ans;
	ans.PB(s);
	VI tans;
	tans.PB(W[s]);
	while(P[s]!=s)
	{
		s = P[s];
		ans.PB(s);
		tans.PB(W[s]);
	}
	while(tans.back()==0 && SZ(tans)>1)
		tans.pop_back();
	reverse(ALL(tans));
	for(int i=0;i<SZ(tans);i++)
		printf("%d",tans[i]);
	printf("\n");
	dout(SZ(ans));
	for(int i=0;i<SZ(ans);i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}