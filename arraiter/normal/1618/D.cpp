#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int n,k,A[105];

int main(){
  int T;
  cin>>T;
  while(T--){
    cin>>n>>k;
    rep(i,1,n)cin>>A[i];
    sort(A+1,A+n+1);
    int ans=0;
    rep(i,1,k)ans+=A[n-k-i+1]/A[n-i+1];
    rep(i,1,n-k*2)ans+=A[i];
    cout<<ans<<endl;
  }
  return 0;
}