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
const int MAX = 1e6 + 10;
bool notP[MAX];
int U[MAX], V[MAX], W[MAX], E;
set<II> S;
int n, m;
void addEdge(int a, int b, int wt){
  assert(a >= 1 && a <= n);
  assert(b >= 1 && b <= n);
  assert(!S.count({a, b}) && !S.count({b, a}));
  S.insert({a, b});
  U[E] = a; V[E] = b; W[E] = wt;E++;
}
int main()
{
  notP[1] = true;
  for(int i = 2; i < MAX; i++)
    for(int j = 2 * i; j < MAX; j += i)
      notP[j] = true;
  si(n);si(m);
  int ans = 0;;
  for(int i = 1; i < n - 1; i++){
    addEdge(i, i + 1, 1);
    ans++;
  }
  int want = 1;
  while(notP[ans + want])want++;
  addEdge(n - 1, n, want);
  ans += want;
  int a = 1, b = 3, wt = 1e9;
  REP(i, m - (n - 1)){
    addEdge(a, b, wt);b++;
    if(b > n){
      a++;b = a + 2;
    }
  }
  assert(E == m);
  assert(!notP[ans]);
  printf("%d %d\n", ans, ans);
  REP(i, E)printf("%d %d %d\n", U[i], V[i], W[i]);
	return 0;
}