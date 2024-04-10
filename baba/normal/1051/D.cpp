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
const int MOD = 998244353;
inline int add(int a, int b){
  a = a + b;
  if(a >= MOD)a -= MOD;
  return a;
}
int diff(int mask, int prv_mask){
  if(mask == 0 || mask == 3){
    return mask + prv_mask == 3;
  }
  int ret = 0;
  ret += ((mask & 1) != (prv_mask & 1));
  ret += ((mask & 2) != (prv_mask & 2));
  return ret;
}
int dp[2][2 * N][4];
int main()
{
  int n, k;
  si(n);si(k);
  int x = 0, y = 1;
  for(int mask = 0; mask < 4; mask++){
    int cnt = (mask == 0 || mask == 3) ? 1 : 2;
    dp[x][cnt][mask] += 1;
  }
  for(int i = 2; i <= n; i++){
    for(int j = 1; j <= k; j++){
      for(int mask = 0; mask < 4; mask++){
        for(int prv_mask = 0; prv_mask < 4; prv_mask++){
          int cnt = diff(mask, prv_mask);
          if(j - cnt < 0)continue;
          dp[y][j][mask] = add(dp[y][j][mask], dp[x][j - cnt][prv_mask]);
        }
      }
    }
    swap(x, y);
    SET(dp[y], 0);
  }
  int ans = 0;
  for(int mask = 0; mask < 4; mask++){
    ans = add(ans, dp[x][k][mask]);
  }
  dout(ans);
	return 0;
}