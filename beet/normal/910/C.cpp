#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  Int n;
  cin>>n;
  vector<string> s(n);
  for(Int i=0;i<n;i++) cin>>s[i];
  vector<Int> t(10,0),d(10,0);
  for(Int i=0;i<n;i++){
    Int p=1;
    for(Int j=(Int)s[i].size()-1;j>=0;j--){
      d[s[i][j]-'a']+=p;
      p*=10;
    }
    t[s[i][0]-'a']++;
  }
  string x="abcdefghij";
  Int ans=1e9;
  do{
    if(t[x[0]-'a']) continue;
    Int res=0;
    for(Int i=0;i<10;i++) res+=d[x[i]-'a']*i;
    ans=min(ans,res);
  }while(next_permutation(x.begin(),x.end()));
  cout<<ans<<endl;
  return 0;
}