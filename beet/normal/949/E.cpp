#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';


template<typename V>
V compress(V vs){
  sort(vs.begin(),vs.end());
  vs.erase(unique(vs.begin(),vs.end()),vs.end());
  return vs;
}
template<typename T>
map<T, int> dict(const vector<T> &vs){
  map<T, int> res;
  for(int i=0;i<(int)vs.size();i++)
    res[vs[i]]=i;
  return res;
}
map<char, int> dict(const string &s){
  return dict(vector<char>(s.begin(),s.end()));
}


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

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i],as[i]*=-1;
  as=compress(as);

  vector<int> ans(40),res;
  MFP([&](auto dfs,vector<int> rs,int k)->void{
    if(k>20) return;
    if(ans.size()<=res.size()) return;
    if(rs.empty()){
      ans=res;
      return;
    }

    int odd=0;
    for(int r:rs) odd+=r&1;

    if(odd==0){
      auto calc=[&](int r){return r/2;};
      vector<int> nx;
      for(int r:rs)
        if(calc(r)!=0)
          if(nx.empty() or nx.back()!=r/2)
            nx.emplace_back(r/2);
      dfs(nx,k+1);
      return;
    }

    for(int d=-1;d<=1;d+=2){
      auto calc=[&](int r){return r%2?(r+d)/2:r/2;};
      vector<int> nx;
      for(int r:rs)
        if(calc(r)!=0)
          if(nx.empty() or nx.back()!=calc(r))
            nx.emplace_back(calc(r));
      res.emplace_back(d*(abs(d)<<k));
      dfs(nx,k+1);
      res.pop_back();
    }
  })(as,0);

  cout<<ans.size()<<newl;
  for(int i=0;i<(int)ans.size();i++){
    if(i) cout<<' ';
    cout<<ans[i];
  }
  cout<<newl;
  return 0;
}