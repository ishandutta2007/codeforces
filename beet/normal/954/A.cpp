#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  string s;
  cin>>n>>s;
  Int ans=n;
  queue<string> q;
  q.emplace(s);
  while(!q.empty()){
    s=q.front();q.pop();
    chmin(ans,(Int)s.size());
    //cout<<s<<endl;
    for(Int i=0;i<(Int)s.size()-1;i++){
      if(s[i]==s[i+1]) continue;
      if(s[i]=='D'||s[i+1]=='D') continue;
      string t=s.substr(0,i)+string("D")+s.substr(i+2);
      q.emplace(t);
      break;
    }
  }
  cout<<ans<<endl;
  return 0;
}