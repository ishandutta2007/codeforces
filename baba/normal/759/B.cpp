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
const int N = int(1e5)+10;
set<pair<LL,int>> A[2],B[2];
LL dp[N];
int main()
{
  int n;si(n);
  LL paid = 0;
  A[0].insert({0ll,0});
  B[0].insert({0ll,0});
  A[1].insert({dp[0],0});
  B[1].insert({dp[0],0});
  LL prv1 = 0, prv2 = 0;
  for(int i=1;i<=n;i++){
    int t;si(t);
    dp[i] = dp[i-1] + 20;
    while(!A[0].empty() && A[0].begin()->F <= t - 90){
      auto top = *A[0].begin();
      int id = top.second;
      A[0].erase(A[0].begin());
      A[1].erase(MP(dp[id],id));
      prv1 = dp[id];
    }
    while(!B[0].empty() && B[0].begin()->F <= t - 1440){
      auto top = *B[0].begin();
      int id = top.second;
      B[0].erase(B[0].begin());
      B[1].erase(MP(dp[id],id));
      prv2 = dp[id];
    }
    dp[i] = min(dp[i],prv1 + 50);
    dp[i] = min(dp[i],prv2 + 120);
    LL pay = max(0ll,dp[i] - paid);
    lldout(pay);
    paid += pay;
    A[0].insert({t,i});
    B[0].insert({t,i});
    A[1].insert({dp[i],i});
    B[1].insert({dp[i],i});
  }
	return 0;
}