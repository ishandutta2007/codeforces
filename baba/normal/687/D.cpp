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

const int N = int(1e3)+10;
const int M = (N*(N-1))/2;
const int LOGM = 23;
int U[M],V[M],W[M],n,m,q,C[N],dsu[N],sz[N];
bool cmp(int a,int b){
  return W[a]>W[b];
}
inline int Find(int x){
  if(x==dsu[x])return x;
  int p = Find(dsu[x]);
  C[x] ^= C[dsu[x]];
  return dsu[x]=p;
}
inline bool Union(int a,int b){
  int x = Find(a), y = Find(b);
  if(x==y)return false;
  if(sz[x]>sz[y])swap(x,y),swap(a,b);
  int p = (C[a]==C[b]);
  C[x] ^= p;
  sz[y] += sz[x];
  dsu[x] = y;
  Find(a);Find(b);
  return true;
}
struct tree{
  VI edges;
  int ans;
  tree(){edges.clear();}
  tree(int l,int r){
    for(int i=l;i<=r;i++)
      edges.PB(i);
    sort(ALL(edges),cmp);
  }
  tree(VI& _edges){edges = _edges;}
  inline void build(){
    ans = -1;
    for(auto e:edges){
      C[U[e]]=C[V[e]]=0;
      dsu[U[e]] = U[e];
      dsu[V[e]] = V[e];
      sz[U[e]]=sz[V[e]]=1;
    }
    VI want;
    for(auto e:edges)
      if(Union(U[e],V[e]))
        want.PB(e);
      else if(ans==-1&&C[U[e]]==C[V[e]])
        ans = W[e],want.PB(e);
    edges = want;
  }
};
tree ST[4*M],null;
inline tree merge(tree &A,tree &B){
  VI edges;
  VI &a = A.edges, &b = B.edges;
  if(a.empty()||b.empty())return (a.empty()?B:A);
  int i=0,j=0;
  while(i<SZ(a) && j<SZ(b))
    if(W[a[i]]>W[b[j]])edges.PB(a[i++]);
    else edges.PB(b[j++]);
  while(i<SZ(a))edges.PB(a[i++]);
  while(j<SZ(b))edges.PB(b[j++]);
  tree ret(edges);
  ret.build();
  return ret;
}
#define lc (x<<1)
#define rc (x<<1)|1
inline void build(int l=1,int r=m+1,int x=1){
  if(l==r-1){
    ST[x] = tree(l,l);
    ST[x].build();
    return;
  }
  int m = (l+r)/2;
  build(l,m,lc);
  build(m,r,rc);
  ST[x] = merge(ST[lc],ST[rc]);
}
inline tree query(int L,int R,int l=1,int r=m+1,int x=1){
  if(l>=L && r<=R)return ST[x];
  if(l>=R || r<=L)return null;
  int m = (l+r)/2;
  tree la = query(L,R,l,m,lc);
  tree ra = query(L,R,m,r,rc);
  return merge(la,ra);
}
int main()
{
  si(n);si(m);si(q);
  for(int i=1;i<=m;i++)
    scanf("%d %d %d",U+i,V+i,W+i);
  build();
  while(q--){
    int l,r;
    si(l);si(r);
    dout(query(l,r+1).ans);
  }
  return 0;
}