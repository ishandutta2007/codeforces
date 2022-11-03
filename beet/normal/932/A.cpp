#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  string s;
  cin>>s;
  string t=s;
  reverse(t.begin(),t.end());
  cout<<s+t<<endl;
  return 0;
}