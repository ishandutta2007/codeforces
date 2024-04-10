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
  vector<Int> ss(n),ts(n);
  for(Int i=0;i<n;i++) cin>>ss[i];
  for(Int i=0;i<n;i++) cin>>ts[i];
  
  sort(ts.begin(),ts.end());

  auto NG=[](){cout<<"NO"<<endl;exit(0);};    
  {
    vector<Int> bss(ss);
    sort(ss.begin(),ss.end());
    Int sum=0;
    for(Int i=0;i<n;i++){
      sum+=ts[i]-ss[i];
      if(sum<0) NG();
    }
    if(sum!=0) NG();
    ss=bss;
  }
  
  using P = pair<Int, Int>;
  vector<P> vp;
  for(Int i=0;i<n;i++) vp.emplace_back(ss[i],i);
  sort(vp.begin(),vp.end());    
  
  using T = tuple<Int, Int, Int>;
  vector<T> ans;
  auto add_edge=
    [&](Int i,Int j,Int d){
      assert(0<=d&&2*d<=ss[j]-ss[i]);
      //cout<<i<<" "<<j<<" "<<d<<endl;
      ans.emplace_back(i,j,d);
    };

  stack<P> sp;
  for(Int i=0;i<n;i++){
    if(vp[i].first==ts[i]) continue;
    if(vp[i].first<ts[i]){
      sp.emplace(ts[i]-vp[i].first,vp[i].second);
      continue;
    }
    if(vp[i].first>ts[i]){
      Int num=vp[i].first-ts[i];
      while(num){
        assert(!sp.empty());
        Int res=min(num,sp.top().first);
        add_edge(sp.top().second,vp[i].second,res);        

        num-=res;
        sp.top().first-=res;
        if(sp.top().first==0) sp.pop();     
      }
      assert(num==0);
      continue;
    }
  }
  
  cout<<"YES"<<endl;
  cout<<ans.size()<<endl;
  assert((Int)ans.size()<=5*n);
  
  for(auto st:ans){
    Int i,j,d;
    tie(i,j,d)=st;
    assert(0<=d&&2*d<=ss[j]-ss[i]);
    ss[i]+=d;
    ss[j]-=d;    
    cout<<i+1<<" "<<j+1<<" "<<d<<"\n";
  }  
  cout<<flush;

  sort(ss.begin(),ss.end());
  assert(ss==ts);
  return 0;
}