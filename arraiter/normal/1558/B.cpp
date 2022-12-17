#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

//inline char nc(){
//  static char buf[1000000],*p1=buf,*p2=buf;
//  return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
//}

//char out_buf[1<<23|5],*ouf=out_buf; // size
//inline void pc(const char&c){*ouf=c,++ouf;}

#define nc() getchar()
#define pc(x) putchar(x)

inline int read(){
  bool f=0;int x=0;char c=nc();
  while(c<48)f|=c=='-',c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return f?-x:x;
}

void write$(int x){
  if(x>9)write$(x/10);
  pc(x%10|48);
}
void write(int x){
  if(x<0)x=-x,pc('-');
  write$(x);
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=2e6+10;
int n,P,seq[maxn],pw2[2049],B,pwB[2049];

void Add(int&x,int y){
  x+=y-P,x+=x>>31&P;
}
void Sub(int&x,int y){
  x-=y,x+=x>>31&P;
}

inline int qp(int k){
  return 1ll*pwB[k>>11]*pw2[k&2047]%P;
//  int res=1,a=2;
//  for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;
//  return res;
}

inline int suf(int x){
  return x>n?0:x>n/2?qp(n-x):seq[x];
}

void solve(){
  cin>>n>>P;
  pw2[0]=1;rep(i,1,2048)pw2[i]=2*pw2[i-1]%P;B=pw2[2048];
  pwB[0]=1;rep(i,1,2048)pwB[i]=1ll*B*pwB[i-1]%P;
//  per(i,n,n/2+1)suf[i]=qp(n-i);
  per(i,n/2,1){
    int res=suf(i+1);
//    int res=suf[i+1];
//    rep(j,2*i,n)Add(res,1ll*(j/i-j/(i+1))*(suf[j]-suf[j+1]+P)%P);
    rep(j,2,n/i){
      int v=i*j;
      Add(res,1ll*j*(suf(v)-suf(v+i)+P)%P);
    }
    int x=2*i;
    Sub(res,1ll*(x/(i+1))*(suf(x)-suf(x+1)+P)%P);
    x++;
    Sub(res,1ll*(x/(i+1))*(suf(x)-suf(x+1)+P)%P);
    rep(j,2,n/(i+1)){
      int v=(i+1)*j;
      Sub(res,1ll*j*(suf(v)-suf(v+i+1)+P)%P);
    }
    seq[i]=suf(i+1);
    Add(seq[i],res);
//    int v=n-i+1;
//    if(i<=lim){
//      if(i==n)dp[i]=1;
//      Add(dp[i],su);
//      v=dp[i];
//    }
//    Add(su,v);
//    for(int l=2,r;l<=i;l=r+1){
//      int x=i/l;
//      r=i/x;
//      Add(dp[x],1ll*(r-l+1)*v%P);
//    }
  }
  cout<<(suf(1)-suf(2)+P)%P<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
//  fwrite(out_buf,1,ouf-out_buf,stdout);
  return 0;
}