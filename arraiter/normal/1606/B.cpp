#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
typedef long long ll;

int main(){
  int T;cin>>T;while(T--){
    ll n,k;
    scanf("%lld%lld",&n,&k);
    ll cur=1;
    ll tim=0;
    while(cur<n&&cur<k){
      cur+=min(cur,k),tim++;
    }
    if(cur<n){
      tim+=(n-cur+k-1)/k;
    }
    printf("%lld\n",tim);
  }
  return 0;
}