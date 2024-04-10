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

int par[10],P[10],num[10];
LL A[10],mod[10][10],kakksBond[10];
map<LL,int> dp;
int get(LL x){
  if(dp.count(x))return dp[x];
  int &cnt = dp[x];
  for(LL i = 2; i * i <= x; i++){
    while(x % i == 0){
      x = x / i;
      cnt++;
    }
  }
  if(x > 1)cnt++;
  return cnt;
}
int main()
{
  int n;si(n);
  for(int i=1;i<=n;i++){
    sll(A[i]);
    P[i] = i;
    num[i] = get(A[i]);
  }
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      mod[i][j] = A[i] % A[j];
  int ans = 10000;
  do{
    for(int i=1;i<=n;i++){
      par[P[i]] = 0;
      for(int j=i-1;j>0;j--)
        if(mod[P[j]][P[i]] == 0){
          par[P[i]] = P[j];
          break;
        }
    }
    bool ok = true;
    for(int i=1;i<=n;i++)kakksBond[i] = A[i];
    for(int i=1;i<=n;i++){
      if(!par[i])continue;
      ok &= (kakksBond[par[i]] % A[i] == 0);
      kakksBond[par[i]] /= A[i];
    }
    if(!ok)continue;
    int cans = 0;
    int wantRoot = -1;
    
    for(int i=1;i<=n;i++){
      if(par[i] == 0){
        cans += get(A[i]) + (get(A[i]) == 1 ? 0 : 1);
        wantRoot++;
      }
      else if(get(A[i])!=1) cans++;
    }
    if(wantRoot)cans++;
    ans = min(ans,cans);

  }while(next_permutation(P+1,P+1+n));
  dout(ans);
	return 0;
}