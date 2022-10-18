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
const int D = int(1e4)+10;
const int N = int(1e3)+10;
double dp[D][N];
int main()
{
  int k,q;
  si(k);si(q);
  dp[0][0] = 1;
  for(int i=1;i<D;i++){
    dp[i][0] = 0;
    for(int j=1;j<=k;j++){
      dp[i][j] = dp[i-1][j] * ((j * 1.0) / k) + dp[i-1][j-1] * ((k - j + 1.0) / k);
    }
  }
  while(q--){
    int p;si(p);
    int l = 0, h = D-1,ans = -1;
    while(l <= h){
      int m = (l+h)/2;
      if(dp[m][k] * 2000 >= p){
        ans = m;
        h = m - 1;
      }
      else l = m + 1;
    }
    dout(ans);
  }
	return 0;
}