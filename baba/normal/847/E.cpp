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

//#define TRACE

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
char s[N];
int PS[N],A[N];
int main()
{
  int n;si(n);
  scanf("%s",s+1);
  for(int i=1;i<=n;i++)
    if(s[i] == '*')
      PS[i] = 1;
  for(int i=1;i<=n;i++)
    PS[i] += PS[i-1];
  auto getNext = [&](int idx, int T, int m = 1){
    trace(idx,T,m);
    if(T < 0)return -1;
    int mx = min(n,(idx + T / m));
    int l = mx, r = n, ans = mx;
    while(l <= r){
      int mid = (l + r) >> 1;
      if(PS[mid] == PS[mx]){
        ans = mid;
        l = mid + 1;
      }
      else r = mid - 1;
    }
    trace(idx,T,m,ans);
    return ans;
  };

  auto ok = [&](int T){
    int prv = 0;
    for(int i=1;i<=n;i++)if(s[i] == '*'){
      prv = i-1;
      break;
    }
    for(int i=1;i<=n;i++){
      if(s[i] != 'P')continue;
      prv = min(prv, i - 1);
      if(i - prv - 1 > T)return false;
      prv = max(getNext(i, T - 2 * (i - prv - 1)), getNext(i, T - (i - prv - 1), 2));
    }
    return prv == n;
  };

  int l = 0, r = int(2e5)+10, ans = -1;
  while(l <= r){
    int mid = (l + r) >> 1;
    if(ok(mid)){
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }
  dout(ans);
	return 0;
}