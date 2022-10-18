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
const int N = 101;
const int MOD = int(1e9)+7;
int C[N][N],dp[N][10],A[10],ans;
int main()
{
  C[0][0]=1;
  for(int i=1;i<N;i++){
    C[i][0]=1;
    for(int j = 1;j <= i; j++)
      C[i][j] = (C[i-1][j]+C[i-1][j-1])%MOD;
  }
  int n;si(n);
  for(int i=0;i<10;i++)si(A[i]);
  for(int i=A[9];i<=n;i++)dp[i][9]=1;
  for(int i=0;i<=n;i++){
    for(int j=8;j>=0;j--){
      for(int k = A[j];k <= n; k++)
        if(i - k >= 0){
          dp[i][j] = (dp[i][j] + dp[i - k][j+1]*1ll*(j?C[i][k]:C[i-1][k])) % MOD;
        }
    }
  }
  for(int i=1;i<=n;i++)
    ans = (ans + dp[i][0])%MOD;
  cout<<ans<<endl;
	return 0;
}