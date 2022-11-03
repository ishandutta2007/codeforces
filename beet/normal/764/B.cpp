#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin>>n;
  ll a[n];
  for(ll i=0;i<n;i++) cin>>a[i];
  for(ll i=0;i<n/2;i+=2) swap(a[i],a[n-1-i]);
  for(ll i=0;i<n;i++) cout<<a[i]<<" \n"[i==n-1];
  return 0;
}