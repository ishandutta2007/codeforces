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
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

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
const int N = int(2e3)+10;
VI g[N],rg[N];
VI order,cmpNodes[N];int vis[N],comp[N],curr;
//g:graph,rg:reverse graph 
void dfs1(int u){
  vis[u]=1;
  for(auto w:g[u])
    if(!vis[w])dfs1(w);	
  order.PB(u);}
void dfs2(int u){
  vis[u]=1;comp[u]=curr;cmpNodes[curr].PB(u);
  for(auto w:rg[u])
    if(!vis[w])dfs2(w);}
void SCC(int n){
  SET(vis,0);order.clear();
  REP(i,n)if(!vis[i])dfs1(i);
  SET(vis,0);reverse(ALL(order));curr=0;
  //components are generated in topological order
  for(auto u:order)
  if(!vis[u])cmpNodes[++curr].clear(),dfs2(u);
}//2-SAT : N = 2*maxvars+10,M = N/2,0-based
int val[N];int var(int x){return x<<1;}
int NOT(int x){return x^1;}
bool solvable(int vars){
  SCC(2*vars);
  REP(i,vars)
    if(comp[var(i)]==comp[NOT(var(i))])
      return false;
  return true;
}
void assign_vars(){
  SET(val,0);
  for(int i=1;i<=curr;i++)
    for(auto it : cmpNodes[i]){
      int u = it>>1;
      if(val[u])continue;
      val[u] = (it&1?+1:-1);
    }
}
void add_edge(int v1,int v2){g[v1].PB(v2);rg[v2].PB(v1);}
void add_imp(int v1,int v2){add_edge(v1,v2);add_edge(1^v2,1^v1);}
void add_equiv(int v1,int v2){add_imp(v1,v2);add_imp(v2,v1);}
void add_or(int v1,int v2){add_edge(1^v1,v2);add_edge(1^v2,v1);}
void add_xor(int v1,int v2){add_or(v1, v2);add_or(1^v1,1^v2);}
void add_true(int v1){add_edge(1^v1, v1);}
void add_and(int v1,int v2){add_true(v1);add_true(v2);}

char s[2][N][30];
string fname(int x){
  string ret = "";
  REP(i,3)ret += s[0][x][i];
  return ret;
}
string lname(int x){
  string ret = "";
  REP(i,2)ret += s[0][x][i];
  ret += s[1][x][0];
  return ret;
}
int main()
{
  int n;si(n);
  REP(i,n)
    REP(t,2)
      scanf("%s",s[t][i]);
  REP(i,n)FOR(j,i+1,n){
    string f1 = fname(i);
    string f2 = fname(j);
    string l1 = lname(i);
    string l2 = lname(j);
    if(f1 == f2)add_or(NOT(var(i)),NOT(var(j)));
    if(f1 == l2)add_or(NOT(var(i)),var(j));
    if(l1 == f2)add_or(var(i),NOT(var(j)));
    if(l1 == l2)add_or(var(i),var(j));
    if(f1 == f2){
      add_equiv(NOT(var(i)),NOT(var(j)));
    }
  }
  if(!solvable(n))return puts("NO");
  puts("YES");
  assign_vars();
  REP(i,n)
    cout<<(val[i]==1?fname(i):lname(i))<<"\n";
	return 0;
}