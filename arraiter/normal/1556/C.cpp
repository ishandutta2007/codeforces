#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

#define int long long

int n,A[1010];

signed main(){
  cin>>n;
  rep(i,1,n)cin>>A[i];
  long long ans=0;
  rep(i,1,n)if(i%2==1){
    int tp=A[i],cur=0;
    rep(j,i+1,n){
//      if(i==1){
//        printf("(%d) : %d %d %lld\n",j,tp,cur,ans);
//      }
      int x=A[j];
      if(cur<=x){
        if(cur)x-=cur,cur=0;
        ans+=min(tp,x)+(j!=i+1);
        if(tp<x){
          break;
        }
        tp-=x;
      }else{
        cur-=x;
      }
      if(++j<=n){
        cur+=A[j];
      }
    }
//    printf("%d : %lld\n",i,ans);
  }
  cout<<ans<<endl;
  return 0;
}