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

double A[101];
int main()
{
  int n;si(n);
  REP(i, n)cin>>A[i];
  double mx = 0;
  REP(i, n)mx = max(mx, A[i]);
  if(mx >= 0.5){
    printf("%.10lf\n",mx);
    return 0;
  }
  double p_0 = 1.0;
  double p_1 = 0.0;
  sort(A, A + n);
  reverse(A, A + n);
  REP(i, n){
    double val = p_1 - p_0;
    double temp = -val * A[i];
    p_1 = p_1 + temp;
    p_0 = p_0 - p_0 * A[i];
    if(p_0 < p_1)break;
  }
  printf("%.10lf\n",p_1);
	return 0;
}