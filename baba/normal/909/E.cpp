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

const int N = 1e5 + 10;
VI g[N];
int V[N], deg[N];
int main()
{
  int n;si(n);
  int m;si(m);
  REP(i, n)si(V[i]);
  REP(i, m){
    int a, b;
    si(a);si(b);
    g[b].PB(a);
    deg[a]++;
  }
  set<II> S;
  REP(i, n)if(!deg[i])S.insert({V[i], i});
  queue<int> Q;
  bool beg = false;
  int ans = 0;
  while(!S.empty() || !Q.empty()){
    if(S.empty()){
      assert(beg);
      beg = false;
      while(!Q.empty()){
        int x = Q.front();Q.pop();
        assert(!V[x]);
        S.insert({V[x], x});
      }
    }
    auto top = *S.begin();
    S.erase(S.begin());
    int x = top.S;
    if(V[x]){
      if(!beg)ans++;
      beg = true;
      for(auto y : g[x]){
        deg[y]--;
        if(!deg[y]){
          if(V[y])S.insert({V[y], y});
          else Q.push(y);
        }
      }
    }
    else {
      for(auto y : g[x]){
        deg[y]--;
        if(!deg[y]){
          S.insert({V[y], y});
        }
      }
    }
  }
  dout(ans);
	return 0;
}