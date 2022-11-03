#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll a,b,c,m;
  cin>>a>>b>>c>>m;
  vector<ll> v[2];
  for(ll i=0;i<m;i++){
    ll val;
    string s;
    cin>>val>>s;
    v[(s=="USB")].push_back(val);
  }
  ll n=0,ans=0;
  sort(v[0].rbegin(),v[0].rend());
  sort(v[1].rbegin(),v[1].rend());
  while(a&&!v[1].empty()){
    a--;
    ans+=v[1][v[1].size()-1];
    v[1].pop_back();
    n++;
  }
  while(b&&!v[0].empty()){
    b--;
    ans+=v[0][v[0].size()-1];
    v[0].pop_back();
    n++;
  }
  for(ll i=0;i<(ll)v[1].size();i++) v[0].push_back(v[1][i]);
  sort(v[0].rbegin(),v[0].rend());
  while(c&&!v[0].empty()){
    c--;
    ans+=v[0][v[0].size()-1];
    v[0].pop_back();
    n++;
  }
  cout<<n<<" "<<ans<<endl;
  return 0;
}