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
  vector<Int> as(n),ts(n);
  for(Int i=0;i<n;i++) cin>>as[i];
  for(Int i=0;i<n;i++) cin>>ts[i];

  using P = pair<Int, Int>;
  vector<P> vp;
  for(Int i=0;i<n;i++)
    vp.emplace_back(as[i],ts[i]);
  sort(vp.begin(),vp.end());
  for(Int i=0;i<n;i++)
    tie(as[i],ts[i])=vp[i];

  Int ans=0;
  Int lst=0;
  Int sum=0;

  priority_queue<Int> pq;
  for(Int i=0;i<n;i++){
    while(lst<as[i]){
      if(pq.empty()) break;
      sum-=pq.top();pq.pop();
      ans+=sum;
      lst++;
    }
    chmax(lst,as[i]);
    pq.emplace(ts[i]);
    sum+=ts[i];
  }

  while(!pq.empty()){
    sum-=pq.top();pq.pop();
    ans+=sum;
  }

  cout<<ans<<endl;
  return 0;
}