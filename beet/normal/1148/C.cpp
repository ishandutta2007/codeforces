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

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> p(n);
  for(Int i=0;i<n;i++) cin>>p[i],p[i]--;
  vector<Int> uku(p);
  
  using P = pair<Int, Int>;
  vector<P> es;
  auto add_edge=
    [&](Int x,Int y){
      assert(abs(x-y)>=n/2);
      es.emplace_back(x,y);
      swap(p[x],p[y]);      
    };

  for(Int i=0;i<n;i++){
    if(p[i]==0){
      if(i==0) break;      
      if(i>=n/2) add_edge(i,0);
      else{
        add_edge(i,n-1);
        add_edge(n-1,0);
      }
      break;
    }
  }
  assert(p[0]==0);
  
  for(Int i=0;i<n;i++){
    if(p[i]==n-1){
      if(i==n-1) break;
      if(i<n/2) add_edge(i,n-1);
      else{
        add_edge(i,0);
        add_edge(0,n-1);
        add_edge(i,0);
      }
      break;
    }
  }
  assert(p[0]==0);
  assert(p[n-1]==n-1);
    
  auto swapLR=
    [&](Int x,Int y){
      if(x>y) swap(x,y);
      assert(0<=x&&x<n/2);
      assert(n/2<=y&&y<n);
      add_edge(0,y);
      add_edge(x,n-1);
      add_edge(0,n-1);
      add_edge(0,y);
      add_edge(x,n-1);
    };

  vector<Int> ls,rs;
  for(Int i=0;i<n;i++){
    if(i<n/2){
      if(p[i]>=n/2) ls.emplace_back(i);
    }else{
      if(p[i]< n/2) rs.emplace_back(i);
    }
  }
  assert(ls.size()==rs.size());
  for(Int i=0;i<(Int)ls.size();i++)
    swapLR(ls[i],rs[i]);
  
  for(Int i=0;i<n;i++){
    if(i< n/2) assert(p[i]< n/2);
    if(i>=n/2) assert(p[i]>=n/2);
  }  
  
  for(Int i=0;i<n/2;i++){
    if(p[i]==i) continue;
    add_edge(i,n-1);
    while(p[n-1]!=n-1)
      add_edge(n-1,p[n-1]);          
  }
  for(Int i=n/2;i<n;i++){
    if(p[i]==i) continue;
    add_edge(i,0);
    while(p[0]!=0)
      add_edge(0,p[0]);          
  }
  assert(is_sorted(p.begin(),p.end()));
  
  cout<<es.size()<<endl;
  for(auto e:es){
    cout<<e.first+1<<" "<<e.second+1<<"\n";
    assert(abs(e.first-e.second)>=n/2);
    swap(uku[e.first],uku[e.second]);
  }
  cout<<flush;
  assert((Int)es.size()<=5*n);
  assert(is_sorted(uku.begin(),uku.end()));
  return 0;
}