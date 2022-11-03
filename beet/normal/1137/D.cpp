#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  auto ask=
    [&](vector<int> v){
      cout<<"next";
      for(int x:v) cout<<" "<<x;
      cout<<endl;
      int cnt;
      cin>>cnt;
      string s;
      for(int i=0;i<cnt;i++) cin>>s;
      return cnt;
    };

  vector<int> v1({0,1});
  vector<int> v2({0});
  vector<int> v3({0,1,2,3,4,5,6,7,8,9});

  ask(v1);
  while(1){
    int x=ask(v2);
    if(x==2) break;
    int y=ask(v1);
    if(y==2) break;
  }
  while(1){
    int x=ask(v3);
    if(x==1){
      cout<<"done"<<endl;
      break;
    }
  }  
  return 0;
}