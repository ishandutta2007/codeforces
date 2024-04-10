#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

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
  static char st[11];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

const int maxn=2e5+10;
int n,A[maxn];

vi E[maxn];ll ans=1e18;

ll F[maxn],sumF[maxn];int mx[maxn],mx2[maxn],out_mx[maxn];
void dfs(int u,int f){
  mx[u]=A[u];
  for(int v:E[u])if(v!=f){
    dfs(v,u);
    chkmax(mx[u],mx[v]);
  }
}
void dfs0(int u,int f){
  int v1=0,v2=0,chk=-1;
  for(int v:E[u])if(v!=f){
    if(v1<mx[v])v2=v1,v1=mx[v],chk=v;
    else if(v2<mx[v])v2=mx[v];
  }
  for(int v:E[u])if(v!=f){
    chkmax(out_mx[v],max(A[u],max(out_mx[u],chk==v?v2:v1)));
    dfs0(v,u);
  }
}
int mxa;
ll G[maxn],out_F[maxn];
void dfs1(int u,int f){
  if(f&&(int)E[u].size()==1){
    F[u]=mx[u]=A[u];
    return;
  }
  mx[u]=A[u];
  F[u]=0;
  for(int v:E[u])if(v!=f){
    dfs1(v,u);
    F[u]+=F[v];
    chkmax(mx[u],mx[v]);
    chkmax(mx2[u],mx[v]);
  }
  sumF[u]=F[u];
  int tp=1e9;
  for(int v:E[u])if(v!=f){
    chkmin(tp,mx[u]-mx[v]);
  }
  F[u]+=tp;
}
void dfs2(int u,int f){
  int v1=0,v2=0,chk=-1;
  for(int v:E[u])if(v!=f){
    if(v1<mx[v])v2=v1,v1=mx[v],chk=v;
    else if(v2<mx[v])v2=mx[v];
  }
  for(int v:E[u])if(v!=f){
    // out_F[v]
    ll&res=out_F[v];
    res=out_F[u];
    res+=sumF[u]-F[v];
    int tp=out_mx[v];
    res+=tp-max(out_mx[u],v==chk?v2:v1);
    ll x=res;
    x+=sumF[v];
    x+=mxa-max(out_mx[v],mx2[v]);
//    printf("%d : (%d %lld) %lld\n",v,tp,res,x+mxa);
    chkmin(ans,x+mxa);
  }
  for(int v:E[u])if(v!=f){
    dfs2(v,u);
  }
}

void solve(){
  n=read();
  rep(i,1,n)A[i]=read(),chkmax(mxa,A[i]);
  rep(i,2,n){
    int u=read(),v=read();
    E[u].push_back(v);
    E[v].push_back(u);
  }
  dfs(1,0),dfs0(1,0);
  dfs1(1,0);
  chkmin(ans,F[1]+mxa);
  dfs2(1,0);
//  rep(i,1,n){
//    dfs1(i,0);
//    printf("%d : %lld\n",i,F[i]);
//    chkmin(ans,F[i]+mxa);
//  }
  cout<<ans<<endl;
}

signed main(){
//  int T;cin>>T;
//  while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}