#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int maxn=1e5+10;
int n,A[maxn],B[maxn];

ll solve(){
  static int p1[maxn],p2[maxn];
  int now=0;
  rep(i,1,n){
    if(A[i]==1)p1[++now]=i;
  }
  now=0;
  rep(i,1,n){
    if(B[i]==1)p2[++now]=i;
  }
  ll ans=0;
  rep(i,1,now)ans+=abs(p1[i]-p2[i]);
  return ans;
}

int main(){
  int T;cin>>T;while(T--){
    scanf("%d",&n);
    int ct[2]={0,0};
    rep(i,1,n)scanf("%d",A+i),A[i]&=1,ct[A[i]]++;
    if(abs(ct[0]-ct[1])>1){
      puts("-1");continue;
    }
    ll ans=1e18;
    if(ct[0]>=ct[1]){
      rep(i,1,n)B[i]=(i-1)%2;
      ans=solve();
    }
    if(ct[1]>=ct[0]){
      rep(i,1,n)B[i]=i%2;
      ans=min(ans,solve());
    }
    printf("%lld\n",ans);
  }
  return 0;
}