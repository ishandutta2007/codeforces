#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,t[2];
vector<ll> v;
priority_queue<ll,vector<ll>,greater<ll> > q;
int main(){
  cin>>n>>k;
  v.resize(n);
  for(ll i=0;i<n;i++){
    cin>>v[i];
    if(v[i]<0) t[0]++;
    else t[1]++;
  }
  ll l;
  for(ll i=0;i<n;i++){
    if(v[i]>=0) continue;
    ll j=1;
    while(i+j<(ll)v.size()&&v[i+j]>=0) j++;
    if(i+j<(ll)v.size()) q.push(j-1);
    else l=j-1;
    i+=j-1;
  }
  ll ans=t[0]*2,y=k-t[0];
  while(!q.empty()){
    ll j=q.top();q.pop();
    if(j<=y){
      y-=j;
      ans-=2;
    }else break;
  }
  if(l<=y) ans--;
  if(t[0]==0) ans=0;
  cout<<(y<0?-1:ans)<<endl;
  return 0;
}