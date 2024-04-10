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

const int N = int(1e5)+10;
II X[N],Y[N],ans[N];
int xlen,ylen, type[N];
map<int, VII> mp;
int main()
{
  int n,w,h;
  si(n);si(w);si(h);
  for(int i=1;i<=n;i++){
    int g,p,t;
    si(g);si(p);si(t);
    type[i] = g;
    mp[p - t].PB({p, i});
  }
  for(auto it : mp){
    const auto &v = it.S;
    xlen = 0; ylen = 0;
    for(auto x : v){
      int p = x.F;
      int i = x.S;
      int g = type[i];
      if(g == 1)X[++xlen] = {p, i};
      else Y[++ylen] = {p, i};
    }
    sort(X+1, X + 1 + xlen);
    sort(Y+1, Y + 1 + ylen);
    for(int i=xlen,ahead = 0; i >= 1; i--,ahead++){
      int idx = X[i].S;
      if(ylen >= ahead + 1)
        ans[idx] = {w, Y[ahead+1].F};
      else ans[idx] = {X[i + ylen].F, h};
    }
    for(int i=ylen,ahead = 0; i >= 1; i--,ahead++){
      int idx = Y[i].S;
      if(xlen >= ahead + 1){
        ans[idx] = {X[ahead+1].F, h};
      }
      else ans[idx] = {w, Y[i + xlen].F};
    }
  }
  for(int i=1;i<=n;i++)
    printf("%d %d\n",ans[i].F,ans[i].S);

  return 0;
}