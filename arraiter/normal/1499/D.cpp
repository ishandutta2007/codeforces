#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

#define int long long

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=2e7+10;
int ptt,pri[maxn],D[maxn];

void sieve(){
  rep(i,2,maxn-1){
    if(!pri[i])pri[++ptt]=i,D[i]=1;
    rep(j,1,ptt){
      if(i*pri[j]>=maxn)break;
      pri[i*pri[j]]=1;
      if(i%pri[j]==0){
        D[i*pri[j]]=D[i];break;
      }
      D[i*pri[j]]=D[i]+1;
    }
  }
}

int exgcd(int a,int b,int&x,int&y){
  if(!b){
    return x=1,y=0,a;
  }
  int res=exgcd(b,a%b,x,y);int tp=x;x=y,y=tp-a/b*y;return res;
}

void solve(){
  int c,d,x;
  cin>>c>>d>>x;
  int X,Y;
  int g=exgcd(c,d,X,Y);
  int res=g-g;
  rep(g,1,x){
    if(g*g>x)break;
    if(x%g==0){
      int tp=d*g+x,ano=c*g;
      if(tp%ano==0)res+=1<<D[tp/ano];
      if(x!=g*g){
        int y=x/g;
        tp=d*y+x,ano=c*y;
        if(tp%ano==0)res+=1<<D[tp/ano];
      }
    }
  }
  cout<<res<<endl;
  return;
//  if(num%g!=0){
//    return puts("0"),void();
//  }
////  printf("#%lld %lld\n",x*num/g,y*num/g);
//  x*=num/g;
////  int tp=d/g;
////  if(tp<0)tp=-tp;
////  int res=x%tp;
////  if(res<0)res+=tp;
//  y*=num/g;
////  printf("(%lld %lld)\n",res,tp);
////  tp=c/g;
////  if(tp<0)tp=-tp;
////  int res2=y%tp;
////  if(res2<0)res2+=tp;
////  printf("(%lld %lld)\n",res2,tp);
//  int dx=d/g;
//  if(dx<0)dx=-dx;
//  int dy=c/g;
//  if(dy<0)dy=-dy;
//  int ans=0;
//  rep(k,-1000,1000){
//    int tx=x+k*dx,ty=y+k*dy;
//    if(tx>0&&ty>0&&tx%ty==0){
//      printf("(%lld %lld)\n",tx,ty);
//      ans+=1+(tx!=ty);
//    }
//  }
//  cout<<ans<<endl;
}

signed main(){
  sieve();
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}