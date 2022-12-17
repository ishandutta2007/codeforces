#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int maxn=4e4+10;
ll n,A[maxn],B[maxn];

int main(){
  ios::sync_with_stdio(0);
  int T;
  cin>>T;
  while(T--){
    cin>>n;
    ll su=0;
    rep(i,1,n)cin>>B[i],su+=B[i];
    if(n==1){
      cout<<"YES"<<endl;
      cout<<B[1]<<endl;
      continue;
    }
    ll tp=1ll*n*(n+1)/2;
    if(su%tp!=0){
      cout<<"NO"<<endl;
      continue;
    }
    su/=tp;
    bool flg=1;
    rep(i,1,n){
      A[i]=-(-B[i>1?i-1:n]+B[i]-su);
      flg&=A[i]%n==0;
      A[i]/=n;
      flg&=A[i]>0;
    }
    if(!flg){
      cout<<"NO"<<endl;
      continue;
    }
    cout<<"YES"<<endl;
    rep(i,1,n)cout<<A[i]<<' ';
    cout<<endl;
  }
  return 0;
}