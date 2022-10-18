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
const int N = int(2e5)+10;
const int MOD = int(1e9)+7;
VI g[N];
int vis[N],U[N],V[N];
int nn=0,clen,level[N];
LL power(LL a,int p,LL mod){
  LL ret=1;
  while(p){
    if(p&1)ret=ret*a%MOD;
    a=a*a%MOD;
    p/=2;
  }
  return ret;
}
int adj(int u,int e){
  return U[e]^V[e]^u;
}
void dfs(int u,int ee){
  vis[u]=1;nn++;
  for(auto e:g[u]){
    int w = adj(u,e);
    if(!vis[w]){
      level[w]=level[u]+1;
      dfs(w,e);
    }
    else if(e!=ee && !clen)
      clen = level[u] - level[w] + 1;
  }
}
LL get(int i){
  clen = 0;nn=0;
  dfs(i,-1);
  LL x = clen;LL y = nn - clen;
  return ((power(2,x,MOD)-2+MOD)%MOD)*(power(2,y,MOD))%MOD;
}
int main()
{
  int n;si(n);
  for(int i=1;i<=n;i++){
    int x;si(x);
    U[i]=i;V[i]=x;
    g[U[i]].PB(i);
    g[V[i]].PB(i);
  }
  LL ans = 1;
  for(int i=1;i<=n;i++)
    if(!vis[i])
      ans  = (ans*get(i))%MOD;
  lldout(ans);
	return 0;
}