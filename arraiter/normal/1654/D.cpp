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

const int maxn=2e5+10;

vector<int>fac[maxn];int inv[maxn];
void sieve(){
  int N=2e5;
  inv[1]=1;rep(i,2,N)inv[i]=1ll*(P-P/i)*inv[P%i]%P;
  rep(i,2,N)if(fac[i].empty()){
    for(int j=i;j<=N;j+=i){
      int x=j;
      while(x%i==0)x/=i,fac[j].push_back(i);
    }
  }
}

int n;

int ecnt=1,h[maxn];
struct edges{
  int nxt,to,x,y;
}E[maxn<<1];
void addline(int u,int v,int x,int y){
  E[++ecnt]={h[u],v,x,y},h[u]=ecnt;
}

int ans,cur;
int A[maxn],B[maxn];

void dfs(int u,int f){
  ans=(ans+cur)%P;
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(v!=f){
      int tp=cur;
      for(int d:fac[E[i].x]){
        A[d]++;
        cur=1ll*cur*d%P;
      }
      for(int d:fac[E[i].y]){
        A[d]--;
        cur=1ll*cur*inv[d]%P;
        chkmin(B[d],A[d]);
      }
      dfs(v,u);
      for(int d:fac[E[i].x]){
        A[d]--;
      }
      for(int d:fac[E[i].y]){
        A[d]++;
      }
      cur=tp;
    }
  }
}

void solve(){
  n=read();
  rep(i,1,n)B[i]=A[i]=h[i]=0;ecnt=1;
  rep(i,2,n){
    int u=read(),v=read(),x=read(),y=read();
    swap(x,y);
    addline(u,v,x,y);
    addline(v,u,y,x);
  }
  ans=0;
  cur=1;
  dfs(1,0);
  rep(i,1,n){
    int x=B[i];
    if(x)ans=1ll*ans*qp(i,-x)%P;
  }
  write(ans),pc(10);
}

signed main(){
  sieve();
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
  int T;cin>>T;while(T--)solve();
//  solve();
  orzjk::flush();
  return 0;
}