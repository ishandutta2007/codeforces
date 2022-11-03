#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,m;
  cin>>n>>m;
  Int quo=n/m;
  Int rem=n%m;
  cout<<(quo*(quo-1)/2)*(m-rem)+(quo*(quo+1)/2)*rem<<" ";
  cout<<(n-m+1)*(n-m)/2<<endl;
  return 0;
}