//TooWeakTooSlow
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
const int N = int(2e5) + 10;
II L[N], R[N], F[N], A[N];
II null = {-1, -1};
II intersect(II a, II b){
  if(a.S < b.F || b.S < a.F)return null;
  return {max(a.F, b.F), min(a.S, b.S)};
}
II expand(II a){
  return {max(a.F - 1, 0), a.S + 1};
}
int main()
{
  int n;si(n);
  REP(i, n){
    int x, y;
    si(x);si(y);
    A[i] = {x, x + y};
  }
  //Left
  L[0] = A[0];
  FOR(i, 1, n){
    L[i] = intersect(expand(L[i - 1]), A[i]);
  }
  //Right
  R[n-1] = A[n - 1];
  for(int i = n - 2; i >= 0; i--){
    R[i] = intersect(expand(R[i + 1]), A[i]);
  }
  //done
  LL ans = 0;
  REP(i, n){
    F[i] = intersect(L[i], R[i]);
    if(F[i] == null){
      puts("-1");
      return 0;
    }
    ans += F[i].S - A[i].F;
  }
  lldout(ans);
  REP(i, n)printf("%d ",F[i].S);
  puts("");
  



	return 0;
}