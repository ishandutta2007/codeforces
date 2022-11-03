#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string s;
  cin>>s;
  int n=s.length();
  int p[4],a[4]={};
  for(int i=0;i<n;i++){
    if(s[i]=='R') p[0]=i%4;
    if(s[i]=='B') p[1]=i%4;
    if(s[i]=='Y') p[2]=i%4;
    if(s[i]=='G') p[3]=i%4;
  }
  for(int i=0;i<n;i++){
    if(s[i]=='!') a[i%4]++;
  }
  cout<<a[p[0]]<<" "<<a[p[1]]<<" "<<a[p[2]]<<" "<<a[p[3]]<<endl;
  return 0;
}