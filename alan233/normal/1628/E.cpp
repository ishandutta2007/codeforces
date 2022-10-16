// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}

namespace IO {
  const int SIZE = 1 << 16;
  char ibuf[SIZE]; int iS, iT;
  char obuf[SIZE]; int oT;
  inline char gc() {
    if (iS == iT)
      iS = 0, iT = fread(ibuf, 1, SIZE, stdin);
    return iS == iT ? EOF : ibuf[iS++];
  }
  inline void pc(char c) {
    obuf[oT++] = c;
    if (oT == SIZE)
      fwrite(obuf, 1, SIZE, stdout), oT = 0;
  }
  inline int read() {
    int x = 0, f = 0;
    char c = gc();
    while (!isdigit(c)) f |= c == '-', c = gc();
    while (isdigit(c)) x = 10 * x + c - '0', c = gc();
    return f ? -x : x; 
  }
  inline void print(int64_t x) {
    static char bufn[64];
    int len = 0;
    if (x < 0) x = -x, pc('-');
    while (x >= 10) bufn[len++] = x % 10 + '0', x /= 10;
    bufn[len++] = x + '0';
    while (len--) pc(bufn[len]);
  }
  inline void print(int64_t x, char ch) {
    print(x), pc(ch);
  }
  struct ff {
    ~ff() {
      if (oT)
        fwrite(obuf, 1, oT, stdout);
    }
  } flusher;
}
using namespace IO;

const int N=600005;

struct DSU{
    int f[N];
    void init(int n){
        iota(f+1,f+n+1,1);
    }    
    int find(int x){
        return f[x]==x?x:f[x]=find(f[x]);
    }
    void merge(int x,int y){
        f[find(x)]=find(y);
    }
}dsu;

struct E{
    int u,v,w;
    friend bool operator < (const E&a,const E&b){
        return a.w<b.w;
    }
}e[N];

vector<int>adj[N];
int n,q,tot;

int W[N],sz[N],son[N];
int dad[N],dep[N];

void dfs1(int u){
    sz[u]=1;
    for(auto v:adj[u]){
        dad[v]=u,dep[v]=dep[u]+1;
        dfs1(v);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]])son[u]=v;
    }    
}
int bl[N];
void dfs2(int u,int topf){
    bl[u]=topf;
    if(son[u])dfs2(son[u],topf);
    for(auto v:adj[u]){
        if(v!=son[u])dfs2(v,v);
    }
}

inline int LCA(int u,int v){
//    printf("? LCA %d %d\n",u,v);
    if(!u||!v)return u|v;
    while(bl[u]!=bl[v]){
        if(dep[bl[u]]<dep[bl[v]])swap(u,v);
        u=dad[bl[u]];
    }    
    if(dep[u]>dep[v])swap(u,v);
//    printf("!!!\n");
    return u;
}

struct NODE{
    int who,cov,lca;
}tr[N<<2];

struct SMT{
    #define ls (u<<1)
    #define rs (u<<1|1)
    void pushup(int u){
        tr[u].lca=LCA(tr[ls].lca,tr[rs].lca);
    }
    void pushcov(int u,int opt){
        if(opt==1)tr[u].lca=tr[u].who;
        else tr[u].lca=0;
        tr[u].cov=opt;
    }
    void pushdown(int u){
        if(tr[u].cov){
            pushcov(ls,tr[u].cov);
            pushcov(rs,tr[u].cov);
            tr[u].cov=0;
        }
    }
    void build(int u,int l,int r){
        if(l==r){
            tr[u].who=l;
            return;
        }
        int mid=l+r>>1;
        build(ls,l,mid),build(rs,mid+1,r);
        tr[u].who=LCA(tr[ls].who,tr[rs].who);
    }    
    void update(int u,int l,int r,int ql,int qr,int opt){
        if(ql<=l&&r<=qr){
            pushcov(u,opt);
            return;
        }
        pushdown(u);
        int mid=l+r>>1;
        if(ql<=mid)update(ls,l,mid,ql,qr,opt);
        if(qr>mid)update(rs,mid+1,r,ql,qr,opt);
        pushup(u);
    }
}smt;

int main(){
    n=read(),q=read();
    rep(i,1,n-1){
        e[i].u=read(),e[i].v=read(),e[i].w=read(); 
    } 
    sort(e+1,e+n);
//    rep(i,1,n-1){
//        printf("(%d,%d,%d)\n",e[i].u,e[i].v,e[i].w);
//    }
    dsu.init(n<<1),tot=n;
    rep(i,1,n)W[i]=-1;
    rep(i,1,n-1){
        int u=dsu.find(e[i].u),v=dsu.find(e[i].v);
        tot++,adj[tot].pb(u),adj[tot].pb(v),W[tot]=e[i].w;
//        printf("add tot=%d,u=%d,v=%d\n",tot,u,v);
//        printf("%d %d\n",e[i].u,e[i].v);
        dsu.f[u]=dsu.f[v]=tot;
    }
    dfs1(tot);
//    cerr<<"!\n";
    dfs2(tot,tot);
//    cerr<<"!\n";
    smt.build(1,1,tot);
//    cerr<<"!\n";
    while(q--){
        int opt=read();
        if(opt==1||opt==2){
            int l=read(),r=read();
            smt.update(1,1,tot,l,r,opt==1?1:-1);
        }else{
            int x=read();
            print(W[LCA(tr[1].lca,x)],'\n');
        }
    }
    return 0;
}