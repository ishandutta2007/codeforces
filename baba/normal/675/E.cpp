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
const int N = int(1e5)+10;
const int LOGN = 20;
int A[N],msb[N],DP[LOGN][N];
LL dp[N],dp2[N];
int MX(int l,int r){
	int d = msb[r-l+1];
	int L = DP[d][l];
	int R = DP[d][r-(1<<d)+1];
	int mx = (A[L]>A[R]?L:R);
  return mx;
}
int main()
{
  int n;si(n);
  for(int i=1;i<n;i++)si(A[i]);
	//RMQ PRE-PROCESSING
	for(int i=1;i<=n;i++)
		DP[0][i]=i;
	for(int i=1;i<LOGN;i++)
		for(int j=1;j<=n;j++)
		{
			int l = DP[i-1][j], r=DP[i-1][min(n,j+(1<<(i-1)))];
			if(A[l]>A[r])
				DP[i][j] = l;
			else
				DP[i][j] = r;
		}
	for(int i=1,x=0;i<N;i++)
		if((1<<(x+1)<=i))
			msb[i]=(++x);
		else
			msb[i]=x;
  //done :)
  LL ans = 0;
  for(int i=n-1;i>=1;i--){
    int mx = MX(i+1,A[i]);
    int sub = A[i] - mx;
    dp2[i] = A[i]-i;
    dp[i] = dp2[i] + dp[mx] + dp2[mx] - 2*sub;
    dp2[i] += dp2[mx] - sub;
    ans += dp[i];
  }
  lldout(ans);
	return 0;
}