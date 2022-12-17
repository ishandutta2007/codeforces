#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=1e6+10;
int n,len,A[maxn];

int main(){
  ios::sync_with_stdio(0);
  int T;cin>>T;while(T--){
    cin>>len>>n;
    rep(i,1,n)cin>>A[i];
    sort(A+1,A+n+1);
    int ans=0;
    long long cur=0;
    per(i,n,1){
      cur+=len-A[i];
      if(cur==len-1){
        ans=n-i+1;break;
      }else if(cur>=len){
        break;
      }
      ans=n-i+1;
    }
    cout<<ans<<endl;
  }
  return 0;
}