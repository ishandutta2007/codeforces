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
const int N = 21;
const int MASK = 1<<N;
const int M = int(1e5)+1;
int dp[N][MASK],S[2][MASK],C[M];
char s[N][M];
int main()
{
  int n;si(n);
  int m;si(m);
  for(int i=0;i<n;i++)
    scanf("%s",s[i]);
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++)
      if(s[j][i] == '1')
        C[i] |= (1<<j);
    dp[0][C[i]]++;S[0][C[i]]++;
  }
  for(int i=1;i<=n;i++){
    int t = (i & 1 ? 1 : 0);
    for(int mask=0;mask<(1<<n);mask++)
      for(int p=0;p<n;p++)
        dp[i][mask] += S[1-t][mask^(1<<p)] - S[t][mask];
    for(int mask=0;mask<(1<<n);mask++){
      dp[i][mask] /= i;
      S[t][mask] += dp[i][mask];
    }
  }
  int ans = M*N;
  for(int mask=0;mask<(1<<n);mask++){
    int curr = 0;
    for(int i=0;i<=n;i++)
      curr += min(i,n-i)*dp[i][mask];
    ans = min(ans,curr);
  }
  dout(ans);
	return 0;
}