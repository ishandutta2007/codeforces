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
const int N = int(2e5)+10;
VI g[N];
int far[N],P[N],level[N],want[N];
void quit(){
  puts("-1");
  exit(0);
}
void dfs(int u,int p){
  far[u] = u; P[u] = p;
  for(auto w : g[u])
    if(w!=p){
      level[w] = level[u] + 1;
      dfs(w,u);
      if(level[far[w]] > level[far[u]])
        far[u] = far[w];
    }
}
int dfs1(int u,int p){
  int ret = 1;
  set<int> S;
  for(auto w : g[u])
    if(w != p){
      S.insert(dfs1(w,u));
    }
  if(SZ(S) > 1)quit();
  if(!S.empty())ret += *S.begin();
  return ret;
}
int main()
{
  int n;si(n);
  for(int i=1;i<n;i++){
    int u,v;
    si(u);si(v);
    g[u].PB(v);
    g[v].PB(u);
  }
  dfs(1,1);
  int x = far[1];
  level[x] = 0;
  dfs(x,x);
  int y = far[x];
  int d = level[y];
  int clen = 0;
  int c = -1;
  int prv = -1;
  while(y != x){
    want[y] = min(clen,d - clen);
    if(clen == d - clen){
      set<int> S;
      for(auto w : g[y])
        if(w!=P[y] && w!=prv){
          int len = dfs1(w,y);
          if(len != clen)
            S.insert(len);
        }
      if(SZ(S) > 1)quit();
      if(!S.empty())c = *S.begin();
    }
    else {
      bool ok = true;
      for(auto w : g[y])
        if(w != P[y] && w != prv){
          ok &= (dfs1(w,y) == want[y]);
        }
      if(!ok) quit();
    }
    prv = y;
    y = P[y];
    clen++;
  }
  assert(clen == d);
  int ans = 0;
  if(c == -1)ans = d;
  else {
    assert(d % 2 == 0);
    ans = d / 2 + c;
  }
  while(ans % 2 == 0)
    ans = ans / 2;
  dout(ans);
	return 0;
}