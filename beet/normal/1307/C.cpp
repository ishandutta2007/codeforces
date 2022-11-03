#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE

const Int Z = 26;
Int cnt[Z][Z];

signed main(){
  string s;
  cin>>s;

  memset(cnt,0,sizeof(cnt));
  vector<Int> num(Z,0);
  for(char c:s){
    Int p=c-'a';
    for(Int i=0;i<Z;i++)
      cnt[i][p]+=num[i];
    num[p]++;
  }

  Int ans=*max_element(num.begin(),num.end());
  for(Int i=0;i<Z;i++)
    for(Int j=0;j<Z;j++)
      chmax(ans,cnt[i][j]);
  cout<<ans<<endl;
  return 0;
}