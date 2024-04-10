#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;

int n,k,A[30],vis[30];
ll pw[18];
ll check(ll mid){
  ll arr[30];memset(arr,0,sizeof arr);
  rep(i,1,n){
    arr[i]=i==n?mid/pw[A[i]]:mid%pw[A[i+1]]/pw[A[i]];
  }
  ll res=0;
  rep(i,1,n)res+=arr[i];
  ll su=0;
  bool flg=0;
  per(i,n,1){
    if(flg){
      su+=pw[A[i+1]-A[i]]-1;
      continue;
    }
    if(arr[i]){
      flg=1,su+=arr[i]-1;
    }
  }
  res=max(res,su);
  return res;
}

int main(){
  pw[0]=1;
  rep(i,1,17)pw[i]=10*pw[i-1];
  int T;cin>>T;while(T--){
    memset(vis,0,sizeof vis);
    scanf("%d%d",&n,&k);
    rep(i,1,n){
      scanf("%d",A+i),vis[A[i]]=1;
    }
    ll l=1,r=1e18;
    while(l<r){
      ll mid=(l+r)/2;
      check(mid)<=k?l=mid+1:r=mid;
    }
    printf("%lld\n",l);
  }
  return 0;
}