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
const int N = 602;
int mod,indeg[N],outdeg[N],dp[N][N],A[N/2][N/2],idx[2][N],vis[N],n,m;
VI g[N];
int mul(int a,int b){
  return (a * 1ll * b) % mod;
}
int add(int a,int b){
  a = a + b;
  if(a >= mod)a -= mod;
  return a;
}
int power(int a,int p){
  int ret = 1;
  while(p){
    if(p&1)ret=mul(ret,a);
    a=mul(a,a);
    p/=2;
  }
  return ret;
}
void f(int x){
  vis[x]=1;dp[x][x]=1;
  for(auto y : g[x]){
    if(!vis[y])f(y);
    for(int i=1;i<=n;i++)
      dp[x][i] = add(dp[x][i],dp[y][i]);
  }
}
int main()
{
  si(n);si(m);si(mod);
  for(int i=1;i<=m;i++){
    int a,b;
    si(a);si(b);
    g[a].PB(b);
    outdeg[a]++;
    indeg[b]++;
  }
  //compute the dp values
  for(int i=1;i<=n;i++)
    if(!vis[i])
      f(i);
  //identify sources,sinks and label them
  for(int i=1;i<=n;i++){
    if(indeg[i] == 0)
      idx[0][i] = idx[0][i-1] + 1;
    else idx[0][i]=idx[0][i-1];
    if(outdeg[i] == 0)
      idx[1][i] = idx[1][i-1] + 1;
    else idx[1][i] = idx[1][i-1];
  }
  int ans = 1;
  //Handle isolated vertices separately
  int neg1 = mod-1;
  for(int i=1;i<=n;i++)
    if(indeg[i] == 0 && outdeg[i] == 0)
      ans = mul(ans,(idx[0][i] + idx[1][i])&1?neg1:1);
  //Build the matrix A
  int r = 0, c = 0;
  for(int i=1;i<=n;i++){
    if(indeg[i]==0 && outdeg[i] == 0)continue;
    if(indeg[i]==0)idx[0][i]=++r;
    if(outdeg[i]==0)idx[1][i]=++c;
  }
  for(int i=1;i<=n;i++){
    if(!(indeg[i]==0 && outdeg[i]!=0))continue;
    for(int j=1;j<=n;j++){
      if(!(indeg[j]!=0 && outdeg[j]==0))continue;
      A[idx[0][i]][idx[1][j]]=dp[i][j];
    }
  }
  //Compute Det(A) % p using gaussian elimination
  assert(r == c);
  for(int i=1;i<=c;i++){
    int idx = -1;
    for(int j=i;j<=r;j++)
      if(A[j][i]!=0){
        idx = j;
        break;
      }
    if(idx == -1){ans = 0;break;}
    if(idx != i)ans = mul(ans,neg1);
    for(int j=1;j<=c;j++)
      swap(A[idx][j],A[i][j]);
    int div = power(A[i][i],mod-2);
    ans = mul(ans,A[i][i]);
    for(int j=1;j<=r;j++){
      if(j == i)continue;
      if(!A[j][i])continue;
      int w = mul(A[j][i],mod-div);
      for(int k=1;k<=c;k++)
        A[j][k] = add(A[j][k],mul(A[i][k],w));
    }
  }
  dout(ans);
	return 0;
}