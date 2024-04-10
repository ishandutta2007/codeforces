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
const LL MOD = LL(1e9)+7;
const int MAX = int(1e6)+10;
LL phi[MAX],primes[MAX];
bool P[MAX];
int len;
LL Phi(LL x){
  if(x < MAX)return phi[int(x)];
  LL ret = 1;
  for(int i=1;i<=len && primes[i] * primes[i] <= x;i++){
    int cnt = 0;
    LL p1 = 1;
    while(x % primes[i] == 0){
      cnt++;
      x = x / primes[i];
      p1 = p1 * primes[i];
    }
    if(!cnt)continue;
    LL p2 = p1 / primes[i];
    p1 = p1 - p2;
    ret = ret * p1;
  }
  if(x != 1)ret = ret * (x - 1);
  return ret;
}
int main()
{
  for(int i=1;i<MAX;i++)phi[i]=i;
  for(int i=2;i<MAX;i++)
    if(!P[i])
      for(int j=i;j<MAX;j+=i){
        if(j>i)P[j] = true;
        phi[j] = (phi[j] * (i - 1)) / i;
      }
  for(int i=2;i<MAX;i++)
    if(!P[i])
      primes[++len] = i;
  LL n,k;
  sll(n);sll(k);
  k = (k+1) / 2;
  LL ans = n;
  for(int i=0;i<k;i++){
    ans = Phi(ans);
    if(ans == 1)break;
  }
  ans = ans % MOD;
  lldout(ans);
	return 0;
}