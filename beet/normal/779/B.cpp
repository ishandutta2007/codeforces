#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string s;
  int k;
  cin>>s>>k;
  reverse(s.begin(),s.end());
  int t=0,ans=0;
  for(int i=0;i<(int)s.size();i++){
    ans+=s[i]!='0';
    t+=s[i]=='0';
    if(t==k) break;
  }
  if(t<k) cout<<s.size()-1<<endl;
  else cout<<ans<<endl;
  return 0;
}