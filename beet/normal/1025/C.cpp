#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  string s;
  cin>>s;
  s=s+s;
  Int n=s.size();
  Int ans=0;
  for(Int i=0;i<n;i++){
    Int j=i;
    while(j+1<n&&s[j]!=s[j+1]) j++;
    chmax(ans,j-i+1);
    i=j;
  }
  chmin(ans,n/2);
  cout<<ans<<endl;
  return 0;
}