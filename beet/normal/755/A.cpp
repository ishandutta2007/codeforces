#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isprime(ll x){
  for(ll i=2;i*i<=x;i++) if(x%i==0) return 0;
  return 1;
}
int main(){
  ll n;
  cin>>n;
  for(ll i=1;i<=1000;i++){
    if(!isprime(n*i+1)){
      cout<<i<<endl;
      return 0;
    }
  }
  return 0;
}