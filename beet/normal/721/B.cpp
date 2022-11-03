#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,j,k,mi,ma;cin>>n>>k;
  int l[200]={};
  string s[n],ans;
  for(i=0;i<n;i++) cin>>s[i],l[s[i].size()]++;
  cin>>ans;
  j=0;
  for(i=1;i<ans.size();i++) j+=l[i];
  mi=j+1;ma=j;
  mi+=(mi-1)/k*5;
  ma+=l[ans.size()];
  ma+=(ma-1)/k*5;
  cout << mi << " " << ma << endl;
  return 0;
}