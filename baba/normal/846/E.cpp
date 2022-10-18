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
LL A[N],B[N],want[N];
VII g[N];
int vis[N];
void dfs(int x){
  vis[x] = 1;
  want[x] = A[x] - B[x];
  for(auto it : g[x]){
    int y = it.F, wt = it.S;
    dfs(y);
    if(want[y] > 0){
      if(want[x] + wt * 1.0 * want[y] > 1e17){
        puts("NO");
        exit(0);
      }
      want[x] += wt * want[y];
    }
    else want[x] += want[y];
  }
}
int main()
{
  int n;si(n);
  for(int i=1;i<=n;i++)sll(B[i]);
  for(int i=1;i<=n;i++)sll(A[i]);
  for(int i=2;i<=n;i++){
    int x,k;
    si(x);si(k);
    g[x].PB({i,k});
  }
  bool ok = true;
  for(int i=1;i<=n;i++)
    if(!vis[i]){
      dfs(i);
      ok &= want[i] <= 0;
    }
  puts(ok ? "YES" : "NO");
	return 0;
}