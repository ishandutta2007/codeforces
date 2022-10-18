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
long long int phi(long long x)
{
  long long int ret = 1,i,pow;
  for (i = 2; x != 1; i++) 
  {
    pow = 1;
    if(i>sqrt(x))break;
    while (!(x%i)) 
    {
      x /= i;
      pow *= i;
    }
    ret *= (pow - (pow/i));
  }
  if(x!=1)ret*=(x-1);
  return ret;
}
LL power(LL a,int p,LL mod){
  LL ret=1;
  while(p){
    if(p&1)ret=ret*a%mod;
    a = a*a%mod;
    p/=2;
  }
  return ret;
}
const int N = int(1e5)+10;
/***************** New **********************/
VI g[N];int sub[N],nn,U[N],V[N],W[N],done[N];
int adj(int u,int e){
  return U[e]^V[e]^u;
}
void dfs1(int u,int p){
  sub[u]=1;nn++;
  for(auto e:g[u]){
    int w = adj(u,e);
    if(w!=p && !done[e])
      dfs1(w,u),sub[u]+=sub[w];
  }
}
int dfs2(int u,int p){
  for(auto e:g[u]){
    if(done[e])continue;int w = adj(u,e);
    if(w!=p && sub[w]>nn/2)
      return dfs2(w,u);
  }return u;
}
LL ans = 0,inv[N],P[N];
int n,m;
map<LL,LL> mp;
void dfs3(int u,int p,LL d,int lvl,bool add){
  trace(u,p,d*inv[lvl] % m,d,m,lvl,inv[lvl]);
  mp[d*inv[lvl] % m] += (add ? +1 : -1);
  if(!add && !d)ans++;
  for(auto e : g[u]){
    if(done[e])continue;
    int w = adj(u,e);
    if(w == p)continue;
    dfs3(w,u,(d * 10  + W[e])%m,lvl+1,add);
  }
}
void dfs4(int u,int p,LL d,int lvl){
  ans += mp[d ? (m - d) : d];
  if(!d) ans++;
  for(auto e : g[u]){
    if(done[e])continue;
    int w = adj(u,e);
    if(w == p)continue;
    dfs4(w,u,(W[e] * P[lvl] + d)%m,lvl+1);
  }
}
void solve(int root){
  mp.clear();
  for(auto e : g[root]){
    if(done[e])continue;
    int w = adj(root,e);
    dfs3(w,root,W[e]%m,1,1);
  }
  for(auto e : g[root]){
    if(done[e])continue;
    int w = adj(root,e);
    dfs3(w,root,W[e]%m,1,0);
    dfs4(w,root,W[e]%m,1);
    dfs3(w,root,W[e]%m,1,1);
  }
}
void decompose(int root,int p){
  nn=0;dfs1(root,root);
  int centroid=dfs2(root,root);
  if(p==-1)p=centroid;//fuck centroid :)
  solve(centroid);
  trace(centroid-1,ans);
  for(auto e:g[centroid]){
    if(done[e])continue;
    done[e]=1;int w = adj(centroid,e);
    decompose(w,centroid);
  }
}
void pre(int m){
  LL p = 1;
  LL x = phi(m);
  trace(x);
  for(int i=0;i<N;i++){
    inv[i] = power(p,x-1,m);
    P[i] = p;
    p = p * 10 % m;
  }
}
int main()
{
  si(n);si(m);
  pre(m);
  for(int i=1;i<=n-1;i++){
    scanf("%d%d%d",U+i,V+i,W+i);
    U[i]++;V[i]++;
    g[U[i]].PB(i);
    g[V[i]].PB(i);
  }
  decompose(1,-1);
  lldout(ans);
  return 0;
}