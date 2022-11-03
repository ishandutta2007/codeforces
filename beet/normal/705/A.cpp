#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  string s[]={"I hate ","I love "};
  string ans="";
  for(int i=0;i<n;i++){
    ans+=s[i%2]+(i==n-1?"it":"that ");
  }
  cout << ans << endl;
  return 0;
}