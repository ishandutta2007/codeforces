#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;cin>>n;
  ll a=1,b=n;
  for(ll i=1;i*i<=n;i++){
    if(n%i) continue;
    if(abs(i-n/i)<abs(b-a)) a=i,b=n/i;
  }
  cout << a << " " << b << endl;
  return 0;
}