#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000003;
ll mod_pow(ll x,ll n){
  ll res=1;
  while(n>0){
    if(n&1) res=res*x%MOD;
    x=x*x%MOD;
    n>>=1;
  }
  return res%MOD;
}
int main(){
  ll n,k,a=1,b=1,c=0;;
  cin>>n>>k;
  if(n<=60&&(1LL<<n)<k){
    a=1;b=1;
  }else{
    b=mod_pow(2,n);
    if(k>=MOD) a=0;
    else{
      for(ll i=1;i<k;i++){
	a*=(b-i)%MOD;
	a%=MOD;
      }
    }
    for(ll i=2;i<k;i*=2) c+=(k-1)/i;
    //cout << a << endl << b << endl << c << endl;
    b=mod_pow(b,k-1);
    c=mod_pow(mod_pow(2,MOD-2),c)%MOD;
    a=(a*c)%MOD;
    b=(b*c)%MOD;
    a=(b-a+MOD)%MOD;
  }
  cout << a << " " << b << endl;
      
  return 0;
}