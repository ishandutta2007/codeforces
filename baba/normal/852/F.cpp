//TooMuchMath
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

const int MAX = int(1e6)+10;
int MOD;
int getMod(int a,int Q){
  int ret = 1;
  for(int p = a; p != 1; p = p * 1ll * a % Q){
    ret++;
  }
  return ret;
}
int power(int a,int p,int mod){
  int ret = 1;
  while(p){
    if(p & 1) ret = (ret * 1ll * a) % mod;
    a = (a * 1ll * a) % mod;
    p >>= 1;
  }
  return ret;
}
int fact[MAX],inv[MAX],A[MAX],ans[MAX];
int nCr(int n, int r){
  if(!(r >= 0 && r <= n))return 0;
  return ((fact[n] * 1ll * inv[n - r])%MOD) * inv[r] % MOD;
}
int sum(int l, int r){
  if(l == 0)return A[r];
  return (A[r] - A[l-1] + MOD) % MOD;
}
int main()
{
  int n,m,a,Q;
  si(n);si(m);si(a);si(Q);
  MOD = getMod(a, Q);
  fact[0] = 1;
  for(int i=1;i<MAX;i++)
    fact[i] = (fact[i-1] * 1ll * i) % MOD;
  for(int i=0;i<MAX;i++)
    inv[i] = power(fact[i],MOD-2, MOD);
  for(int i=0;i<=m;i++){ 
    A[i] = nCr(m, i);
  }
  for(int i=0;i<=m;i++)
    A[i] = (i ? A[i] + A[i-1] : A[i]) % MOD;
  for(int i=m+1;i<n;i++)
    A[i] = A[m];
  VI out;
  for(int i=0;i<n;i++){
    int v = power(a, A[i], Q);
    out.PB(v);
  }
  reverse(ALL(out));
  for(auto x : out)
    printf("%d ",x);
  puts("");


	return 0;
}