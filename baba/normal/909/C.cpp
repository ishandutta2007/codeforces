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
const int N = 5e3 + 10;
const int MOD = 1e9 + 7;
int dp[N][N], sum[N];
char s[N];
int main()
{
  int n;si(n);
  REP(i, n){
    char temp[2];
    scanf("%s", temp);
    s[i] = temp[0];
  }
  dp[0][0] = 1;
  sum[0] = 1;
  FOR(i, 1, n){
    REP(j, i + 1){
      if(s[i - 1] == 'f')
        dp[i][j] = (j ? dp[i - 1][j - 1] : 0);
      else {
        dp[i][j] = sum[j];
      }
    }
    sum[n + 1] = 0;
    for(int j = n; j >= 0; j--)
      sum[j] = (sum[j + 1] + dp[i][j]) % MOD;
  }
  dout(sum[0]);
	return 0;
}