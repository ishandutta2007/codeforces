#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int main(){
  int T;
  cin>>T;
  while(T--){
    int a,b,c,d,e,f,g;
    cin>>a>>b>>c>>d>>e>>f>>g;
    cout<<a<<' '<<b<<' '<<g-a-b<<endl;
  }
  return 0;
}