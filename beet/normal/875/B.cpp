#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin>>n;
  typedef pair<int,int> P;
  set<P> sp;
  sp.insert(P(n+2,n+2));
  cout<<1;
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    P p(k,k+1);
    auto latte=sp.lower_bound(p);
    //cout<<latte->first<<" "<<latte->second<<endl;
    if(p.second==latte->first){
      p.second=latte->second;
      sp.erase(latte);
    }
    auto malta=--sp.lower_bound(p);
    //cout<<malta->first<<" "<<malta->second<<endl;
    if(malta->second==p.first){
      p.first=malta->first;
      sp.erase(malta);
    }
    sp.insert(p);
    if((----sp.end())->second==n+1){
      cout<<" "<<i+2-((----sp.end())->second-(----sp.end())->first);
    }else{
      cout<<" "<<i+2;
    }
    
    
    //cout<<(----sp.end())->first<<" "<<(----sp.end())->second<<endl;
    //cout<<sp.size()-1-((----sp.end())->second==n+1)<<endl;
  }
  cout<<endl;
  return 0;
}