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

const int N = int(1e3)+10;
const int MAXITER = int(1e5);
int X[N][5],V[N][5],A[N];
bool bad(int idx,int n){
  REP(i,n){
    A[i] = i;
    REP(j,5)
      V[i][j] = X[i][j] - X[idx][j];
  }
  swap(A[0],A[idx]);
  REP(it,MAXITER){
    int i = max(1,rand() % n);
    int j = max(1,rand() % n);
    if(i == j)continue;
    int v = 0;
    REP(k,5)v += V[A[i]][k] * V[A[j]][k];
    if(v > 0)return true;
  }
  return false;
}
int main()
{
  srand(time(NULL));
  int n;si(n);
  REP(i,n)
    REP(j,5)
      si(X[i][j]);
  vector<int> ans;
  REP(i,n)
    if(!bad(i,n))
      ans.PB(i);
  dout(SZ(ans));
  for(auto x : ans)
    dout(x + 1);
	return 0;
}