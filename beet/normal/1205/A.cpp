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


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  if(~n&1) drop("NO");
  vector<Int> ans(n*2);
  for(Int i=0;i<n;i++){
    if(~i&1){
      ans[0+i]=i*2+1;
      ans[n+i]=i*2+2;
    }else{
      ans[0+i]=i*2+2;
      ans[n+i]=i*2+1;
    }
  }

  {
    vector<Int> sm(n*2+1,0);
    for(Int i=0;i<n*2;i++) sm[i+1]=sm[i]+ans[i];
    set<Int> ss;
    for(Int i=0;i<=n;i++) ss.emplace(sm[n+i]-sm[i]);
    assert(ss.size()==2u);
  }

  cout<<"YES"<<endl;
  for(Int i=0;i<n*2;i++){
    if(i) cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
  return 0;
}