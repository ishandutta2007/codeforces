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

const int N = int(5e3)+10;
int A[N];
LL PS[N];
int main()
{
  int n;si(n);
  for(int i=0;i<n;i++)
    si(A[i]);
  for(int i=1;i<=n;i++)
    PS[i] = PS[i-1] + A[i-1];
  LL ans = 0;
  int ai=0,aj=0,ak=0;
  for(int i=0;i<=n;i++){
    int mn = i;
    for(int j=i;j<=n;j++){
      if(PS[j] < PS[mn]){
        mn = j;
      }
      LL val = 2 * PS[i] -  2 * PS[mn] + 2 * PS[j] - PS[n];
      if(val > ans){
        ans = val;
        ai=i;aj=mn;ak = j;
      }
    }
  }
  printf("%d %d %d\n",ai,aj,ak);
	return 0;
}