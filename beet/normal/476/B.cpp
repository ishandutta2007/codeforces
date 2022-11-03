#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename F>
struct FixPoint : F{
  FixPoint(F&& f):F(forward<F>(f)){}
  template<typename... Args>
  decltype(auto) operator()(Args&&... args) const{
    return F::operator()(*this,forward<Args>(args)...);
  }
};
template<typename F>
inline decltype(auto) MFP(F&& f){
  return FixPoint<F>{forward<F>(f)};
}


struct Precision{
  Precision(){
    cout<<fixed<<setprecision(12);
  }
}precision_beet;

//INSERT ABOVE HERE
signed main(){
  string s,t;
  cin>>s>>t;
  map<char, int> mv;
  mv['+']=+1;
  mv['-']=-1;
  int pos=0;
  for(char c:s) pos+=mv[c];

  using D = double;
  D ans=0;
  int n=t.size();
  MFP([&](auto dfs,int v,int cur,D p)->void{
        if(v==n){
          if(cur==pos) ans+=p;
          return;
        }
        if(mv.count(t[v])){
          dfs(v+1,cur+mv[t[v]],p);
        }else{
          dfs(v+1,cur+1,p/2);
          dfs(v+1,cur-1,p/2);
        }
      })(0,0,1);

  cout<<ans<<endl;
  return 0;
}