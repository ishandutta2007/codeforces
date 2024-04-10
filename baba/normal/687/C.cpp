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
const int N = 501;
int dp[2][N][N],A[N];
int main()
{
  int n,k;
  si(n);si(k);
  for(int i=1;i<=n;i++)
    si(A[i]);
  int x = 0, y = 1;
  dp[x][0][0]=1;
  for(int i=1;i<=n;i++){
    for(int j=0;j<N;j++)
      for(int k=0;k<N;k++){
        dp[y][j][k]=dp[x][j][k];
        if(j-A[i]>=0 && k-A[i]>=0)
          dp[y][j][k] |= dp[x][j-A[i]][k-A[i]];
        if(j-A[i]>=0)
          dp[y][j][k] |= dp[x][j-A[i]][k];
      }
    swap(x,y);
  }
  VI ans;
  for(int i=0;i<N;i++)
    if(dp[x][k][i])
      ans.PB(i);
  dout(SZ(ans));
  for(auto i:ans)
    printf("%d ",i);
  puts("");
	return 0;
}