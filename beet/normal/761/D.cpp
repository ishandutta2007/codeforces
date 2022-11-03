#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(){
  ll n,l,r;
  cin>>n>>l>>r;
  vector<ll> a(n),b(n),p(n);
  vector<P> c(n);
  for(ll i=0;i<n;i++) cin>>a[i];
  for(ll i=0;i<n;i++) cin>>p[i];
  for(ll i=0;i<n;i++){
    c[i].first=p[i];
    c[i].second=i;
  }
  sort(c.rbegin(),c.rend());
  ll m=r;
  for(ll i=0;i<n;i++){
    ll v=c[i].second;
    if(m<l){
      cout<<-1<<endl;
      return 0;
    }
    b[v]=m;
    if(i<n-1){
      ll u=c[i+1].second;
      m=min(r+1,m-a[v]+a[u])-1;
    }
  }
  //for(ll i=0;i<n;i++) cout<<b[i]-a[i]<<" \n"[i==n-1];
  for(ll i=0;i<n;i++) cout<<b[i]<<" \n"[i==n-1];
  return 0;
}