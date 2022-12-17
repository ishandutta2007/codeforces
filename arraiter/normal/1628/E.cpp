#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define mem(x) memset((x),0,sizeof(x))

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

typedef unsigned u32;
typedef unsigned uint;
typedef unsigned long long u64;

namespace orzjk{
  const int SZ=1e6;
  char buf[SZ],*p1=buf,*p2=buf;
  char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
  }
  char fub[SZ],*p3=fub,*p4=fub+SZ;
  void pc(char c){
    p3==p4&&(fwrite(fub,1,SZ,stdout),p3=fub);
    *p3++=c;
  }
  void flush(){
    fwrite(fub,1,p3-fub,stdout),p3=fub;
  }
}
using orzjk::nc;
using orzjk::pc;

//#define nc getchar
//#define pc putchar

int read(){
  int x=0,f=1;char c=nc();
  while(c<48)c=='-'&&(f=-1),c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return x*f;
}
void write(int x){
  static char st[21];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

//const int P=1e9+7;
const int P=998244353;
int qp(int a,int k){
  int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;
}

const int maxn=6e5+10;
int n,q;

struct edge{
  int u,v,w;
}G[maxn];

int par[maxn];
int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}

int pv[maxn],ch[maxn][2];
int fa[maxn],sz[maxn],son[maxn],top[maxn],dep[maxn],dfn[maxn],seq[maxn];
void dfs1(int u,int f){
  if(!u)return;
  fa[u]=f,sz[u]=1,dep[u]=dep[f]+1;
  rep(_,0,1){
    int v=ch[u][_];
    dfs1(v,u),sz[u]+=sz[v];
    if(sz[son[u]]<sz[v])son[u]=v;
  }
}
void dfs2(int u,int tp){
  top[u]=tp;
  static int now;dfn[u]=++now,seq[now]=u;
  if(son[u])dfs2(son[u],tp);
  if(son[u])rep(_,0,1){
    int v=ch[u][_];
    if(v!=son[u])dfs2(v,v);
  }
}
int qlca(int u,int v){
  for(;top[u]!=top[v];u=fa[top[u]]){
    if(dep[top[u]]<dep[top[v]])swap(u,v);
  }
  return dep[u]<dep[v]?u:v;
}

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

struct node{
  int x,y;
}val[maxn<<2],tmp[maxn<<2][2];int cov[maxn<<2];
node operator+(node A,node B){
  return{min(A.x,B.x),max(A.y,B.y)};
}
void pushtag(int k,int x){
  cov[k]=x,val[k]=tmp[k][x];
}
void pushdown(int k){
  if(~cov[k]){
    pushtag(k<<1,cov[k]);
    pushtag(k<<1|1,cov[k]);
    cov[k]=-1;
  }
}
void build(int k,int l,int r){
  cov[k]=-1,val[k]=tmp[k][0]={(int)1e9,0};
  if(l==r)tmp[k][1]={dfn[l],dfn[l]};
  else build(lson),build(rson),tmp[k][1]=tmp[k<<1][1]+tmp[k<<1|1][1];
}
void upd(int k,int l,int r,int ql,int qr,int x){
  if(ql<=l&&r<=qr)return pushtag(k,x);
  pushdown(k);
  if(ql<=mid)upd(lson,ql,qr,x);
  if(qr>mid)upd(rson,ql,qr,x);
  val[k]=val[k<<1]+val[k<<1|1];
}
node query(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return val[k];
  pushdown(k);
  if(qr<=mid)return query(lson,ql,qr);
  if(ql>mid)return query(rson,ql,qr);
  return query(lson,ql,qr)+query(rson,ql,qr);
}
void print(int k,int l,int r){
//  printf("(%d %d %d) (%d %d)\n",k,l,r,val[k].x,val[k].y);
  if(l==r)printf("%d%c",cov[k],"\n "[l<n]);
  else pushdown(k),print(lson),print(rson);
}

#undef mid

void solve(){
  n=read(),q=read();
  rep(i,1,n-1){
    G[i].u=read(),G[i].v=read(),G[i].w=read();
  }
  sort(G+1,G+n,[](edge P,edge Q){
    return P.w<Q.w;
  });
  rep(i,1,n)par[i]=i;
  int tot=n;
  rep(i,1,n-1){
    int u=G[i].u,v=G[i].v;
    int x=find(u),y=find(v);
    ++tot,pv[tot]=G[i].w,par[tot]=tot;
    ch[tot][0]=x,ch[tot][1]=y,par[x]=par[y]=tot;
  }
  dfs1(tot,0);
  dfs2(tot,tot);
  build(1,1,n);
  while(q--){
    int op=read();
    if(op==3){
      int u=read();
      node tp=val[1];
      if(tp.x>tot){
        write(-1),pc(10);continue;
      }
      int x=seq[tp.x],y=seq[tp.y];
//      printf("(%d %d)\n",x,y);
      int anc=qlca(x,y);
      int goal=qlca(u,anc);
      write(goal==u?-1:pv[goal]),pc(10);
    }else{
      int l=read(),r=read();
      upd(1,1,n,l,r,2-op);
//      print(1,1,n);
    }
  }
}

signed main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
//  int T;cin>>T;while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}