#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int n,A[50];

int main(){
  int T;cin>>T;while(T--){
    cin>>n;
    rep(i,1,n)cin>>A[i];
    sort(A+1,A+n+1);
    per(i,n,1)A[i]-=A[1];
    int ans=0;
    per(i,n,1)ans=__gcd(ans,A[i]);
    cout<<(ans?ans:-1)<<endl;
  }
  return 0;
}