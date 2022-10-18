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
LL dp[4][N];
int A[N];
int main()
{
  int n;si(n);
  for(int i=1;i<=n;i++)si(A[i]);
  dp[0][1] = 0;
  dp[1][1] = A[1];
  dp[2][n] = 0;
  dp[3][n] = A[n];
  for(int i=2;i<=n;i++){
    if(dp[1][i - 1] >= A[i]){
      dp[1][i] = dp[1][i - 1] + 1;
      dp[0][i] = dp[0][i - 1] + dp[1][i] - A[i];
    }
    else{
      dp[1][i] = A[i];
      dp[0][i] = dp[0][i - 1];
    }
  }
  for(int i = n - 1;i >= 1;i--){
    if(dp[3][i + 1] >= A[i]){
      dp[3][i] = dp[3][i + 1] + 1;
      dp[2][i] = dp[2][i + 1] + dp[3][i] - A[i];
    }
    else{
      dp[3][i] = A[i];
      dp[2][i] = dp[2][i + 1];
    }
  }
  long long curr_min = dp[0][1] + dp[2][1], curr_cost;
  for(int i = 1;i <= n;i++){
    curr_cost = dp[0][i] + dp[2][i];
    curr_cost -= min(dp[1][i], dp[3][i]) - A[i];
    curr_min = min(curr_min, curr_cost);
  }
  lldout(curr_min);



  return 0;
}