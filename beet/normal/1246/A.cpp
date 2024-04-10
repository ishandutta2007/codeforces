#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  Int n,p;
  cin>>n>>p;

  const Int MAX = 5050;
  for(Int i=1;i<MAX;i++){
    Int sum=n-p*i;
    if(sum<i) continue;
    if(__builtin_popcountll(sum)>i) continue;
    cout<<i<<endl;
    return 0;
  }
  cout<<-1<<endl;
  return 0;
}