#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n,m,z,ans=0;
  cin>>n>>m>>z;
  for(int i=n;i<=z;i+=n) ans+=!(i%m);
  cout<<ans<<endl;
  return 0;
}