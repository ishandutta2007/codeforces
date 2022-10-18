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
const int N = 2001;
const int MOD = int(1e9)+7;
int dp[3][4][N];
int A[N],B[N];
void add(int &a,int b){
  a = a + b;
  if(a > MOD)a -= MOD;
}
int main()
{
  fast_io;
  int m,d;
  string a,b;
  cin>>m>>d>>a>>b;
  int n = SZ(a);
  for(int i=0;i<n;i++)A[i]=a[i]-'0';
  for(int i=0;i<n;i++)B[i]=b[i]-'0';
  int x = 0,y = 1;
  if(A[0]==B[0] && A[0]!=d)dp[x][2][A[0]%m] = 1;
  else {
    if(A[0]!=d)dp[x][0][A[0]%m] = 1;
    for(int j = A[0]+1;j<B[0];j++)
      if(j!=d)
        dp[x][3][j%m] += 1;
    if(B[0]!=d)dp[x][1][B[0]%m] += 1;
  }
  for(int i=1;i<n;i++){
    for(int j=0;j<4;j++){
      for(int k=0;k<m;k++){
        int s = (j == 0 || j == 2 ? A[i] : 0);
        int e = (j == 1 || j == 2 ? B[i] : 9);
        for(int c = s; c <= e; c++){
          int nxt = -1;
          if(c !=s && c!=e)nxt = 3;
          else if(c == s && c == e)nxt = j;
          else if(c == s)nxt = (j == 0 || j == 2 ? 0 : 3);
          else if(c == e)nxt = (j == 1 || j == 2 ? 1 : 3);
          else assert(false);
          if((i & 1) && c != d)continue;
          if(!(i & 1) && c == d)continue;
          //trace(i,j,k,dp[x][j][k],s,e,c);
          add(dp[y][nxt][(k*10 + c)%m],dp[x][j][k]);
        }
      }
    }
    swap(x,y);
    SET(dp[y],0);
  }
  int ans = 0;
  for(int i = 0; i < 4 ; i++)
    add(ans,dp[x][i][0]);
  cout<<ans<<endl;
	return 0;
}