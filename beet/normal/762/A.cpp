#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,k;
  cin>>n>>k;
  vector<ll> v;
  for(ll i=1;i*i<=n;i++){
    if(n%i) continue;
    v.push_back(i);
    v.push_back(n/i);
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  if((ll)v.size()<k) cout<<-1<<endl;
  else cout<<v[k-1]<<endl;
  return 0;
}