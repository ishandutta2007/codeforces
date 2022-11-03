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

//INSERT ABOVE HERE
int ask(int u,int v){
  cout<<"? "<<u+1<<" "<<v+1<<endl;
  int w;
  cin>>w;
  return w-1;
}

int answer(int r){
  cout<<"! "<<r+1<<endl;
  exit(0);
}

signed main(){
  int n;
  cin>>n;

  vector<vector<int>> G(n);
  for(int i=1;i<n;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    G[x].emplace_back(y);
    G[y].emplace_back(x);
  }

  vector<int> dead(n,0);
  while(1){
    int cnt=0;
    vector<int> deg(n,0);
    int r=-1;
    for(int v=0;v<n;v++){
      if(dead[v]) continue;
      cnt++;
      for(int u:G[v])
        if(!dead[u]) deg[v]++;
      if(deg[v]>=2) r=v;
    }

    if(r<0){
      assert(cnt<=2);
      if(cnt==1){
        for(int v=0;v<n;v++)
          if(!dead[v]) answer(v);
      }
      if(cnt==2){
        for(int v=0;v<n;v++){
          if(dead[v]) continue;
          for(int u:G[v]){
            if(dead[u]) continue;
            int w=ask(u,v);
            answer(w);
          }
        }
      }
      assert(0);
    }

    vector<int> cs;
    for(int c:G[r]){
      if(!dead[c]) cs.emplace_back(c);
      if(cs.size()>=2) break;
    }
    assert(cs.size()>=2);

    auto fill_tree=
      MFP([&](auto dfs,int v,int p)->void{
            dead[v]=1;
            for(int u:G[v]){
              if(u==p) continue;
              dfs(u,v);
            }
          });

    int w=ask(cs[0],cs[1]);
    if(w==r){
      fill_tree(cs[0],r);
      fill_tree(cs[1],r);
    }
    if(w==cs[0]) fill_tree(r,cs[0]);
    if(w==cs[1]) fill_tree(r,cs[1]);
  }
  assert(0);
  return 0;
}