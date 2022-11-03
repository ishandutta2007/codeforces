#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,i,j,k,x,sum=0,sum2=0;
  cin >> n >> k;
  ll d[n];
  bool c[n];
  for(i=0;i<n;i++){
    cin >> d[i];
    sum+=d[i];
    c[i]=false;
  }
  ll ans=0;
  for(i=0;i<k;i++){
    cin >> x;x--;c[x]=true;
  }
  for(i=0;i<n;i++){
    if(c[i]) {
      sum2+=d[i];
      if(c[(n+i-1)%n]) ans+=(sum-sum2)*d[i];
      else ans+=(sum-sum2-d[(n+i-1)%n])*d[i];
    }else{
      ans+=d[i]*d[(n+i+1)%n];
    }
    //cout << ans << endl;
  }

  cout << ans << endl;
  return 0;
}