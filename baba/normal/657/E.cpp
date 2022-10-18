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

//#define TRACE

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
const int N = int(6e5)+10;
const int M = int(6e5)+10;
const int LOGN = 20;
VI tree[N],g[2][N];//edge list representation of graph
int U[2][M],V[2][M],vis[N],arr[2][N],T,cmpno,C[2][N],dep[N],DP[LOGN][N],level[N],A[N],comp[N];
bool isbridge[M]; // if i'th edge is a bridge edge or not 
int t;
int adj(int u,int e){
	return U[t][e]==u?V[t][e]:U[t][e];
}
int dfs0(int u,int edge){ //mark bridges
	vis[u]=1;arr[t][u]=T++;
	int dbe = arr[t][u];
	for(int i=0;i<SZ(g[t][u]);i++){
		int e = g[t][u][i];int w = adj(u,e);
		if(!vis[w])dbe = min(dbe,dfs0(w,e));
		else if(e!=edge)dbe = min(dbe,arr[t][w]);
	}
	if(dbe == arr[t][u] && edge!=-1)isbridge[edge]=true;
	return dbe;
}
void dfs1(int u){//Build the bridge tree
	vis[u]=1;C[t][u]=cmpno;
	for(auto e:g[t][u])
		if(!isbridge[e] && !vis[adj(u,e)])
			dfs1(adj(u,e));
}
void buildBridgeTree(int n,int m)
{
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs0(i,-1);
	SET(vis,0);
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs1(i),cmpno++;
	for(int i=0;i<m;i++)
		if(C[t][U[t][i]]!=C[t][V[t][i]])
			tree[C[t][U[t][i]]].PB(C[t][V[t][i]]),
				tree[C[t][V[t][i]]].PB(C[t][U[t][i]]);
}
//Bridge Tree done 
//Pre-Process the forest
int c;
void dfs2(int u,int p)
{
	arr[0][u]=T++;vis[u]=1;DP[0][u]=p;
	level[u]=level[p]+1;comp[u]=c;
	for(auto w:tree[u])
		if(!vis[w])
			dfs2(w,u);
	dep[u]=T++;
}
void preProcess(int n)
{
	T = 0;c = 0;
	SET(vis,0);
	for(int i=0;i<n;i++)
		if(!vis[i])
			dfs2(i,i),c++;
	for(int i=1;i<LOGN;i++)
		for(int j=0;j<n;j++)
			DP[i][j]=DP[i-1][DP[i-1][j]];
}
int lca(int a,int b)
{
	if(comp[a]!=comp[b])return -1;
	if(level[a]>level[b])swap(a,b);
	int d = level[b]-level[a];
	for(int i=0;i<LOGN;i++)
		if((1<<i)&d)
			b = DP[i][b];
	if(a==b)return a;
	for(int i=LOGN-1;i>=0;i--)
		if(DP[i][a]!=DP[i][b])
			a=DP[i][a],b=DP[i][b];
	return DP[0][a];
}
//Q[]: array containing k nodes of auxillary tree
//arr[] : arrival time of nodes
//anc(p,u) : returns true if p is ancestor of u
//VI tree[N] : final auxillary tree with O(k) nodes
int Q[N],k;
int anc(int p,int u)
{
	return arr[0][u]>=arr[0][p] && dep[u]<=dep[p];
}
bool cmp(int u,int v){
	return arr[0][u]<arr[0][v];
}
void create_tree(int &m){//return root of tree
	set<int> S;//get distinct nodes 
	for(int i=0;i<k;i++)S.insert(Q[i]);k=0;
	for(auto it=S.begin();it!=S.end();it++)Q[k++]=*it;
	sort(Q,Q+k,cmp);int kk = k;//distinct initial nodes
	//add lca of adjacent pairs
	for(int i=0;i<kk-1;i++){
		int x = lca(Q[i],Q[i+1]);
		if(x==-1)continue;
		if(S.count(x))continue;
		Q[k++]=x;S.insert(x);
	}
	sort(Q,Q+k,cmp);
	stack<int> s;
	for(int i=0;i<k;i++){
		while(!s.empty() && !anc(s.top(),Q[i]))s.pop();
		if(s.empty())
			s.push(Q[i]);
		else
		{
			U[t][m]=s.top();V[t][m]=Q[i];
			g[t][s.top()].PB(m);
			g[t][Q[i]].PB(m);
			m++;s.push(Q[i]);
		}
	}
}
//check biconnectivity in final tree
bool go(int n,int m)
{
	for(int i=0;i<k;i++)vis[Q[i]]=0;
	for(int i=0;i<m;i++)isbridge[i]=false;
	T=0;
	for(int i=0;i<k;i++)
		if(!vis[Q[i]])
			dfs0(Q[i],-1);
	for(int i=0;i<k;i++)vis[Q[i]]=0;
	cmpno=0;
	for(int i=0;i<k;i++)
		if(!vis[Q[i]])
			dfs1(Q[i]),cmpno++;
	bool ok=true;
	for(int i=0;i<n;i++)
		if(C[t][A[i]]!=C[t][A[0]])
			ok=false;
	for(int i=0;i<k;i++)g[t][Q[i]].clear();
	return ok;
}

//For input 
int R,n,m,q;
int rotate(int element)
{
	element=(element+R)%n;
	if (element==0) {
		element=n;
	}
	return element;
}
int main()
{
	t=0;si(n);si(m);si(q);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",U[t]+i,V[t]+i);
		g[t][U[t][i]].PB(i);
		g[t][V[t][i]].PB(i);
	}
	buildBridgeTree(n,m);
	preProcess(cmpno);
	t=1;
	for(int qq=1;qq<=q;qq++)
	{
		int nn,mm;k=0;
		si(nn);si(mm);
		for(int i=0;i<nn;i++)
		{
			si(A[i]);A[i]=rotate(A[i]);
			Q[k++]=A[i];A[i]=C[0][A[i]];
		}
		for(int i=0;i<mm;i++)
		{
			scanf("%d %d",U[t]+i,V[t]+i);
			U[t][i]=rotate(U[t][i]);
			V[t][i]=rotate(V[t][i]);
			Q[k++]=U[t][i];Q[k++]=V[t][i];
			U[t][i]=C[0][U[t][i]];V[t][i]=C[0][V[t][i]];
		}
		for(int i=0;i<k;i++)Q[i]=C[0][Q[i]];
		for(int i=0;i<mm;i++)
		{
			g[t][U[t][i]].PB(i);
			g[t][V[t][i]].PB(i);
		}
		create_tree(mm);
		bool ok = go(nn,mm);
		puts(ok?"YES":"NO");
		if(ok)R=(R+qq)%n;
	}
	return 0;
}