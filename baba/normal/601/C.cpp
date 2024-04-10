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
const int N = 101;
const int M = 1001;
const int NM = N*M;
double dp[2][NM],PS[NM]; //dp[i][j] : Probabity(for a participant except main guy) of having a score j after i matches. N*N*M.
int A[N];
int main()
{
  int n,m;
  si(n);si(m);
  if(m==1){
    puts("1.00000000");
    return 0;
  }
  int score = 0;
  for(int i=1;i<=n;i++){
    si(A[i]);
    score+=A[i];
  }
  int x = 0, y = 1;
  for(int i=1;i<=m;i++)
    if(A[1] != i)
      dp[x][i] = 1.0 / (m-1);
  for(int i=2;i<=n;i++){
    for(int j=1;j<=n*m;j++)
      PS[j] = PS[j-1] + dp[x][j];
    for(int j=1;j<=n*m;j++)
      dp[y][j] = (PS[j-1] - PS[max(0,j-m-1)] - dp[x][max(0,j-A[i])])/(m-1);
    swap(x,y);
  }
  double ans = 0;
  for(int i=1;i<score;i++)
    ans += dp[x][i];
  ans = ans * (m-1);
  printf("%.13lf\n",1+ans);
	return 0;
}