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
const ll mod=1e9+7;
const ll inf=1e9+500;

set<ll>  e;
set<ll> l;
set<ll> :: iterator it;

int main(){
 ll n,m,cl,ce,v;
 cin>>n>>m>>cl>>ce>>v;
 for(ll i=0;i<cl;i++){
  ll x;
  cin>>x;
  l.insert(x);
 }
 for(ll i=0;i<ce;i++){
  ll x;
  cin>>x;
  e.insert(x);
 }
 ll q;
 cin>>q;
 while(q--){
  ll x,y,xx,yy;
  cin>>x>>y>>xx>>yy;
  if(x==xx){
   cout<<abs(y-yy)<<endl;
  }else{
   ll ans=inf;
   ll res=0;
   it=l.lower_bound(y);
   if(it!=l.end()){
    ll u=(*it);
    res=abs(u-y)+abs(u-yy)+(abs(x-xx));
    ans=min(ans,res);
   }
   if(it!=l.begin()){
    it--;
    ll u=(*it);
    res=abs(u-y)+abs(u-yy)+(abs(x-xx));
    ans=min(ans,res);
   }
   it=e.lower_bound(y);
   if(it!=e.end()){
    ll u=(*it);
    res=abs(u-y)+abs(u-yy)+(abs(x-xx)+v-1)/v;
    ans=min(ans,res);
   }
   if(it!=e.begin()){
    it--;
    ll u=(*it);
    res=abs(u-y)+abs(u-yy)+(abs(x-xx)+v-1)/v;
    ans=min(ans,res);
   }
   cout<<ans<<endl;
  }
 }
}