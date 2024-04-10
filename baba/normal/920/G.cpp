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
const int MASK = 1 << 8;
const int N = 1e6 + 10;
VI primes[N];
int get(int num, int p){
  if(p == 1){
    return num;
  }
  int n = SZ(primes[p]);
  int ans = 0;
  REP(mask, 1 << n){
    int sign = 1;
    int val = 1;
    REP(i, n){
      if(mask & (1 << i)){
        val *= primes[p][i];
        sign *= -1;
      }
    }
    ans += sign * (num / val);
  }
  return ans;
}
int main()
{
  for(int i = 2; i < N; ++i){
    if(primes[i].empty()){
      for(int j = i; j < N; j += i){
        primes[j].PB(i);
      }
    }
  }

  int t;si(t);
  while(t--){
    int x, p, k;
    si(x);si(p);si(k);
    int sub = get(x, p);
    int low = x, high = 100 * N, ans = -1;
    while(low <= high){
      int mid = (low + high) >> 1;
      if(get(mid, p) >= k + sub){
        ans = mid;
        high = mid - 1;
      }
      else low = mid + 1;
    }
    dout(ans);
  }
	return 0;
}