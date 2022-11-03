#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string s;
  cin>>s;
  int n=s.length();
  int t=0;
  for(int i=0;i<n/2;i++) t+=s[i]!=s[n-1-i];
  if(n%2){
    if(t<=1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }else{
    if(t==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl; 
  }
  return 0;
}