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

const int N = int(5e5)+10;
const int LOGN = 22;
int A[2][N],DP[2][LOGN][N],msb[N],n,len;
map<int,int>mp;
bool cmp(int t,int a,int b){
  if(t)return a < b;
  else return a > b;
}
void build(int t){
  for(int i=1;i<=n;i++)DP[t][0][i]=i;
  for(int i=1;i<LOGN;i++)
    for(int j=1;j<=n;j++){
      int x = j + (1<<(i-1));
      if(x > n )break;
      DP[t][i][j] = cmp(t,A[t][DP[t][i-1][j]],A[t][DP[t][i-1][x]]) ? DP[t][i-1][j] : DP[t][i-1][x];
    }
}
int query(int t,int l,int r){
  int idx = msb[r-l+1], sub = (1<<idx);
  return cmp(t,A[t][DP[t][idx][l]],A[t][DP[t][idx][r-sub+1]])?DP[t][idx][l]:DP[t][idx][r-sub+1];
}
void build_msb(){
  int mx = -1;
  for(int i=0;i<N;i++){
    if(i>=(1<<(mx+1)))mx++;
    msb[i]=mx;
  }
}
int main()
{
  build_msb();si(n);
  for(int i=0;i<2;i++)
    for(int j=1;j<=n;j++){
      si(A[i][j]);
      mp[A[i][j]];
    }
  for(auto &it:mp)
    it.S = len++;
  for(int i=0;i<2;i++)
    for(int j=1;j<=n;j++)
      A[i][j]=mp[A[i][j]];
  for(int i=0;i<2;i++)build(i);
  LL Ans = 0;
  for(int i=1;i<=n;i++){
    int l = i, h = n, R1 = 0,R2 = -1,ans = 0;
    while(l<=h){
      int m = (l+h)/2;
      int mx = query(0,i,m);
      int mn = query(1,i,m);
      if(A[0][mx] < A[1][mn])l = m+1;
      else ans = m, h = m-1;
    }
    if(ans && A[0][query(0,i,ans)]==A[1][query(1,i,ans)])R1 = ans;
    l = i, h = n, ans = 0;
    while(l<=h){
      int m = (l+h)/2;
      int mx = query(0,i,m);
      int mn = query(1,i,m);
      if(A[0][mx] <= A[1][mn])ans = m,l = m+1;
      else h = m-1;
    }
    if(ans && A[0][query(0,i,ans)]==A[1][query(1,i,ans)])R2 = ans;
    Ans += R2-R1+1;
  }
  cout<<Ans<<endl;
	return 0;
}