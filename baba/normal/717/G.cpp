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
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
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

// min cost max ciculation for directed weighted graphs
// Configure: MAXE (at least 2 * calls_to_edge)
// - init(n) initializes the algorithm with the given number of nodes
// - addEdge(x, y, c, w) adds an edge x->y with capacity c and weight w
// - run() runs the algorithm and returns total cost
namespace Circu {
  const int MAXV = 1000100, MAXE = 1000100;
  int how[MAXV],good[MAXV],bio[MAXV],cookie=1,to[MAXE];
  int from[MAXE],V,E;LL cap[MAXE],cost[MAXE],dist[MAXV];
  void init(int n) { V = n; E = 0; }
  void AddEdge(int x, int y, LL c, LL w) {
    from[E]=x;to[E]=y;cap[E]=c;cost[E]=+w;++E;
    from[E]=y;to[E]=x;cap[E]=0;cost[E]=-w;++E;
  }void reset() {
    REP(i, V) dist[i]=0,how[i]=-1;
  }bool relax() {
    bool ret = false;
    REP(e, E)if (cap[e]) {
      int x = from[e],y = to[e];
      if(dist[x]+cost[e]<dist[y]){
        dist[y]=dist[x]+cost[e];
        how[y]=e;ret=true;
      }}return ret;
  }LL cycle(int s, bool flip = false) {
    int x = s;LL c = cap[how[x]];
    do {int e = how[x];
      c = min(c, cap[e]);
      x = from[e];
    }while (x != s);
    LL sum = 0;
    do {int e = how[x];
      if (flip) {cap[e]-=c;cap[e^1]+=c;
      }sum += cost[e]*c;x=from[e];
    }while (x != s);return sum;
  }LL push(int x) {
    for(++cookie;bio[x]!=cookie;x=from[how[x]]){
      if(!good[x]||how[x]==-1||cap[how[x]]==0)return 0;
      bio[x]=cookie;good[x]=false;
    }return cycle(x) >= 0 ? 0 : cycle(x, true);
  }LL run() { 
    reset();LL ret = 0;
    REP(step, 2*V) {
      if (step == V) reset();
      if (!relax()) continue;
      REP(i, V) good[i] = true;
      REP(i, V)if(LL w=push(i))ret+=w,step=0;
    }return ret;
  }}
const int N = 505;
const int MAX = int(1e5)+10;
int nfa[N];
void build_NFA(string &s){
  nfa[0]=0;int x=0,n=SZ(s);
  for(int i=1;i<=n;i++){
    nfa[i]=x;
    while(i!=n){
      if(s[x]==s[i]){x++;break;}
      if(!x)break;x=nfa[x];
    }}}
int kmp_search(int start,string& P,string& T){
  for(int i=start,x=0;i<SZ(T);){
    if(T[i]==P[x])x++,i++;
    else if(!x)i++;
    else x = nfa[x];
    if(x==SZ(P))return i-SZ(P);
  }return -1;
}//ans=kmp_search(ans),ans+=(SZ(P)-nfa[SZ(p)])
string s;
int L[MAX],R[MAX],C[MAX],len,deg[N];
int main()
{
  fast_io;
  int n;cin>>n;
  cin>>s;
  int m;cin>>m;
  for(int i=1;i<=m;i++){
    string t;
    int c;
    cin>>t>>c;
    int ans = 0;
    build_NFA(t);
    while((ans = kmp_search(ans,t,s))!=-1){
      L[len] = ans,R[len] = ans + SZ(t), C[len] = c;
      len++;ans += SZ(t) - nfa[SZ(t)];
    }
  }
  int x;cin>>x;
  Circu::init(n+1);
  for(int i=0;i<len;i++){
    Circu::AddEdge(R[i], L[i], 1, -C[i]);
  }
  for(int i=1;i<=n;i++)
    Circu::AddEdge(i-1, i, x, 0);
  LL ans = Circu::run();
  cout << -ans << endl;
  return 0;
}