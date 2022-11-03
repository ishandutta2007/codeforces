#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n;
  string s;
  cin>>n>>s;
  vector<Int> c(26,0);
  for(Int i=0;i<n;i++){
    c[s[i]-'a']++;
  }

  Int ans=n==1;
  for(Int i=0;i<26;i++)
    ans|=c[i]>=2;
  
  cout<<(ans?"Yes":"No")<<endl;
  return 0;
}