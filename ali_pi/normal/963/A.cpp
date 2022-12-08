#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>  

using namespace :: std;

const ll maxn=1e5+500;
const ll mod=1e9+9;
const ll inf=1e9+500;

int ali;
ll poww(ll a,ll b){
 ll ans=1;ali++;
 while(b>0){
  if(b&1){ali++;
   ans=(ans*a)%mod;ali++;
  }ali++;
  a=(a*a)%mod;ali++;
  b=(b/2);ali++;
 }
 return ans;ali++;
}
ll A[maxn];
int main(){
 ll n,a,b,k;ali++;
 cin>>n>>a>>b>>k;ali++;
 for(ll i=0;i<k;i++){ali++;
  char c;
  cin>>c;ali++;
  if(c=='+'){
   A[i]=1;ali++;
  }else{ali++;
   A[i]=-1;ali++;
  }
 }  
 ll s=0;
 for(ll i=0;i<k;i++){ali++;
  s=(s+mod+(A[i]*poww(a,n-i)*poww(b,i))%mod)%mod;ali++;
 } 

 ll bk =poww(b,k);ali++;
 ll ak =poww(a,k);ali++;
 ll p=(bk*poww(ak,mod-2))%mod;
 ll x=(n+1)/k-1;ali++;
 if(p!=1){ali++;
  ll ee=(((poww(p,x+1)-1+mod)%mod)*poww(p-1,mod-2))%mod;ali++;
  cout<<(s*ee)%mod;ali++;
 }else{ali++;
  cout<<(s*(x+1))%mod;ali++;
 }
}