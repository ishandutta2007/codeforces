#include<bits/stdc++.h>
using namespace std;
using Int = long long;

#define MOD 1000000007
#define MAX_P 200005
Int fact[MAX_P],inv[MAX_P],finv[MAX_P];

Int mod_pow(Int x,Int n,Int mod){
  Int res=1;
  while(n){
    if(n&1) (res*=x)%=mod;
    (x*=x)%=mod;
    n>>=1;
  }
  return res;
}

void init(Int mod){
  fact[0]=1;
  for(Int i=1;i<MAX_P;i++)
    fact[i]=(fact[i-1]*i)%mod;

  inv[1]=1;
  for(Int i=2;i<MAX_P;i++)
    inv[i]=inv[mod%i]*(mod-mod/i)%mod;
  
  finv[0]=1;
  for(Int i=1;i<MAX_P;i++)
    finv[i]=finv[i-1]*inv[i]%mod;
}

//only for prime mod
Int mod_comb3(Int n,Int k,Int mod){
  if(k<0||k>n) return 0;
  return fact[n]*finv[k]%mod*finv[n-k]%mod;
}

//INSERT ABOVE HERE
signed main(){

  init(MOD);
  auto calc=[&](Int n,Int k){
    Int res=0;
    for(Int i=0;i<=n;i++){
      res+=mod_comb3(n,i,MOD)*mod_pow(i,k,MOD)%MOD;
      res%=MOD;
    }
    return res;
  };

  auto calc2=[&](Int n,Int k){
    if(k>=n) return calc(n,k);
    vector<Int> dp(k+1,0);
    dp[0]=1;
    for(Int i=0;i<k-1;i++){
      for(Int j=i;j>=0;j--){
	dp[j+1]+=dp[j]*(i+1-j)%MOD;
	dp[j+1]%=MOD;
      }
    }
    Int res=0;
    int mul=1;
    for(Int i=1;i<=k;i++){
      mul=mul*(n-i+1)%MOD;
      Int tmp=mul%MOD*mod_pow(2,n-i,MOD)%MOD;
      tmp=tmp*dp[k-i]%MOD;
      res=(res+tmp)%MOD;
    }
    return res;
  };

  if(0){
    for(Int i=1;i<1000;i++){
      for(Int j=1;j<1000;j++){
	//calc2(i,j);cout<<endl;
	//cout<<calc(i,j)<<" "<<calc2(i,j)<<endl;;
	assert(calc(i,j)==calc2(i,j));
      }
      cout<<i<<endl;
      //cout<<endl;
    }
  }
  
  Int n,k;
  cin>>n>>k;
  cout<<calc2(n,k)<<endl;
  return 0;
}