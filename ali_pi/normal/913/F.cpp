#include<bits/stdc++.h>

#define ll long long
#define mod 998244353

using namespace std;

ll K(ll x,int y=mod-2){
  ll t=1;
  for (;y;y>>=1,x=x*x%mod) if (y&1) t=t*x%mod;
  return t;
}
ll n,x,y,p,np,f[2020][2020],g[2020],h[2020];

void U(ll &x,ll y){
  x=(x+y)%mod;
}

int main(){
  cin>>n>>x>>y; 
  p=x*K(y)%mod;
  np=(mod+1-p)%mod;
  f[1][0]=f[1][1]=1;
  for (int i=1;i<=n;++i){
    for (int j=0;j<=i;++j){
      U(f[i+1][j],f[i][j]*K(p,j));
      U(f[i+1][j+1],f[i][j]*K(np,i-j));
    }
  }
  for (int i=1;i<=n;++i){
    g[i]=1;
    for (int j=1;j<i;++j)
      U(g[i],mod-f[i][j]*g[j]%mod);
  }
  for (int i=2;i<=n;++i){
    for (int j=1;j<i;++j)
      U(h[i],f[i][j] *g[j]%mod *( j*(j-1)/2+j*(i-j)+h[j]+h[i-j] )%mod);
    h[i]=(h[i]+ g[i]*i*(i-1)/2)%mod *K(mod+1-g[i])%mod;
  }
  cout<<h[n]<<endl;
}