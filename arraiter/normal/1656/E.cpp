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

const int maxn=1e5+10;
int n,rt;ll ans[maxn];

vi E[maxn];

int mxd;
int dep[maxn],L[2],R[2];bool leaf[2];
void dfs(int u,int f){
  chkmax(mxd,dep[u]);
  if(f){
    int x=E[u].size()-1;
    if(L[dep[u]&1]==-1)L[dep[u]&1]=R[dep[u]&1]=x;
    else chkmin(L[dep[u]&1],x),chkmax(R[dep[u]&1],x);
    if(E[u].size()==1u){
      leaf[dep[u]&1]=1;
    }
  }
  for(int v:E[u])if(v!=f){
    dep[v]=dep[u]+1;
    dfs(v,u);
  }
}
void dfs2(int u,int f){
  for(int v:E[u])if(v!=f){
    ans[u]-=ans[v];
  }
  for(int v:E[u])if(v!=f){
    dfs2(v,u);
  }
}

void solve(){
  n=read();
  rep(i,1,n)E[i].clear();
  rep(i,2,n){
    int u=read(),v=read();
    E[u].push_back(v);
    E[v].push_back(u);
  }
  dfs(1,0);
  rep(i,1,n)printf("%d%c",(dep[i]&1?1:-1)*(int)E[i].size(),"\n "[i<iend]);
}

signed main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
  int T;cin>>T;while(T--)solve();
//  solve();
  orzjk::flush();
  return 0;
}