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
const int MAX = int(1e6)+10;
const int N = int(2e5)+10;
const int MOD = int(1e9)+ 7;
int A[N];
int F[MAX];
vector<int> D[MAX];
int S[MAX];
int add(int a,int b){
  a = a + b;
  if(a >= MOD) a -= MOD;
  return a;
}
int mult(int a,int b){
  return (a * 1ll * b) % MOD;
}
int power(int a,int p){
  int ret = 1;
  while(p){
    if(p & 1) ret = mult(ret,a);
    a = mult(a,a);
    p /= 2;
  }
  return ret;
}
int get(int n){
  if(!n)return 0;
  return mult(power(2,n-1),n);
}
int main()
{
  for(int i=1;i<MAX;i++)
    for(int j=i;j<MAX;j+=i)
      D[j].PB(i);
  int n;si(n);
  for(int i=1;i<=n;i++){
    int x;si(x);
    for(auto it : D[x]){
      F[it]++;
    }
  }
  int ans = 0;
  for(int i = MAX - 1;i > 1; i--){
    int rem = 0;
    for(int j = 2 * i; j < MAX; j += i){
      rem = add(rem,S[j]);
    }
    int total = get(F[i]);
    S[i] = total - rem;
    if(S[i] < 0)S[i] += MOD;
    ans = add(ans,mult(i,S[i]));
  }
  dout(ans);
	return 0;
}