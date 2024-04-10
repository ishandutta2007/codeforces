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
const int N = int(1e6)+10;
const int MOD = int(1e9)+7;
int L[N],R[N],A[N],rev[N],len;
map<int,int> mp;
LL fact[N],inv[N];
LL power(LL a,int p){
  LL ret = 1;
  while(p){
    if(p&1)ret=ret*a%MOD;
    a=a*a%MOD;
    p/=2;
  }
  return ret;
}
LL nCr(int n,int k){
  if(k > n)return 0;
  return (fact[n]*inv[k]%MOD)*inv[n-k]%MOD;
}
int main()
{
  fact[0]=inv[0]=1;
  for(int i=1;i<N;i++)
    fact[i]=fact[i-1]*i%MOD,
      inv[i] = power(fact[i],MOD-2);
  int n,k;
  si(n);si(k);
  for(int i=1;i<=n;i++){
    scanf("%d %d",L+i,R+i);
    mp[L[i]];mp[R[i]];mp[R[i]+1];
  }
  for(auto &it : mp)
    it.S = len,rev[len]=it.F,len++;
  for(int i=1;i<=n;i++){
    L[i]=mp[L[i]];R[i]=mp[R[i]];
    A[L[i]]++;A[R[i]+1]--;
  }
  for(int i=1;i<len;i++)
    A[i]+=A[i-1];
  LL ans = 0;
  for(int i=0;i<len-1;i++)
    ans = (ans + (rev[i+1]-rev[i])*nCr(A[i],k))%MOD;
  cout<<ans<<endl;
	return 0;
}