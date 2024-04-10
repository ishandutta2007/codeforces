#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  cin.tie(0);
  int n;
  cin>>n;
  string s[n];
  for(int i=0;i<n;i++) cin>>s[i];
  int l[n];
  l[n-1]=s[n-1].length();
  for(int i=n-1;i>0;i--){
    l[i-1]=1;
    if(l[i]==1) continue;
    int a=s[i-1].length();
    for(int j=1;j<min(l[i],a);j++){
      if(s[i-1][j]<s[i][j]){
	l[i-1]=a;
	break;
      }
      if(s[i-1][j]>s[i][j]) break;
      l[i-1]=j+1;
    }
  }
  
  for(int i=0;i<n;i++){
    for(int j=0;j<l[i];j++) cout<<s[i][j];
    cout<<endl;
  }
  return 0;
}