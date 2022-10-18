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

const int N = int(1e6)+10;
int P[N],cnt[N],vis[N],v[N];
bool dp[N],old[N];
int main()
{
  int n;si(n);
  int k;si(k);
  for(int i=1;i<=n;i++)
    si(P[i]);
  int use = 0;
  for(int i=1;i<=n;i++){
    if(vis[i])continue;
    int x = i;
    int sz = 0;
    while(!vis[x]){
      vis[x] = 1;
      x = P[x];
      sz++;
    }
    use += sz / 2;
    cnt[sz]++;
  }
  dp[0]=true;v[0]=true;
  int kk = k;
  k = min(k,n-k);
  for(int i=1;i<=k && !dp[k];++i){
    if(!cnt[i])continue;
    int c = cnt[i];
    for(int s = k; s >= k - i + 1;--s){
      v[s] = 0;
      for(int j = 0;j <= c && s >= j * i; ++j){
        old[s] = dp[s];
        v[s] += dp[s - j * i];
        dp[s] = (v[s] ? true : false);
      }
    }
    for(int s = k - i; s >= 1; --s){
      old[s] = dp[s];
      v[s] = v[s + i] - old[s+i] + (s >= c * i ? dp[s - c * i] : 0);
      dp[s] = (v[s] ? true : false);
    }
  }
  int mn = -1, mx = -1;
  if(dp[k])mn = kk;
  else mn = kk + 1;
  if(kk <= use) mx = 2 * kk;
  else mx  = 2 * use + min(n - 2 * use, kk - use);
  printf("%d %d\n",mn,mx);
	return 0;
}