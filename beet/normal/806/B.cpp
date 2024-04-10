#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int n;
  cin>>n;
  vector<array<Int, 5>> as(n);
  array<Int, 5> cnt;
  fill(cnt.begin(),cnt.end(),0);
  for(Int i=0;i<n;i++){
    for(Int j=0;j<5;j++){
      cin>>as[i][j];
      if(as[i][j]<0) as[i][j]=250;
      else cnt[j]++;
    }
  }

  auto point=[&](Int x,Int y){
    if(x<=y/32) return 12;
    if(x<=y/16) return 10;
    if(x<=y/8) return 8;
    if(x<=y/4) return 6;
    if(x<=y/2) return 4;
    if(x<=y/1) return 2;
    abort();
  };

  const Int MAX = 150 * 40;
  for(Int add=0;add<=MAX;add++){
    Int dif=0;
    for(Int j=0;j<5;j++){
      Int x=as[0][j];
      Int y=as[1][j];
      if(x<=y or x==250){
        dif+=point(cnt[j],n+add)*(y-x);
      }else{
        dif+=point(cnt[j]+add,n+add)*(y-x);
      }
    }
    // cout<<add<<':'<<dif<<endl;
    if(dif>0) drop(add);
  }

  drop(-1);
  return 0;
}