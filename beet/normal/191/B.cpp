#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  Int n,k,b;
  cin>>n>>k>>b;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  using P = pair<Int, Int>;
  priority_queue<P> pq;
  for(Int i=0;i<n-1;i++) pq.emplace(a[i],i);
  Int sum=0;
  vector<Int> used(n,0);
  for(Int i=0;i<k-1;i++){
    P p=pq.top();pq.pop();
    sum+=p.first;
    used[p.second]=1;
  }
  Int ans=-1;
  for(Int i=0;i<n-1;i++){
    if(used[i]){
      if(sum+pq.top().first>b){
	ans=i;
	break;
      }
    }else{
      if(sum+a[i]>b){
	ans=i;
	break;
      }
    }
  }
  if(ans<0) cout<<n<<endl;
  else cout<<ans+1<<endl;
  return 0;
}