#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n;
  cin>>n;
  int c[n],ans=0;
  memset(c,0,sizeof(c));
  for(int i=0;i<n;i++){
    c[i]++;
    ans=max(ans,c[i]);
    if(c[i]==1) for(int j=i;j<n;j+=i+2) c[j]=max(c[j],c[i]);
  }
  cout<<ans<<endl;
  for(int i=0;i<n;i++) cout<<c[i]<<" \n"[i==n-1];
  return 0;
}