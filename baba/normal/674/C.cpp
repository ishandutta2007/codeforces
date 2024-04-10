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
const int N = int(2e5)+10;
const int K =  51;
double dp[K][N],PS[N],PS2[N],PS3[N];
int A[N];
double cost(int i,int j){
  return PS2[j]-PS2[i-1] - PS[i-1]*(PS3[j] - PS3[i-1]);
}
void go(int k,int l,int r,int L,int R){
  if(l > r)return;
  int m = (l+r)/2;
  dp[k][m] = 1e20;
  int opt = m;
  for(int i=L;i<=min(m-1,R);i++)
    if(dp[k][m] > dp[k-1][i] + cost(i+1,m)){
      dp[k][m] = dp[k-1][i] + cost(i+1,m);
      opt = i;
    }
  go(k,l,m-1,L,opt);
  go(k,m+1,r,opt,R);
}
int main()
{
  int n,k;
  si(n);si(k);
  for(int i=1;i<=n;i++)si(A[i]);
  for(int i=1;i<=n;i++)PS3[i]=(1.0)/A[i];
  for(int i=1;i<=n;i++)PS[i] = PS[i-1]+A[i];
  for(int i=1;i<=n;i++)PS2[i] = PS[i]/A[i];
  for(int i=1;i<=n;i++)PS2[i]+=PS2[i-1];
  for(int i=1;i<=n;i++)PS3[i]+=PS3[i-1];
  for(int i=1;i<=n;i++)dp[1][i] = cost(1,i);
  for(int i=2;i<=k;i++)
    go(i,1,n,1,n);
  printf("%.9lf\n",dp[k][n]);
	return 0;
}