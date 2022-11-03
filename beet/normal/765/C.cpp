#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll k,a,b,ans=0;
  cin>>k>>a>>b;
  ans+=a/k;
  ans+=b/k;
  if(a>k*ans||b>k*ans) cout<<-1<<endl;
  else cout<<ans<<endl;
  return 0;
}