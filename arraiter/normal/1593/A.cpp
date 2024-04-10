#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

#define int long long

signed main(){
  int T;cin>>T;while(T--){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max(0ll,max(b,c)+1-a)<<' '<<max(0ll,max(a,c)+1-b)<<' '<<max(0ll,max(a,b)+1-c)<<endl;
  }
  return 0;
}