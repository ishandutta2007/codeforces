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

const int MOD = int(1e6)+3;
LL mod = MOD-1;
LL get(LL x,LL p){
  LL ret = 0;
  LL d = p;
  while(x/d)ret+=x/d,d = d * p;
  return ret%mod;
}
LL power(LL a,LL p,LL mod){
  LL ret=1;
  while(p){
    if(p&1)ret=ret*a%mod;
    a=a*a%mod;
    p/=2;
  }
  return ret;
}
int main()
{
  LL n,k;
  sll(n);sll(k);
  LL gcd = get(k-1,2);
  LL den = power(2,((k%mod)*(n%mod)%mod - n%mod - gcd + 10*mod)%mod,MOD);
  if(n <= 62 && (1ll<<n) < k){
    puts("1 1");
    return 0;
  }
  if(k > MOD){
    LL ans = den;
    printf("%lld %lld\n",ans,ans);
    return 0;
  }
  LL p = 1;
  for(LL x = 1; x < k; x++){
    p = p * ((power(2,n%mod,MOD)-x+MOD)%MOD) % MOD;
  }
  p = p * (power(power(2,gcd,MOD),MOD-2,MOD))%MOD;
  LL num = (den - p + 10*MOD)%MOD;
  printf("%lld %lld\n",num,den);
	return 0;
}