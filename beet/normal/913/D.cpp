#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T> void chmin(T &a,T b){if(a>b) a=b;}
template<typename T> void chmax(T &a,T b){if(a<b) a=b;}

signed main(){
  Int n,m;
  cin>>n>>m;
  vector<Int> a(n),t(n);
  for(Int i=0;i<n;i++) cin>>a[i]>>t[i];

  using P = pair<Int, Int>;
  Int ans=0;
  priority_queue<P> lst;
  auto solve=[&](bool flg){
    priority_queue<P> pq;
    for(Int i=0;i<n;i++) pq.emplace(-t[i],i);
    Int tmp=0;
    priority_queue<P> s;
    for(Int i=1;i<=n;i++){
      while(!s.empty()&&-s.top().first<i){
	tmp-=t[s.top().second];s.pop();
      }
      while((Int)s.size()<i){
	if(pq.empty()) break;
	Int k=pq.top().second;pq.pop();
	while(!pq.empty()&&a[k]<i){
	  k=pq.top().second;pq.pop();
	}
	if(a[k]<i) break;
	s.emplace(-a[k],k);
	tmp+=t[k];
      }
      if(!flg&&tmp<=m&&(Int)s.size()>=i) ans=i;
      if(flg&&ans==i) lst=s;
    }
  };
  solve(0);solve(1);
  cout<<ans<<endl;
  cout<<lst.size()<<endl;
  Int flg=0;
  while(!lst.empty()){
    if(flg) cout<<" ";
    flg=1;
    cout<<lst.top().second+1;
    lst.pop();
  }
  cout<<endl;
  return 0;
}