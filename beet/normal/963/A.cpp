#include<bits/stdc++.h>
using namespace std;
using Int = long long;

#define MOD 1000000009

Int extgcd(Int a,Int b,Int& x,Int& y){
  Int d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}

Int mod_inverse(Int a,Int mod){
  Int x,y;
  extgcd(a,mod,x,y);
  return (mod+x%mod)%mod;
}

Int mod_pow(Int x,Int n,Int mod){
  Int res=1;
  while(n){
    if(n&1) (res*=x)%=mod;
    (x*=x)%=mod;
    n>>=1;
  }
  return res;
}


//INSERT ABOVE HERE
signed main(){
  Int n,a,b,k;
  cin>>n>>a>>b>>k;
  string s;
  cin>>s;
  Int x=0;
  Int v=mod_pow(a,n,MOD);
  Int ia=mod_inverse(a,MOD);
  for(Int i=0;i<k;i++){
    if(s[i]=='+') x+=v;
    else x+=MOD-v;
    x%=MOD;
    v=v*b%MOD;
    v=v*ia%MOD;
  }
  Int p=(n+1)/k;
  Int y=mod_pow(ia,k,MOD)*mod_pow(b,k,MOD)%MOD;
  if(y==1){
    x=x*p%MOD;
    cout<<x<<endl;
    return 0;
  }
  Int z=(mod_pow(y,p,MOD)+MOD-1)%MOD;
  z=z*mod_inverse(y-1,MOD)%MOD;
  x=x*z%MOD;
  cout<<x<<endl;
  return 0;
}