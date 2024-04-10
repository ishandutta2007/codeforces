#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  int n;
  cin>>n;
  vector<int> ans;
  for(int i=0;i<min(1000000,n);i++){
    string s=to_string(n-i);
    int k=n-i;
    for(int j=0;j<(int)s.size();j++) k+=s[j]-'0';
    //cout<<i<<" "<<k<<endl;
    if(k==n) ans.push_back(n-i);
  }
  cout<<ans.size()<<endl;
  sort(ans.begin(),ans.end());
  for(int u:ans) cout<<u<<endl;
  return 0;
}