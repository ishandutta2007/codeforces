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
const int N = 1e3 + 10;
const int MOD = 1e9 + 7;
const int LOGN = 20;
int dp[N][N][2], val[N];
char s[N];
inline int add(int a, int b){
  a = a + b;
  if(a >= MOD)a -= MOD;
  return a;
}
int getVal(int x){
  if(x == 1)return 0;
  int cnt = 0;
  REP(i, LOGN)if(x & (1 << i))cnt++;
  return 1 + getVal(cnt);
}
int main()
{
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  int k;si(k);
  val[0] = -1000;
  FOR(i, 1, N)val[i] = getVal(i);
  //dp[i][j][t] : first i positions, j ones placed, number is equal/less so far
  dp[0][0][1] = 1;//equal so far
  for(int i = 1; i <= n; i++)
    for(int j = 0; j <= n; j++){
      if(s[i] == '1'){
        //place 0 at this pos
        dp[i][j][0] = add(dp[i - 1][j][0], dp[i - 1][j][1]);
        if(j){
          //place 1 at this pos
          dp[i][j][1] = dp[i - 1][j - 1][1];
          dp[i][j][0] = add(dp[i][j][0], dp[i - 1][j - 1][0]);
        }
      }
      else {
        dp[i][j][0] = add(dp[i - 1][j][0], dp[i - 1][j - 1][0]);
        dp[i][j][1] = dp[i - 1][j][1];
      }
    }
  int ans = 0;
  for(int j = 1; j <= n; j++){
    if(val[j] + 1 == k){
      ans = add(ans, dp[n][j][0]);
      ans = add(ans, dp[n][j][1]);
      if(j == 1){
        ans = ans - 1;
        if(ans < 0)ans += MOD;
      }
    }
    if(j == 1 && k == 0)ans = add(ans, 1);
  }
  dout(ans);

  return 0;
}