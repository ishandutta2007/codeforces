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
char s[N],t[N];
int nfa[N];
int memo[N][26];
int go(int x,char c){
  int &ret = memo[x][c-'a'];
  if(ret != -1)return ret;
  while(true){
    if(t[x] == c){x++;break;}
    if(!x)break;
    x = nfa[x];
  }
  return ret = x;
}
int dp[2][N],can[2][N];
int main()
{
  SET(memo,-1);
  scanf("%s",s);
  scanf("%s",t);
  int slen = strlen(s), n = strlen(t),x = 0,y = 1;
  for(int i=1;i<=n;i++){
    nfa[i] = x;
    if(i < n)
      x = go(x,t[i]);
  }
  x = 0;y = 1;
  can[0][0]=true;
  REP(i,slen){
    REP(j,n+1){
      if(!can[x][j])continue;
      if(s[i] == '?'){
        REP(c,26){
          int nc = go(j,c+'a');
          dp[y][nc] = max(dp[y][nc],dp[x][j] + (nc == n));
          can[y][nc] = true;
        }
      }
      else {
        int nc = go(j,s[i]);
        dp[y][nc] = max(dp[y][nc],dp[x][j] + (nc == n));
        can[y][nc] = true;
      }
    }
    swap(x,y);
    REP(j,n+1)dp[y][j]=can[y][j]=0;
  }
  int ans = 0;
  REP(i,n+1)ans = max(ans,dp[x][i]);
  dout(ans);
	return 0;
}