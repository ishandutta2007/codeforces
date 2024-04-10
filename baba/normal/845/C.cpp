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
const int N = int(2e5)+10;
int L[N],R[N],A[N];
int main()
{
  int n;si(n);
  for(int i=1;i<=n;i++){
    si(L[i]);si(R[i]);A[i]=i;
  }
  sort(A+1,A+1+n,[](int a,int b){return L[a] < L[b];});
  int e1 = -1, e2 = -1;
  bool ok = true;
  for(int i=1;i<=n;i++){
    int st = L[A[i]], en = R[A[i]];
    if(st <= e1 && st <= e2){
      ok = false;
      break;
    }
    if(st > e1){
      e1 = en;
    }
    else if(st > e2){
      e2 = en;
    }
    else assert(false);
  }
  puts(ok ? "YES" : "NO");
	return 0;
}