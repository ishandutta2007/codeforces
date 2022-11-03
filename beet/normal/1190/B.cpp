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
  vector<Int> as(n);
  for(Int i=0;i<n;i++) cin>>as[i];

  map<Int, Int> cnt;
  for(Int a:as) cnt[a]++;
  if(cnt.count(0))
    if(cnt[0]>=2) drop("cslnb");

  Int num=0;
  vector<Int> bs;
  for(auto p:cnt){
    if(p.second>=3) drop("cslnb");
    if(p.second>=2){
      num++;
      if(cnt.count(p.first-1)) drop("cslnb");
      bs.emplace_back(p.first-1);
    }
    bs.emplace_back(p.first);
  }
  if(num>=2) drop("cslnb");

  n=bs.size();
  Int sum=0;
  for(Int i=0;i<n;i++) sum+=bs[i]-i;
  //cout<<sum<<endl;
  Int win=sum&1;

  if(num==1) win=!win;
  cout<<(win?"sjfnb":"cslnb")<<endl;
  return 0;
}