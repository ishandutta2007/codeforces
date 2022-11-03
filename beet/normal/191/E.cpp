#include<bits/stdc++.h>
using namespace std;
using Int = long long;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
template <typename T>
using gtree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  Int n,k;
  cin>>n>>k;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  Int D=0;
  auto check=[&](Int x){
    Int cnt=0,tmp=0;
    using P = pair<Int, Int>;
    gtree<P> s;
    if(D) cout<<x<<"====="<<endl;
    for(Int i=0;i<n;i++){
      s.insert(P(-tmp,i));
      tmp+=a[i];
      cnt+=(i+1)-(s.order_of_key(P(x-tmp,-1)));
    }
    if(D) cout<<cnt<<"++JOJOKO"<<endl;
    return cnt>=k;
  };
  Int l=0,r=1e16,off=-1e15;
  while(l+1<r){
    Int m=(l+r)>>1;
    if(check(m+off)) l=m;
    else r=m;
  }
  cout<<l+off<<endl;
  return 0;
}