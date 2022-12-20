#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int n,A[100010];

int main(){
  cin>>n;rep(i,1,n)scanf("%d",A+i);
  if(n>233)return puts("1"),0;
  int ans=1e9;
  rep(i,1,n)rep(l,1,i)rep(r,i+1,n){
    int x=0,y=0;
    rep(t,l,i)x^=A[t];
    rep(t,i+1,r)y^=A[t];
    if(x>y)ans=min(ans,r-l-1);
  }
  cout<<(ans>n?-1:ans)<<endl;
  return 0;
}