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
#define div divv
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
int A[N], B[N];
inline int add(int a, int b){
  a = a + b;
  if(a >= MOD)a -= MOD;
  return a;
}
inline int mul(int a, int b){
  return (a * 1ll * b) % MOD;
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
inline int div(int a, int b){
  return mul(a, power(b, MOD - 2));
}
int main()
{
  int n;si(n);
  int m;si(m);
  REP(i, n)si(A[i]);
  REP(i, n)si(B[i]);
  int prob = 1;
  int ans = 0;
  REP(i, n){
    //prob that they are equal till i - 1 and A > B at i.
    int cprob = 1; //prob of A[i] > B[i];
    if(A[i] && B[i]){
      cprob = (A[i] > B[i] ? 1 : 0);
    }
    else if(A[i]){
      cprob = div(A[i] - 1, m);
    }
    else if(B[i]){
      cprob = div(m - B[i], m);
    }
    else {
      cprob = div(div(((m * 1ll * (m - 1)) / 2) % MOD, m), m);
    }
    ans = add(ans, mul(prob, cprob));
    //prob that A[i] == B[i];
    if(A[i] && B[i]){
      prob = mul(prob, A[i] == B[i] ? 1 : 0);
    }
    else {
      prob = div(prob, m);
    }
  }
  cout << ans << endl;
	return 0;
}