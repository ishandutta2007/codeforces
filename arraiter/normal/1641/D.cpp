#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

#define pb push_back
#define ALL(x) (x).begin,(x).end()
#define mem(x) memset((x),0,sizeof(x))

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
  static char st[21];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

const int P=998244353;
int qp(int a,int k){
  int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;
}

const int maxn=1e5+10;
int n,m,A[maxn][5],W[maxn];

int vtt,dat[maxn*5],buk[maxn*5];

typedef unsigned long long u64;

const int N=5000>>4;
int all[N+1];

struct BS{
  int arr[N+1];
  void clr(){
    memcpy(arr,all,sizeof all);
  }
  void upd(int x){
    arr[x>>4]&=~(1<<(x&15));
  }
  bool test(int x){
    return arr[x>>4]>>(x&15)&1;
  }
  void orz(const BS&o){
    for(int i=0;i<=N;++i){
      arr[i]&=o.arr[i];
    }
  }
}bit,zzh[25001];

int B[N+1][65536];

int L,R,ans=2e9+1;

int h[maxn*5],nxt[maxn*5],key[maxn*5],ecnt;

const int inf=1e9;

void solve(){
  memset(W,0x3f,sizeof W);
  rep(i,0,5000>>4)all[i]=(1<<16)-1;
  n=read(),m=read();
  rep(i,1,n){
    rep(j,0,m-1)dat[(i-1)*m+j+1]=A[i][j]=read();
    W[i]=read();
  }
  vtt=n*m;
  sort(dat+1,dat+vtt+1);
  vtt=unique(dat+1,dat+vtt+1)-dat-1;
  rep(i,1,n)rep(j,0,m-1)A[i][j]=lower_bound(dat+1,dat+vtt+1,A[i][j])-dat;
  static const int gg=5000;
  for(int st=1;st<=n;st+=gg){
    L=st,R=min(n,L+gg-1);
    memset(buk,0,sizeof buk);
    mem(h),ecnt=0;
    int mn=2e9;
    rep(i,L,R)chkmin(mn,W[i]);
    rep(i,L,R)rep(j,0,m-1){
      buk[A[i][j]]++;
      nxt[++ecnt]=h[A[i][j]];
      key[ecnt]=i-L+1;
      h[A[i][j]]=ecnt;
    }
    static int mp[maxn*5];
    int now=0;
    rep(v,1,vtt)if(buk[v]>50){
      mp[v]=++now;
      auto&cur=zzh[now];
      cur.clr();
//      rep(j,1,R-L+1)if(cur.test(j))printf("%d : %d\n",v,j);
      for(int p=h[v];p;p=nxt[p]){
        cur.upd(key[p]);
      }
    }
    memset(B,0x3f,sizeof B);
    static int op[5100];
    memset(op,0x3f,sizeof op);
    rep(i,L,R)op[i-L+1]=W[i];
    rep(i,0,N){
      int*seq=op+i*16;
//      if(i==0)rep(j,0,15)printf("#%d : %d\n",j,seq[j]);
      rep(S,1,65535){
        B[i][S]=min(seq[__builtin_ctz(S)],B[i][S&(S-1)]);
      }
    }
    rep(i,1,R)if(W[i]+mn<ans){
      bit.clr();
      rep(j,0,m-1){
        int v=A[i][j];
        if(buk[v]<=50){
          for(int p=h[v];p;p=nxt[p]){
            bit.upd(key[p]);
//            printf("%d %d : %d\n",i,v,key[p]);
          }
        }else{
          v=mp[v];
          bit.orz(zzh[v]);
        }
      }
      int res=2e9;
//      rep(j,1,R-L+1)if(bit.test(j))chkmin(res,W[L+j-1]),printf("%d : %d\n",i,L+j-1);
      rep(j,0,N)chkmin(res,B[j][bit.arr[j]]);
      if(res<=inf)chkmin(ans,W[i]+res);
    }
  }
  cout<<(ans>2e9?-1:ans)<<endl;
}

signed main(){
//  int T;cin>>T;
//  while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}