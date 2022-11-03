#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  string s;
  cin>>s;

  int v=0,h=0;
  for(char c:s){
    if(c=='0'){
      cout<<1<<' '<<v+1<<newl;
      v=(v+1)%4;
    }
    if(c=='1'){
      cout<<3<<' '<<h+1<<newl;
      h=(h+2)%4;
    }
  }

  return 0;
}