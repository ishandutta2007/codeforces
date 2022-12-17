#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=1e5+10;
int n,A[maxn];

int main(){
  int T;cin>>T;while(T--){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",A+i);
    bool flg=1;
    rep(i,1,n){
      int j=i;
      while(j&&A[i]%(j+1)==0)j--;
      if(!j){
        flg=0;break;
      }
    }
    puts(flg?"YES":"NO");
  }
  return 0;
}