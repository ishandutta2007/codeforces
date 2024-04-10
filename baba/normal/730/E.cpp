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

//#define TRACE

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
const int MAX = N * N * 4;
const int ZERO = 2 * N * N - 1;
int A[N],D[N],P[N],vis[N],kakkarBond[MAX];
bool cmp(int i,int j){
  return A[i] < A[j];
}
int main()
{
  int n;si(n);
  for(int i=1;i<=n;i++){
    si(A[i]);si(D[i]);
    A[i] = A[i] * N - i;
    D[i] = D[i] * N;
    kakkarBond[A[i] + ZERO] = i;
  }
  int ans = 0;
  //left to right
  for(int i=1;i<MAX;i++){
    int x = kakkarBond[i];
    if(x && !vis[x] && D[x] >= 0){
      trace(x,D[x]);
      vis[x] = 1;
      int cnt = 0;
      for(int j=1;j<=n;j++){
        trace(j,A[j],i,i+D[x],vis[j]);
        if(j == x)continue;
        if(vis[j] && A[j] + D[j] >= i - ZERO && A[j] + D[j] <= i + D[x] - ZERO)
          cnt++;
        else if(!vis[j] && A[j] >= i - ZERO && A[j] <= i + D[x] - ZERO)
          cnt++;
      }
      trace(cnt);
      ans += cnt;
      kakkarBond[i + D[x]] = x;
      kakkarBond[x] = 0;
    }
  }
  //right to left
  for(int i=MAX-1;i >= 1; i--){
    int x = kakkarBond[i];
    if(x && !vis[x]){
      trace(x,D[x]);
      assert(D[x] < 0);
      vis[x] = 1;
      int cnt = 0;
      for(int j=1;j<=n;j++){
        if(j == x)continue;
        trace(j,A[j],i,i+D[x],vis[j]);
        if(vis[j] && A[j] + D[j] <= i - ZERO && A[j] + D[j] >= i + D[x] - ZERO)
          cnt++;
        else if(!vis[j] && A[j] <= i - ZERO && A[j] >= i + D[x] - ZERO)
          assert(D[j] < 0), cnt++;
      }
      trace(cnt);
      ans += cnt;
      kakkarBond[i  + D[x]] = x;
      kakkarBond[x] = 0;
    }
  }
  //Kakkar <3 honors & rawat : I was kidding. Please ignore :)
  dout(ans);

	return 0;
}