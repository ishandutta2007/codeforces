#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  const Int INF = 1e15;
  Int n,m,x,y,v;
  scanf("%lld %lld %lld %lld %lld",&n,&m,&x,&y,&v);
  vector<Int> a(x),b(y);
  for(Int i=0;i<x;i++) scanf("%lld",&a[i]);
  for(Int i=0;i<y;i++) scanf("%lld",&b[i]);

  a.emplace_back(INF);
  b.emplace_back(INF);
  
  a.emplace_back(-INF);
  b.emplace_back(-INF);
  
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  
  Int q;
  scanf("%lld",&q);
  for(Int i=0;i<q;i++){
    Int x1,y1,x2,y2;
    scanf("%lld %lld %lld %lld",&y1,&x1,&y2,&x2);
    if(x1>x2) swap(x1,x2);
    if(y1>y2) swap(y1,y2);
   
    Int ans=INF;
    {
      Int dl=INF;
      Int k=lower_bound(a.begin(),a.end(),x1)-a.begin();
      if(a[k]<=x2) dl=0;
      else chmin(dl,a[k]-x2);
      chmin(dl,x1-a[k-1]);
      chmin(ans,(y2-y1)+(x2-x1)+dl*2);
      //cout<<dl<<endl;
    }
    {
      Int de=INF;
      Int k=lower_bound(b.begin(),b.end(),x1)-b.begin();
      if(b[k]<=x2) de=0;
      else chmin(de,b[k]-x2);
      chmin(de,x1-b[k-1]);
      chmin(ans,(y2-y1+v-1)/v+(x2-x1)+de*2);
      //cout<<de<<endl;
    }
    if(y1==y2) chmin(ans,x2-x1);
    
    printf("%lld\n",ans);
  }
  return 0;
}