//Tanuj Khattar
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
const int N = int(3e5)+10;
const int M = int(3e5)+10;
VII tree[N];
VI g[N];//edge list representation of graph
int U[M],V[M],W[M],vis[N],arr[N],T,cmpno,A[N],C[N];
bool isbridge[M]; // if i'th edge is a bridge edge or not 
queue<int> Q[N];
int adj(int u,int e){
  return U[e]==u?V[e]:U[e];
}
int dfs0(int u,int edge = -1){ //mark bridges
  vis[u]=1;arr[u]=T++;
  int dbe = arr[u];
  for(int i=0;i<SZ(g[u]);i++){
    int e = g[u][i];int w = adj(u,e);
    if(!vis[w])dbe = min(dbe,dfs0(w,e));
    else if(e!=edge)dbe = min(dbe,arr[w]);
  }
  if(dbe == arr[u] && edge!=-1)isbridge[edge]=true;
  return dbe;
}
void dfs1(int v){//Build the bridge tree
  int currcmp = cmpno; 
  Q[currcmp].push(v);vis[v]=1;
  while(!Q[currcmp].empty()){
    int u = Q[currcmp].front();Q[currcmp].pop();C[u]=currcmp;   
    for(int i=0;i<SZ(g[u]);i++){
      int e = g[u][i];int w = adj(u,e);
      if(vis[w])continue;
      if(isbridge[e]){cmpno++;
        tree[currcmp].push_back({cmpno,W[e]});
        tree[cmpno].push_back({currcmp,W[e]});
        dfs1(w);
      }
      else Q[currcmp].push(w),vis[w]=1;
    }
  }
}
int go(int s,int d)
{
	s=C[s];d=C[d];
	queue<II> Q;SET(vis,0);
	Q.push({s,0});vis[s]=1;
	while(!Q.empty())
	{
		int u = Q.front().F, status = Q.front().S|A[u];Q.pop();
		if(u==d)return status;
		for(int i=0;i<SZ(tree[u]);i++)
			if(!vis[tree[u][i].F])
			{
				vis[tree[u][i].F]=1;
				Q.push({tree[u][i].F,status|tree[u][i].S});
			}
	}
	assert(false);//shouldn't come here :) 
	return 0;
}
int main()
{
	int n,m;
	si(n);si(m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",U+i,V+i,W+i);
		g[U[i]].PB(i);
		g[V[i]].PB(i);
	}
	int s,d;
	si(s);si(d);
	dfs0(1);SET(vis,0);dfs1(1);
	for(int i=0;i<m;i++)
		if(C[U[i]]==C[V[i]])
			A[C[U[i]]]|=W[i];
	puts(go(s,d)?"YES":"NO");
	return 0;
}