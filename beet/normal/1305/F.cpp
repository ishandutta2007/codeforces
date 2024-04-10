#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

using ll = long long;

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

template<typename T>
ll isprime(T x){
  if(x<=1) return 0;
  for(T i=2;i*i<=x;i++)
    if(x%i==0) return 0;
  return 1;
}

//INSERT ABOVE HERE

const ll MAX = 2e5+100;
ll as[MAX];

ll n;

set<ll> used;
ll check(ll p,ll ans){
  if(used.count(p)) return ans;
  used.emplace(p);

  ll res=0;
  for(ll i=0;i<n;i++){
    if(as[i]<=p){
      res+=p-as[i];
    }else{
      ll x=as[i]%p;
      res+=min(x,p-x);
    }
    if(res>=ans) break;
  }
  return res;
}

signed main(){
  cin>>n;

  for(ll i=0;i<n;i++) cin>>as[i];
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  shuffle(as,as+n,rng);

  ll ans=n;
  for(ll p=2;p<=1000;p++)
    if(isprime(p)) chmin(ans,check(p,ans));

  const ll LIM = min(n, 40LL);
  for(ll i=0;i<LIM;i++){
    for(ll d=-1;d<=1;d++){
      ll t=as[i]+d;
      if(t==0) continue;
      for(ll x=2;x*x<=t;x++){
        if(t%x) continue;
        chmin(ans,check(x,ans));
        while(t%x==0) t/=x;
      }
      if(t>1) chmin(ans,check(t,ans));
    }
  }

  cout<<ans<<endl;
  return 0;
}