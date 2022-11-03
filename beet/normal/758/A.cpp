#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n;
  cin>>n;
  int a[n],m=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    m=max(m,a[i]);
  }
  int ans=0;
  for(int i=0;i<n;i++) ans+=m-a[i];
  cout<<ans<<endl;
  return 0;
}