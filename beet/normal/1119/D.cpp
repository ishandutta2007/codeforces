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


template<typename T>
vector<T> compress(vector<T> v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}

template<typename T>
map<T, Int> dict(const vector<T> &v){
  map<T, Int> res;
  for(Int i=0;i<(Int)v.size();i++)
    res[v[i]]=i;
  return res;
}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> s(n);
  for(Int i=0;i<n;i++) cin>>s[i];
  s=compress(s);
  n=s.size();
  
  Int q;
  cin>>q;
  vector<Int> x(q);
  for(Int i=0;i<q;i++){
    Int l,r;
    cin>>l>>r;
    x[i]=r-l+1;    
  }
  auto y=compress(x);
  auto id=dict(y);
  
  priority_queue<Int, vector<Int>, greater<Int> > pq;
  for(Int i=0;i+1<n;i++) pq.emplace(s[i+1]-s[i]);  

  Int res=0;
  vector<Int> ans(y.size());
  for(Int i=0;i<(Int)y.size();i++){
    while(!pq.empty()&&pq.top()<=y[i]){
      res+=pq.top();pq.pop();      
    }
    ans[i]=res+(y[i]*((Int)pq.size()+1));
  }
  
  for(Int i=0;i<q;i++){
    if(i) cout<<" ";
    cout<<ans[id[x[i]]];
  }
  cout<<endl;
  return 0;
}