#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;

int main(){
  int T;cin>>T;while(T--){
    ll x;
    cin>>x;
    int n=0,A[20];
    while(x)A[++n]=x%10,x/=10;
    if(!n){
      puts("0");continue;
    }
    int ans=99;
    rep(i,1,n)rep(j,i+1,n){
      bool flg=0;
      flg|=A[i]==0&&A[j]==0;
      flg|=A[i]==5&&A[j]==2;
      flg|=A[i]==0&&A[j]==5;
      flg|=A[i]==5&&A[j]==7;
      if(flg)ans=min(ans,i-1+(j-i-1));
    }
    cout<<ans<<endl;
  }
  return 0;
}