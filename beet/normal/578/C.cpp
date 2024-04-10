#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;


struct Precision{
  Precision(){
    cout<<fixed<<setprecision(12);
  }
}precision_beet;


template <typename T,bool isMin>
struct ConvexHullTrick {
  #define F first
  #define S second
  using P = pair<T, T>;
  deque<P> H;
  bool empty()const{return H.empty();}
  void clear(){H.clear();}

  inline Int sgn(T x){return x==0?0:(x<0?-1:1);}

  using D = long double;
  inline bool check(const P &a,const P &b,const P &c){
    if(b.S==a.S||c.S==b.S)
      return sgn(b.F-a.F)*sgn(c.S-b.S) >= sgn(c.F-b.F)*sgn(b.S-a.S);

    //return (b.F-a.F)*(c.S-b.S) >= (b.S-a.S)*(c.F-b.F);
    return
      D(b.F-a.F)*sgn(c.S-b.S)/D(abs(b.S-a.S)) >=
      D(c.F-b.F)*sgn(b.S-a.S)/D(abs(c.S-b.S));
  }

  //using D = double;
  D intersect(const P &l1,const P &l2) const{
    return D(l2.S-l1.S)/D(l1.F-l2.F);
  }

  void addLine(T m,T b){
    if(!isMin) m*=-1,b*=-1;
    P line(m,b);
    if(empty()){
      H.emplace_front(line);
      return;
    }
    if(H.front().F<=m){
      if(H.front().F==m){
        if(H.front().S<=b) return;
        H.pop_front();
      }
      while(H.size()>=2&&check(line,H.front(),H[1])) H.pop_front();
      H.emplace_front(line);
    }else{
      assert(m<=H.back().F);
      if(H.back().F==m){
        if(H.back().S<=b) return;
        H.pop_back();
      }
      while(H.size()>=2&&check(H[H.size()-2],H.back(),line)) H.pop_back();
      H.emplace_back(line);
    }
  }

  inline T getY(const P &a,const T &x){
    return a.F*x+a.S;
  }

  T query(T x){
    assert(!empty());
    Int l=-1,r=H.size()-1;
    while(l+1<r){
      Int m=(l+r)>>1;
      if(getY(H[m],x)>=getY(H[m+1],x)) l=m;
      else r=m;
    }
    if(isMin) return getY(H[r],x);
    return -getY(H[r],x);
  }

  T queryMonotoneInc(T x){
    assert(!empty());
    while(H.size()>=2&&getY(H.front(),x)>=getY(H[1],x)) H.pop_front();
    if(isMin) return getY(H.front(),x);
    return -getY(H.front(),x);
  }

  T queryMonotoneDec(T x){
    assert(!empty());
    while(H.size()>=2&&getY(H.back(),x)>=getY(H[H.size()-2],x)) H.pop_back();
    if(isMin) return getY(H.back(),x);
    return -getY(H.back(),x);
  }
  #undef F
  #undef S
};

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> as(n);
  for(Int i=0;i<n;i++) cin>>as[i];

  using D = double;
  ConvexHullTrick<D, true>  chi;
  ConvexHullTrick<D, false> cha;

  chi.addLine(0,0);
  cha.addLine(0,0);
  D sum=0;
  for(Int i=0;i<n;i++){
    sum+=as[i];
    chi.addLine(i+1,sum);
    cha.addLine(i+1,sum);
  }

  vector<D> pos;
  pos.emplace_back(0);

  for(Int i=0;i+1<(Int)chi.H.size();i++)
    pos.emplace_back(chi.intersect(chi.H[i],chi.H[i+1]));

  for(Int i=0;i+1<(Int)cha.H.size();i++)
    pos.emplace_back(cha.intersect(cha.H[i],cha.H[i+1]));

  D ans=1e18;
  sort(pos.begin(),pos.end());
  for(auto p:pos) chmin(ans,cha.queryMonotoneInc(p)-chi.queryMonotoneInc(p));
  cout<<ans<<endl;
  return 0;
}