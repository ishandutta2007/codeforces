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
const LL is_query=-(1LL<<62);
struct Line{
  LL m,b;//compare two lines by increasing slope
  mutable function<const Line*()> succ;
  bool operator<(const Line& rhs)const{
    if(rhs.b!=is_query)return m > rhs.m;//> for min
    const Line* s=succ();
    if(!s)return 0;
    return b-s->b > (s->m-m)*rhs.m;//> for min
  }};
struct HullDynamic:public multiset<Line>{
  bool bad(iterator y){//maintains upper hull for max
    auto z=next(y);
    if(y==begin()){
      if(z==end())return 0;
      return y->m == z->m && y->b >= z->b;//>= for min
    }auto x=prev(y);
    if(z==end())
      return y->m==x->m && y->b >= x->b; // >= for min
    return (x->b-y->b)* 1.0 * (z->m-y->m) >= (y->b-z->b)* 1.0 * (y->m-x->m);
  }
  void insert_line(LL m,LL b){
    auto y=insert({ m,b});
    y->succ=[=]{return next(y)==end()?0:&*next(y);};
    if(bad(y)){erase(y);return;}
    while(next(y)!=end() && bad(next(y)))erase(next(y));
    while(y!=begin() && bad(prev(y)))erase(prev(y));
  }
  LL eval(LL x){
    auto l=*lower_bound((Line){x,is_query});
    return l.m*x +l.b;
  }};
const int N = 1e5 + 10;
int A[N], B[N], sub[N];
VI g[N];
LL dp[N];
void dfs0(int x, int p){
  sub[x] = 1;
  for(auto y : g[x])if(y != p){
    dfs0(y, x);
    sub[x] += sub[y];
  }
}
void dfs(int x, int p, HullDynamic& cht){
  int mx = -1;
  for(auto y : g[x]){
    if(y == p)continue;
    if(mx == -1 || sub[mx] < sub[y]){
      mx = y;
    }
  }
  if(mx == -1){
    //leaf
    dp[x] = 0;
    cht.insert_line(B[x], dp[x]);
    return;
  }
  dfs(mx, x, cht);
  for(auto y : g[x]){
    if(y == p  || y == mx)continue;
    HullDynamic temp;
    dfs(y, x, temp);
    for(auto p : temp){
      cht.insert_line(p.m, p.b);
    }
  }
  dp[x] = cht.eval(A[x]);
  cht.insert_line(B[x], dp[x]);
}
int main()
{
  int n;si(n);
  for(int i = 1; i <= n; i++)si(A[i]);
  for(int i = 1; i <= n; i++)si(B[i]);
  REP(i, n - 1){
    int x, y;
    si(x);si(y);
    g[x].PB(y);
    g[y].PB(x);
  }
  dfs0(1, 1);
  HullDynamic cht;
  dfs(1, 1, cht);
  for(int i = 1; i <= n; i++)printf("%lld ", dp[i]);
  puts("");
	return 0;
}