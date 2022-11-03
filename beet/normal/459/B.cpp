#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> bs(n);
  for(Int i=0;i<n;i++) cin>>bs[i];
  map<Int, Int> cnt;
  for(Int b:bs) cnt[b]++;
  if(cnt.size()==1){
    cout<<0<<" ";
    drop(n*(n-1)/2);
  }
  cout<<cnt.rbegin()->first-cnt.begin()->first<<" ";
  cout<<cnt.rbegin()->second*cnt.begin()->second<<endl;
  return 0;
}