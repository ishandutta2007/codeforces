#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  ll n,d,b;
  cin>>n>>d>>b;

  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  // x kai made miss OK
  auto check=[&](ll x)->int{
    vector<ll> bs(as);
    ll pos=0,cur=0,sum=0,cnt=0;
    for(int i=0;i<(n+1)/2;i++){
      if(cnt+x==(n+1)/2) break;
      while(pos<=i+d*(i+1) and pos<n){
        sum+=as[pos];
        pos++;
      }
      if(sum<b) continue;
      ll res=b;
      while(res){
        ll dif=min(bs[cur],res);
        bs[cur]-=dif;
        res-=dif;
        if(bs[cur]==0) cur++;
      }
      sum-=b;
      cnt++;
    }
    if(0){
      cerr<<"X:"<<x<<endl;
      cerr<<cnt+x<<endl;
      for(ll b:bs) cerr<<b<<' ';
      cerr<<endl;
    }
    if(cnt+x!=(n+1)/2) return 0;

    vector<ll> sm(n+1,0);
    for(int i=0;i<n;i++) sm[i+1]=sm[i]+bs[i];

    ll uku=0;
    for(int i=0;i<n/2;i++){
      ll l=(n-(i+1))-d*(i+1);
      if(l<0) l=0;
      // cerr<<i<<' '<<l<<':'<<sm[n]-sm[l]<<endl;
      if(sm[n]-sm[l]-uku*b>=b) uku++;
    }
    // cerr<<uku<<' '<<x<<' '<<n/2<<endl;
    return uku+x>=n/2;
  };

  ll L=-1,R=n/2;
  // check(L): false
  // check(R): true
  while(L+1<R){
    ll M=(L+R)>>1;
    if(check(M)) R=M;
    else L=M;
  }
  cout<<R<<newl;
  return 0;
}