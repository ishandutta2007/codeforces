#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=1e5+10;
int n,A[maxn];

bool pd(int x){
  rep(i,2,sqrt(x))if(x%i==0)return 0;
  return 1;
}

int main(){
  int T;cin>>T;while(T--){
    scanf("%d",&n);
    int su=0;
    rep(i,1,n)cin>>A[i],su+=A[i];
    if(!pd(su)){
      printf("%d\n",n);
      rep(i,1,n)printf("%d ",i);
      puts("");
      continue;
    }
    bool flg=0;
    rep(i,1,n){
      if(!pd(su-A[i])){

      printf("%d\n",n-1);
      rep(t,1,n)if(i!=t)printf("%d ",t);
      puts("");
        flg=1;break;
      }
    }
    if(!flg){
      rep(i,1,n)if(!flg)rep(j,i+1,n){
        if(!pd(su-A[i]-A[j])){

      printf("%d\n",n-2);
      rep(t,1,n)if(i!=t&&j!=t)printf("%d ",t);
      puts("");
      flg=1;break;
        }
      }
    }
    if(!flg){
      rep(i,1,n)if(!flg)rep(j,i+1,n)if(!flg)rep(k,j+1,n){
        if(!pd(A[i]+A[j]+A[k])){
      printf("%d\n",n-3);
      rep(t,1,n)if(i!=t&&j!=t&&k!=t)printf("%d ",t);
      puts("");
          flg=1;break;
        }
      }
    }
  }
  return 0;
}