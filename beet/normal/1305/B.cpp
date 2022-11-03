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
  string s;
  cin>>s;
  int n=s.size();

  vector<int> ans;
  int l=0,r=n-1;
  while(l<r){
    while(l<n&&s[l]!='(') l++;
    if(l>=n) break;
    while(r>=0&&s[r]!=')') r--;
    if(r<0) break;
    if(l>=r) break;
    ans.emplace_back(l);
    ans.emplace_back(r);
    l++;
    r--;
  }

  if(ans.empty()){
    cout<<0<<endl;
    return 0;
  }

  cout<<1<<endl;
  cout<<ans.size()<<endl;
  sort(ans.begin(),ans.end());
  for(int i=0;i<(int)ans.size();i++){
    cout<<ans[i]+1<<" ";
  }
  cout<<endl;
  return 0;
}