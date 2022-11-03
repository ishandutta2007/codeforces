#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=Int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int x0,y0,ax,ay,bx,by;
  cin>>x0>>y0>>ax>>ay>>bx>>by;

  const Int INF = 1e18;

  vector<Int> xx,yy;
  {
    __int128_t x=x0,y=y0;
    while(max(x,y)<INF){
      xx.emplace_back((Int)x);
      yy.emplace_back((Int)y);
      x=ax*x+bx;
      y=ay*y+by;
      chmin(x,INF);
      chmin(y,INF);
    }
  }

  Int n=xx.size();

  Int xs,ys,t;
  cin>>xs>>ys>>t;

  xx.emplace_back(xs);
  yy.emplace_back(ys);

  auto dist=[&](Int i,Int j){
    return abs(xx[i]-xx[j])+abs(yy[i]-yy[j]);
  };

  Int ans=0;
  for(Int s=0;s<n;s++){
    for(Int l=0;l<=s;l++){
      for(Int r=s;r<n;r++){
        // n -> s -> l -> r
        if(dist(n,s)+dist(s,l)+dist(l,r)<=t) chmax(ans,r-l+1);
        // n -> s -> r -> l
        if(dist(n,s)+dist(s,r)+dist(r,l)<=t) chmax(ans,r-l+1);
      }
    }
  }
  cout<<ans<<newl;
  return 0;
}