//Tanuj Khattar
#include<bits/stdc++.h>
#pragma GCC optimize("O3")

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
const int INF = 1e9;
namespace SuffixTree{
  const int MAXN = 1.2e6;
  const int dollar = 257;
  int s[MAXN];
  map<int, int> to[MAXN];
  int len[MAXN]={INF}, fpos[MAXN], link[MAXN],suff[MAXN],par[MAXN];
  int node, pos, remain;
  int sz = 1, n = 0;
  int make_node(int _pos, int _len,int _par){
    fpos[sz] =  _pos;
    len [sz] = _len;
    suff[sz] = n - remain;
    par[sz] = _par;
    return sz++;
  }
  void go_edge(){
    while(pos > len[to[node][s[n - pos]]]){
      node = to[node][s[n - pos]];
      pos -= len[node];
    }
  }
  void add_letter(int c){
    s[n++] = c;int last = 0;
    for(remain++,pos++;pos > 0;remain--){
      go_edge();
      int edge = s[n - pos];
      int &v = to[node][edge];
      int t = s[fpos[v] + pos - 1];
      if(v == 0){
        v = make_node(n - pos, INF,node);
        link[last] = node;
        last = 0;
      }
      else if(t == c){
        link[last] = node;
        return;
      }
      else{
        int u = make_node(fpos[v], pos - 1,node);
        to[u][c] = make_node(n - 1, INF,u);
        to[u][t] = v;par[v] = u;
        fpos[v] += pos - 1;
        len [v] -= pos - 1;
        v = u;
        link[last] = u;
        last = u;
      }
      if(node == 0) pos--;
      else node = link[node];
    }
  }
}
const int N = int(1.2e6)+10;
int cost[N],idx[N],len,dollar[N];
LL sum[N];
char s[N];
LL ans;
void dfs(int x,int clen = 0){
  sum[x] = (SuffixTree::to[x].empty() ? cost[idx[SuffixTree::suff[x]]] : 0);
  for(auto it : SuffixTree::to[x]){
    int y = it.S,l = SuffixTree::fpos[y], r = min(len-1,l + SuffixTree::len[y] - 1);
    if(clen < 0)dfs(y,clen);
    else if(dollar[l] <= r)
      dfs(y,-INF),ans = max(ans,sum[y] * (dollar[l] - l + (dollar[l] > l ? clen : 0 )));
    else dfs(y,clen + r - l + 1);
    sum[x] += sum[y];
  }
  if(clen >= 0)
    ans = max(ans,sum[x] * clen);
}
int main()
{
  int n;si(n);
  int prv = 0;
  REP(i,n){
    scanf("%s",s);
    for(char *c = s;*c;c++)
      SuffixTree::add_letter(*c),idx[len++] = i;
    SuffixTree::add_letter(SuffixTree::dollar + i);
    idx[len++] = i;
    FOR(j,prv,len)dollar[j] = len - 1;
    prv = len;
  }
  REP(i,n)si(cost[i]);
  dfs(0);
  lldout(ans);
}