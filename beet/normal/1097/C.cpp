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
  Int n;
  cin>>n;
  vector<string> vs(n);
  for(Int i=0;i<n;i++) cin>>vs[i];

  const Int MAX = 5e5+100;
  vector<Int> pos(MAX),neg(MAX);
  Int zero=0;
  for(string s:vs){
    Int len=s.size();
    Int cl=0,cr=0;
    Int fl=1,fr=1;
    for(Int i=0;i<len;i++){
      if(s[i]=='(') cl++;
      if(s[i]==')') cl--;
      if(cl<0) fl=0;
    }
    for(Int i=len-1;i>=0;i--){
      if(s[i]==')') cr++;
      if(s[i]=='(') cr--;
      if(cr<0) fr=0;
    }
    assert(cl+cr==0);
    
    if(fl==0&&fr==0) continue;
    
    if(cl==0){
      assert(fl&&fr);
      zero++;
      continue;
    }
    
    if(fl&&cl>0) pos[cl]++;
    if(fr&&cr>0) neg[cr]++;
  }  
  
  Int ans=zero/2;
  for(Int i=0;i<MAX;i++) ans+=min(pos[i],neg[i]);
  cout<<ans<<endl;
  return 0;
}