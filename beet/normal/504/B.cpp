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


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
template <typename T>
using gtree = tree<T, null_type, less<T>, rb_tree_tag,
                   tree_order_statistics_node_update>;
// usage:
// find_by_order(Int k):
// return the iterator of k-th smallest element (0-indexed)
// order_of_key(T key):  return the index of key in tree

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);


  Int n;
  cin>>n;

  auto encode=[&](auto vs){
    vector<Int> rs(n);
    gtree<Int> G;
    for(Int i=0;i<n;i++) G.insert(i);
    for(Int i=0;i<n;i++){
      rs[i]=G.order_of_key(vs[i]);
      G.erase(G.find(vs[i]));
    }
    return rs;
  };

  auto sum=[&](auto as,auto bs){
    for(Int i=n-1,carry=0;i>=0;i--){
      as[i]+=bs[i]+carry;
      Int d=n-i;
      carry=as[i]/d;
      as[i]%=d;
    }
    return as;
  };

  auto decode=[&](auto vs){
    vector<Int> rs(n);
    gtree<Int> G;
    for(Int i=0;i<n;i++) G.insert(i);
    for(Int i=0;i<n;i++){
      rs[i]=*G.find_by_order(vs[i]);
      G.erase(G.find(rs[i]));
    }
    return rs;
  };

  auto ps=read(n);
  auto qs=read(n);
  auto rs=decode(sum(encode(ps),encode(qs)));
  for(Int i=0;i<n;i++){
    if(i) cout<<' ';
    cout<<rs[i];
  }
  cout<<newl;
  return 0;
}