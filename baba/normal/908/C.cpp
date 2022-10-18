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
const long double EPS = 1e-14;
int X[N], r;
long double Y[N];
long double sq(long double a){
  return a * a;
}
bool intersect(long double x1, long double y1, long double x2, long double y2, long double r){
  return sq(x1 - x2) + sq(y1 - y2) <= 4 * r * r;
}
int main()
{
  int n;si(n);
  int r;si(r);
  SET(X, -1);
  REP(i, n){
    int x;si(x);
    Y[i] = r;
    REP(j, N){
      if(X[j] == -1)continue;
      int idx = X[j];
      long double x1 = x, y1 = Y[idx], x2 = j, y2 = Y[idx];
      if(!intersect(x1, y1, x2, y2, r))continue;
      y1 = sqrt(4 * r * r - sq(x1 - x2)) + y2;
      Y[i] = max(Y[i], y1);
    }
    X[x] = i;
  }
  REP(i, n)printf("%.10Lf ", Y[i]);
  puts("");
	return 0;
}