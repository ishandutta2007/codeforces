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

  const int MAX = 1000;
  vector<int> dp(MAX,0);
  for(int i=2;i<MAX;i++){
    int x=i/2,y=i-x;
    dp[i]=dp[x]+dp[y]+(x*y);
  }

  int k;
  cin>>k;

  string ans;
  for(int i=0;i<26;i++){
    for(int j=MAX-1;j>=0;j--){
      if(k-dp[j]>=0){
        k-=dp[j];
        ans+=string(j,'a'+i);
        break;
      }
    }
  }

  assert(k==0);
  cout<<ans<<endl;
  return 0;
}