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
const int N = int(7e3)+10;
int A[N],B[N];
int dp[2][N],L[2][N],W[2][N],SW[2][N],SL[2][N];
int n;
int nxt(int a,int b){
  a = a + b;
  while(a > n) a -= n;
  return a;
}
int prv(int a,int b){
  a = a - b;
  while(a <= 0) a += n;
  return a;
}
int main()
{
  si(n);
  int a;si(a);
  for(int i=1;i<=a;i++)si(A[i]);
  sort(A+1,A+1+a);
  int b;si(b);
  for(int i=1;i<=b;i++)si(B[i]);
  sort(B+1,B+1+b);
  SET(dp,-1);
  dp[0][1] = dp[1][1] = 0;
  for(int k=1;k<=b;k++)
    SL[1][prv(1,B[k])]++;
  for(int k=1;k<=a;k++)
    SL[0][prv(1,A[k])]++;
  for(int i=1;i<=4*n;i++){
    for(int j=1;j<=n;j++){
      if(dp[0][j] != -1)continue;
      if(SW[0][j] == a){
        assert(!SL[0][j]);
        dp[0][j] = 0;
        L[0][j] = 1;
        dp[0][j] = 0;
        for(int k=1;k<=b;k++)
          SL[1][prv(j,B[k])]++;
      }
      if(SL[0][j]){
        W[0][j] = 1;
        dp[0][j] = 1;
        for(int k=1;k<=b;k++)
          SW[1][prv(j,B[k])]++;
      }
    }
    for(int j=1;j<=n;j++){
      if(dp[1][j] != -1)continue;
      if(SW[1][j] == b){
        assert(!SL[1][j]);
        dp[1][j] = 0;
        L[1][j] = 1;
        dp[1][j] = 0;
        for(int k=1;k<=a;k++)
          SL[0][prv(j,A[k])]++;
      }
      if(SL[1][j]){
        W[1][j] = 1;
        dp[1][j] = 1;
        for(int k=1;k<=a;k++)
          SW[0][prv(j,A[k])]++;
      }
    }
  }
  REP(t,2){
    for(int i=2;i<=n;i++)
      if(dp[t][i] == 0)printf("Lose ");
      else if(dp[t][i] == 1)printf("Win ");
      else printf("Loop ");
    puts("");
  }
  return 0;
}