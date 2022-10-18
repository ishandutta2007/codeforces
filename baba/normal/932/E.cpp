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

const int N = 5e3 + 10;
const int MOD = 1e9 + 7;
inline int add(int a, int b){
  a = a + b;
  if(a >= MOD)a -= MOD;
  return a;
}
inline int mul(int a, int b){
  return a * 1ll * b % MOD;
}
inline int power(int a, int p){
  int ret = 1;
  while(p){
    if(p & 1)ret = mul(ret, a);
    a = mul(a, a);
    p >>= 1;
  }
  return ret;
}
inline int inv(int x){
  return power(x, MOD - 2);
}
int nCr(int n, int r){
  int num = 1, den = 1;
  for(int sub = 0; sub < r; sub++){
    num = mul(num, n - sub);
    den = mul(den, sub + 1);
  }
  return mul(num, inv(den));
}
int ST[N][N], fact[N];
void pre(){
  fact[0] = 1;
  FOR(i, 1, N)fact[i] = mul(i, fact[i - 1]);
  FOR(i, 1, N)ST[i][1] = 1;
  FOR(i, 2, N)FOR(j, 2, i + 1){
    ST[i][j] = add(ST[i - 1][j - 1], mul(j, ST[i - 1][j]));
  }
}
int main()
{
  int n, k;
  cin >> n >> k;
  pre();
  int sum = 0;
  REP(i, k + 1){
    int v = fact[i];
    v = mul(v, ST[k][i]);
    v = mul(v, nCr(n, i));
    v = mul(v, inv(power(2, i)));
    sum = add(sum, v);
  }
  sum = mul(sum, power(2, n));
  cout << sum << endl;
	return 0;
}