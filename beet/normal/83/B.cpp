#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  Int n,k;
  cin>>n>>k;
  vector<Int> v(n);
  for(Int i=0;i<n;i++) cin>>v[i];
  Int s=accumulate(v.begin(),v.end(),Int(0));
  if(s<k){
    cout<<-1<<endl;
    return 0;
  }
  if(s==k){
    cout<<endl;
    return 0;
  }
  Int l=0,r=1e9;
  while(l+1<r){
    Int m=(l+r)>>1;
    Int tmp=0;
    for(Int i=0;i<n;i++)
      tmp+=min(m,v[i]);
    if(tmp<=k) l=m;
    else r=m;
  }
  
  Int tmp=0;
  for(Int i=0;i<n;i++)
    tmp+=min(l,v[i]);
  assert(tmp<=k);
  k-=tmp;
  using P= pair<Int, Int> ;
  deque<P> d;
  for(Int i=0;i<n;i++)
    if(v[i]>l) d.emplace_back(i,v[i]-l);
  
  while(k--){
    P p=d.front();d.pop_front();
    if(p.second>1){
      p.second--;
      d.push_back(p);
    }
  }
  for(Int i=0;i<(Int)d.size();i++){
    if(i) cout<<" ";
    cout<<d[i].first+1;
  }
  cout<<endl;
  return 0;
}