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
const int N = int(2e5)+10;
const int LOGN = 20;
int DP[LOGN][N],level[N],ans[N],A[N];
LL depth[N];
VII g[N];
void dfs(int x){
  for(auto it : g[x]){
    int y = it.F, wt = it.S;
    level[y] = level[x] + 1;
    depth[y] = depth[x] + wt;
    dfs(y);
  }
}
void dfs2(int x){
  for(auto y : g[x]){
    dfs2(y.F);
    ans[x] += ans[y.F];
  }
}
int goUp(int x,int d){
  for(int i=0;i<LOGN;i++)
    if((1<<i)&d)
      x = DP[i][x];
  return x;
}
int main()
{
  int n;si(n);
  for(int i=1;i<=n;i++)
    si(A[i]);
  for(int i=2;i<=n;i++){
    int p;si(p);
    int w;si(w);
    DP[0][i] = p;
    g[p].PB({i,w});
  }
  g[0].PB({1,0});dfs(0);
  for(int i=1;i<LOGN;i++)
    for(int j=1;j<=n;j++)
      DP[i][j]=DP[i-1][DP[i-1][j]];
  for(int i=1;i<=n;i++){
    int l = 1, h = level[i]-1,id = -1;
    while(l <= h){
      int m = (l+h)/2;
      int x = goUp(i,m);
      if(depth[i] - depth[x] <= A[i]){
        id = x;
        l = m + 1;
      }
      else h = m - 1;
    }
    if(id == -1)continue;
    ans[DP[0][id]]--;
    ans[DP[0][i]]++;
  }
  dfs2(1);
  for(int i=1;i<=n;i++)
    printf("%d ",ans[i]);
  puts("");
	return 0;
}