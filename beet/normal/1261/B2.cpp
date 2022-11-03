#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
template <typename T>
using gtree = tree<T,null_type,less<T>,rb_tree_tag,
                   tree_order_statistics_node_update>;
// usage:
// find_by_order(int k):
// return the iterator of k-th smallest element (0-indexed)
// order_of_key(T key):  return the index of key in tree


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  int n;
  cin>>n;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  using P = pair<int, int>;
  vector<P> vp;
  for(int i=0;i<n;i++) vp.emplace_back(-as[i],i);
  sort(vp.begin(),vp.end());

  int m;
  cin>>m;
  vector< vector<int> > Q(n+1);
  vector<int> ks(m),ps(m);
  for(int i=0;i<m;i++){
    cin>>ks[i]>>ps[i];
    ps[i]--;
    Q[ks[i]].emplace_back(i);
  }

  gtree<int> G;
  vector<int> ans(m);
  for(int i=0;i<n;i++){
    G.insert(vp[i].second);
    for(int j:Q[i+1])
      ans[j]=as[*G.find_by_order(ps[j])];
  }

  for(int a:ans) cout<<a<<"\n";
  cout<<flush;
  return 0;
}