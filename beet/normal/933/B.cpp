#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int p,k;
  while(cin>>p>>k){
    Int t=1,pre=p;
  
    vector<Int> ans;
    while(p){
      ans.emplace_back((p*t)%k);
      if(ans.back()<0) ans.back()+=k;
    
      p-=ans.back()*t;
      p/=k;
      t*=-1;
    }

    cout<<ans.size()<<endl;
    for(Int i=0;i<(Int)ans.size();i++){
      if(i) cout<<" ";
      cout<<ans[i];
    }
    cout<<endl;

    Int tmp=0,po=1;
    for(Int i=0;i<(Int)ans.size();i++){
      tmp+=ans[i]*po;
      po*=-k;
    }
    assert(tmp==pre);
  }
  return 0;
}