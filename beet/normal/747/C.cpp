#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,q;cin>>n>>q;
  ll s[n];
  memset(s,0,sizeof(s));
  for(ll i=0;i<q;i++){
    ll t,k,d,a=0,b;
    cin>>t>>k>>d;b=k;
    for(ll j=0;j<n;j++){
      if(!b) break;
      if(s[j]<=t){
	b--;
	a+=j+1;
      }
    }
    if(!b){
      for(ll j=0;j<n;j++){
	if(!k) break;
	if(s[j]<=t){
	  k--;
	  s[j]=t+d;
	}
      }
    }
    cout << (k?-1:a) << endl;
  }
  return 0;
}