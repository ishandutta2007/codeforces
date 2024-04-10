#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int main(){
  int T;cin>>T;while(T--){
    int a,b;
    scanf("%d%d",&a,&b);
    if(a%2!=b%2){
      puts("-1");continue;
    }
    if(!a&&!b){
      puts("0");continue;
    }
    if(a==b){
      puts("1");continue;
    }
    puts("2");
  }
  return 0;
}