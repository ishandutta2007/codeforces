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

const int N = 501;
int A[N][N];
int X[N * N], Y[N * N], T[N * N];
int n,m,k,q;
bool fucked(int t){
  SET(A,0);
  REP(i,q)if(T[i] <= t)A[X[i]][Y[i]]=1;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];
  for(int i=k;i<=n;i++)
    for(int j=k;j<=m;j++){
      int v = A[i][j] - A[i-k][j] - A[i][j-k] + A[i-k][j-k];
      if(v == k * k)
        return true;
    }
  return false;
}
int main()
{
  scanf("%d %d %d %d",&n,&m,&k,&q);
  REP(i,q)scanf("%d %d %d",X+i,Y+i,T+i);
  int l = 0, h = int(1e9), ans = -1;
  while(l <= h){
    int m = (l + h) >> 1;
    if(fucked(m)){
      ans = m;
      h = m - 1;
    }
    else l = m + 1;
  }
  dout(ans);
	return 0;
}