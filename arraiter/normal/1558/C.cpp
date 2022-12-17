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
const int maxn=3010;
int n,A[maxn];
  vi ans;

void push(int x){
  if(x>1)ans.push_back(x),reverse(A+1,A+x+1);
}
void solve(){
  cin>>n;
  bool asf=1;
  rep(i,1,n)A[i]=read(),asf&=(A[i]&1)==(i&1);
  if(!asf)return puts("-1"),void();
  ans.clear();
  while(n>1){
    if(A[n]==n&&A[n-1]==n-1){
      n-=2;continue;
    }
    if(A[1]==n&&A[2]==n-1){
      push(n),n-=2;continue;
    }
    int p1=-1,p2=-1;
    rep(i,1,n){
      if(A[i]==n)p1=i;
      if(A[i]==n-1)p2=i;
    }
    if(p1<p2){
      if(abs(p1-p2)!=1){
        push(p1);
        push(p2-1);
        rep(i,1,n){
          if(A[i]==n)p1=i;
          if(A[i]==n-1)p2=i;
        }
      }
      push(p2+1);
      rep(i,1,n){
        if(A[i]==n)p1=i;
        if(A[i]==n-1)p2=i;
      }
      push(p1);
      push(n);
    }else{
      push(p1);
      rep(i,1,n){
        if(A[i]==n)p1=i;
        if(A[i]==n-1)p2=i;
      }
      push(p2-1);
      rep(i,1,n){
        if(A[i]==n)p1=i;
        if(A[i]==n-1)p2=i;
      }
      push(p2+1);
      rep(i,1,n){
        if(A[i]==n)p1=i;
        if(A[i]==n-1)p2=i;
      }
      push(p1);
      push(n);
    }
    n-=2;
//    int pos=-1;
//    rep(i,1,n)if(i%2==0)if(A[i]==n-1&&A[i+1]==n){
//      pos=i,push(i+1);break;
//    }
//    if(pos==-1){
//      rep(i,1,n-1)if(i%2==1&&A[i]==n&&A[i+1]==n-1){
//        pos=i;
//        push(i+2);
//        break;
//      }
//      if(pos==-1)return puts("-1"),void();
//      pos=-1;
//      rep(i,1,n)if(i%2==0)if(A[i]==n-1&&A[i+1]==n){
//        pos=i,push(i+1);break;
//      }
//      if(pos==-1)return puts("-1"),void();
//      push(n);
//    }else push(n);
  }
  cout<<ans.size()<<endl;
  for(int x:ans)printf("%d ",x);
  puts("");
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
//  fwrite(out_buf,1,ouf-out_buf,stdout);
  return 0;
}