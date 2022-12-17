#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

long long A[105],n;

bool check(long long d){
  rep(i,2,n){
    if((A[i]%d==0)==(A[i-1]%d==0)){
      return 0;
    }
  }
  return 1;
}

int main(){
  int T;
  cin>>T;
  while(T--){
    cin>>n;
    rep(i,1,n)cin>>A[i];
    bool flg=0;
    {
      long long d=0;
      for(int i=1;i<=n;i+=2)d=__gcd(d,A[i]);
      if(check(d)){
        cout<<d<<endl;
        flg=1;
      }
    }
    if(!flg){
      long long d=0;
      for(int i=2;i<=n;i+=2)d=__gcd(d,A[i]);
      if(check(d)){
        cout<<d<<endl;
        flg=1;
      }
    }
    if(!flg){
      puts("0");
    }
  }
  return 0;
}