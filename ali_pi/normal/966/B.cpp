#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>  

using namespace :: std;

const ll maxn=3e5+500;
const ll mod=1e9+7;
const ll inf=1e9+500;

pii c[maxn];
ll f[maxn];
pii s[maxn];


void prii(ll k,ll x){
 ll t=((k+c[x].F-1)/c[x].F);
 cout<<t<<' ';
}
void pri(ll k,ll x){
 ll t=((k+c[x].F-1)/c[x].F);
 for(ll i=x;i<x+t;i++){
  cout<<c[i].S+1<<' ';
 }
 cout<<endl;
}

int main(){
 ll n,k1,k2;
 cin>>n>>k1>>k2;
 for(ll i=0;i<n;i++){
  cin>>c[i].F;
  c[i].S=i;
 }
 sort(c,c+n);

 for(ll i=0;i<n;i++){
  f[i]=c[i].F*(n-i);
 }


 s[n-1]=mp(f[n-1],n-1);
 for(ll i=n-2;i>=0;i--){
  s[i]=max(s[i+1],mp(f[i],i));
 }
 for(ll i=0;i<n;i++){
  ll t=((k1+c[i].F-1)/c[i].F);
  if(i+t-1<n){
   if(s[i+t].F>=k2){
    cout<<"Yes\n";
    prii(k1,i);
    prii(k2,s[i+t].S);
    cout<<endl;
    pri(k1,i);
    pri(k2,s[i+t].S);

    return 0;
   }
  }

  t=((k2+c[i].F-1)/c[i].F);
  if(i+t-1<n){
   if(s[i+t].F>=k1){
    cout<<"Yes\n";
    prii(k1,s[i+t].S);
    prii(k2,i);
    
    cout<<endl;

    pri(k1,s[i+t].S);
    pri(k2,i);

    return 0;
   }
  }
 }
 cout<<"No";
}