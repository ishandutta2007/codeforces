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
const int maxn=1e5+10;

int n,a,b,A[maxn];

void solve(){
  n=read(),a=read(),b=read();
  if(abs(a-b)>1||a+b>n-2){
    puts("-1");
    return;
  }
  bool flg=a<b;
  if(a<b)swap(a,b);
  if(a==b){
    A[1]=1;
    int cur=2;
    int l=2,r=n;
    while(a||b){
      A[cur++]=r--;
      A[cur++]=l++;
      a--
      ,
      b--;
    }
    while(l<=r)A[cur++]=l++;
  }else{
    A[1]=1;
    int cur=2;
    int l=2,r=n;
    while(b){
      A[cur++]=r--;
      A[cur++]=l++;
      a--
      ,
      b--;
    }
    A[cur++]=r--;
    while(l<=r)A[cur++]=r--;
  }
  if(flg)rep(i,1,n)A[i]=n-A[i]+1;
  rep(i,1,n)printf("%d%c",A[i],"\n "[i<n]);
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
//  fwrite(out_buf,1,ouf-out_buf,stdout);
  return 0;
}