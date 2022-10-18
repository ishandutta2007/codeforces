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
const int MAX = int(2e5)+400;
const int ZERO = int(1e5)+200;
const int MOD = int(1e9)+7;
int dp[2][MAX],PS[MAX];
inline int add(int a,int b){
  a = a + b;
  if(a>=MOD)a -= MOD;
  return a;
}
inline int sub(int a,int b){
  a = a - b;
  if(a < 0)a += MOD;
  return a;
}
inline int mul(LL a,LL b){
  a = a * b % MOD;
  return a;
}
int main()
{
  int a,b,k,t;
  si(a);si(b);si(k);si(t);
  int x = 0, y = 1;
  dp[x][ZERO] = 1;
  for(int j=1;j<=t;j++){
    int s = 0;
    for(int i=0;i<=k;i++)
      s = add(s,dp[x][i]);
    for(int i=0;i<MAX;i++){
      dp[y][i] = s;
      if(i + k + 1 < MAX)s = add(s,dp[x][i+k+1]);
      if(i - k >= 0)s = sub(s,dp[x][i-k]);
    }
    swap(x,y);
  }
  for(int i=1;i<MAX;i++)
    PS[i] = add(PS[i-1],dp[x][i]);
  int ans = 0;
  for(int i=1;i<MAX;i++){
    int s = i + a - b > 0 ? PS[i + a - b - 1] : 0;
    s = mul(s,dp[x][i]);
    ans = add(ans,s);
  }
  dout(ans);
	return 0;
}