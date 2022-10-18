//TooWeakTooSlow
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

const int N = 510;
int dp[N][N], opt[N][N], st[N], en[N];
char s[N][N];
int n, m, k;
void go(int opt[], char s[]){
  SET(st, -1);SET(en, -1);
  int val = 0;
  for(int i = 1; i <= m; ++i){
    if(s[i] == '1'){
      val++;
      st[val] = i;
    }
  }
  val = 0;
  for(int i = m; i >= 1; i--){
    if(s[i] == '1'){
      val++;
      en[val] = i;
    }
  }
  opt[0] = en[1] - st[1] + 1;
  for(int i = 1; i < val; i++){
    opt[i] = 1e8;
    for(int s = 0; s <= i; s++){
      int e = i - s;
      if(st[s + 1] == -1 || en[e + 1] == -1 || st[s + 1] > en[e + 1])continue;
      opt[i] = min(opt[i], en[e + 1] - st[s + 1] + 1);
    }
    if(opt[i] > 1e7){
      opt[i] = -1;
    }
  }
  opt[val] = 0;
}
int main()
{
  si(n);si(m);si(k);
  FOR(i, 1, n + 1)scanf("%s", s[i] + 1);
  SET(opt, -1);SET(dp, -1);
  FOR(i, 1, n + 1)go(opt[i], s[i]);
  //FOR(i, 1, n + 1)REP(j, m + 1)trace(i, j, opt[i][j]);
  dp[0][0] = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = 0; j <= k; j++){
      dp[i][j] = 1e8;
      for(int l = 0; l <= j; l++){
        if(opt[i][l] == -1 || dp[i - 1][j - l] == -1)continue;
        dp[i][j] = min(dp[i][j], dp[i - 1][j - l] + opt[i][l]);
      }
      if(dp[i][j] > 1e7)dp[i][j] = -1;
    }
  }
  int ans = 1e8;
  REP(i, k + 1)if(dp[n][i] != -1)ans = min(ans, dp[n][i]);
  cout << ans << endl;

	return 0;
}