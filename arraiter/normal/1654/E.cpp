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
int n,A[maxn];

int ans;

static int bsz=100;

void solve2(){
  rep(d,-bsz,bsz)if(d){
    static int dat[maxn];
    rep(i,1,n)dat[i]=A[i]-i*d;
    sort(dat+1,dat+n+1);
    int ct=0;
    rep(i,1,n){
      if(dat[i]!=dat[i-1]){
        ct=0;
      }
      chkmax(ans,++ct);
    }
//    unordered_map<int,int>mp;
//    rep(i,1,n)++mp[A[i]-i*d];
//    for(pii p:mp)chkmax(ans,p.second);
  }
  static int buk[maxn],vis[maxn];
  mem(vis);
  rep(i,1,n){
    int rig=min(n,i+maxn/bsz);
    rep(j,i+1,rig){
      int t=(A[j]-A[i])/(j-i);
      if(t*(j-i)==A[j]-A[i]){
        if(vis[t]!=i)vis[t]=i,buk[t]=0;
        chkmax(ans,(++buk[t])+1);
      }
    }
  }
}

void solve(){
  ans=1;
//  n=1e5;
//  rep(i,1,n)A[i]=Rnd()%n+1;
  cin>>n;
  rep(i,1,n)A[i]=read();
  map<int,int>ct;
  rep(i,1,n)chkmax(ans,++ct[A[i]]);
  solve2();
//  reverse(A+1,A+n+1);
//  solve2();
  cout<<n-ans<<endl;
}

signed main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
//  int T;cin>>T;while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}