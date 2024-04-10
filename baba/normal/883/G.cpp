//TooWeakTooSlow
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

const int N = int(3e5) + 10;
VI g[N],ug[N];
int U[N], V[N], D[N], len, vis[N], vis2[N];
void dfs(int x){
  if(vis[x])return;
  vis[x] = 1;
  for(auto y : g[x])
    dfs(y);
}
int main()
{
  int n, m, s;
  si(n);si(m);si(s);
  REP(i, m){
    int t, u, v;
    si(t);si(u);si(v);
    if(t == 1){
      g[u].PB(v);
    }
    else {
      U[len] = u, V[len] = v;
      ug[u].PB(len);
      ug[v].PB(len);
      len++;
    }
  }
  dfs(s);
  //For Max
  queue<int> Q;
  FOR(i, 1, n + 1)
    if(vis[i]){
      Q.push(i);
      vis2[i] = 1;
    }
  while(!Q.empty()){
    int x = Q.front();Q.pop();
    trace(x);
    for(auto e : ug[x]){
      int y = U[e] ^ V[e] ^ x;
      if(!vis2[y]){
        D[e] = (U[e] == x ? 0 : -1);
        Q.push(y);
        vis2[y] = 1;
      }
    }
    for(auto y : g[x])
      if(!vis2[y]){
        vis2[y] = 1;
        Q.push(y);
      }
  }
  int ans = 0;
  FOR(i, 1, n + 1)ans += vis2[i];
  dout(ans);
  REP(i, len)printf("%c",D[i] == -1 ? '-' : '+');
  puts("");
  //For Min
  ans = 0;
  FOR(i, 1, n + 1)ans += vis[i];
  dout(ans);
  REP(i, len)printf("%c",(vis[U[i]] && !vis[V[i]]) ? '-' : '+');
  puts("");
	return 0;
}