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

const int N = int(2e6)+10;
LL PS[N],cnt[N],P[N];
int main()
{
  int n,x,y;
  si(n);si(y);si(x);
  int k = y / x;
  for(int i=1;i<=n;i++){
    int x;si(x);
    PS[x] += x;
    cnt[x] += 1;
  }
  for(int i=1;i<N;i++){
    PS[i] += PS[i-1];
    cnt[i] += cnt[i-1];
  }
  for(int i=2;i<N;i++)
    for(int j=2*i;j<N;j+=i)
      P[j] = 1;
  LL ans = LL(1e18);
  for(int i=2;i<N/2;i++){
    int last = 0;
    LL sum = 0;
    if(P[i])continue;
    for(int j=i;j<N;j+=i){
      sum += ((cnt[j-1] - cnt[max(last, j - k - 1)]) * j - (PS[j-1] - PS[max(last, j - k - 1)])) * x;
      sum += (cnt[max(last,j - k - 1)] - cnt[last]) * y;
      last = j;
    }
    ans = min(ans,sum);
  }
  lldout(ans);
	return 0;
}