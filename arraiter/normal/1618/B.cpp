#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

char str[105];
string A[105];

int main(){
  int T;
  cin>>T;
  while(T--){
    int n;
    cin>>n;
    rep(i,1,n-2){
      cin>>A[i];
    }
    if(n==3){
      cout<<A[1];
      putchar('a');
      puts("");
      continue;
    }
    rep(i,1,n-3){
      if(A[i][1]!=A[i+1][0]||i==n-3){
        rep(j,1,i)putchar(A[j][0]);
        putchar(A[i][1]);
        putchar(A[i+1][0]);
        rep(j,i+1,n-2)putchar(A[j][1]);
        puts("");
        break;
      }
    }
  }
  return 0;
}