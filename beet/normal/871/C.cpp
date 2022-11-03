#include<bits/stdc++.h>
using namespace std;
using Int = long long;

#define MOD 1000000007
#define MAX_N 100000
#define MAX_P 200005
Int fact[MAX_P];
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
Int mod_inverse(Int a,Int m){
  Int x,y;
  extgcd(a,m,x,y);
  return (m+x%m)%m;
}
Int euler_phi(Int n){
  Int res=n;
  for(Int i=2;i*i<=n;i++){
    if(n%i==0){
      res=res/i*(i-1);
      for(;n%i==0;n/=i);
    }
  }
  if(n!=1) res=res/n*(n-1);
  return res;
}

Int euler[MAX_N];

void euler_phi2(){
  for(Int i=0;i<MAX_N;i++) euler[i]=i;
  for(Int i=2;i<MAX_N;i++){
    if(euler[i]==i){
      for(Int j=i;j<MAX_N;j+=i) euler[j]=euler[j]/i*(i-1);
    }
  }
}

Int mod_pow(Int x,Int n,Int mod){
  Int res=1;
  while(n>0){
    if(n&1) (res*=x)%=mod;
    (x*=x)%=mod;
    n>>=1;
  }
  return res;
}

Int mod_inverse2(Int a,Int mod){
  return mod_pow(a,mod-2,mod);
}

void init(Int p){
  fact[0]=1;
  for(Int i=1;i<MAX_P;i++) fact[i]=(fact[i-1]*i)%p;
}

Int mod_fact(Int n,Int p,Int& e){
  e=0;
  if(n==0) return 1;
  Int res=mod_fact(n/p,p,e);
  e+=n/p;
  if(n/p%2!=0)return res*(p-fact[n%p]) %p;
  return res*fact[n%p]%p;
} 
Int mod_comb(Int n,Int k,Int p){
  if(n==k||k==0) return 1;
  Int e1,e2,e3;
  Int a1=mod_fact(n,p,e1),a2=mod_fact(k,p,e2),a3=mod_fact(n-k,p,e3);
  if(e1>e2+e3) return 0;
  return a1*mod_inverse(a2*a3%p,p)%p;
}

Int mod_comb2(Int n,Int k,Int mod){
  Int res=1;
  for(Int i=0;i<k;i++){
    res*=n-i;
    res%=mod;
    res*=mod_inverse(i+1,mod);
    res%=mod;
  }
  return res;
}

Int montmort(Int n,Int mod){
  Int res=0,inv=1;
  for(Int k=2;k<=n;k++){
    (inv*=mod_inverse(k,mod))%=mod;
    if(k%2 ) (res+=mod-inv)%=mod;
    else (res+=inv)%=mod;
  }
  for(Int i=1;i<=n;i++)
    (res*=i)%=mod;
  return res;
}



signed main(){
  Int n;
  cin>>n;
  Int x[n],y[n];
  vector<Int>vx(n),vy(n);
  for(Int i=0;i<n;i++){
    cin>>x[i]>>y[i];
    vx[i]=x[i];vy[i]=y[i];
  }
  sort(vx.begin(),vx.end());
  vx.erase(unique(vx.begin(),vx.end()),vx.end());
  sort(vy.begin(),vy.end());
  vy.erase(unique(vy.begin(),vy.end()),vy.end());
  Int sx=vx.size(),sy=vy.size();
  map<Int,Int> mx,my;
  for(Int i=0;i<sx;i++) mx[vx[i]]=i;
  for(Int i=0;i<sy;i++) my[vy[i]]=i;
  vector<vector<Int>> G(sx+sy);
  for(Int i=0;i<n;i++){
    Int a=mx[x[i]],b=sx+my[y[i]];
    //cout<<a<<" "<<b<<endl;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  Int ans=1;
  vector<Int> used(sx+sy,0);
  Int cv,ce;
  function<void(Int)> dfs=[&](Int v){
    if(used[v]) return;
    used[v]=1;
    cv++;
    for(Int u:G[v]) ce++,dfs(u);
  };
  for(Int i=0;i<sx+sy;i++){
    if(used[i]) continue;
    cv=ce=0;
    dfs(i);
    assert(ce%2==0);
    ce/=2;
    ans*=(mod_pow(2,cv,MOD)+MOD-(cv==ce+1))%MOD;
    ans%=MOD;
  }
  cout<<ans<<endl;
  return 0;
}