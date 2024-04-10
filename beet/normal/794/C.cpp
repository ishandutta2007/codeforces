#include<bits/stdc++.h>
using namespace std;
#define int long long
char buf[333333];
signed main(){
  scanf("%s",buf);
  string ts(buf);
  scanf("%s",buf);
  string tt(buf);
  int n=ts.length();
  deque<char> s,t;
  sort(ts.begin(),ts.end());
  sort(tt.rbegin(),tt.rend());
  for(int i=0;i<n/2;i++){
    s.push_back(ts[i]);
    t.push_back(tt[i]);
  }
  if(n%2) s.push_back(ts[n/2]);
  string ans,tmp;
  //printf("%s\n",ts.c_str());
  //printf("%s\n",tt.c_str());
  for(int i=0;i<n/2;i++){
    if(!s.empty()&&!t.empty()&&s.front()<t.front()){
      ans.push_back(s.front());
      s.pop_front();
    }else{
      tmp.push_back(s.back());
      s.pop_back();
    }
    //cout<<ans<<":"<<tmp<<endl;
    if(!s.empty()&&!t.empty()&&s.front()<t.front()){
      ans.push_back(t.front());
      t.pop_front();
    }else{
      tmp.push_back(t.back());
      t.pop_back();
    }
    //cout<<ans<<":"<<tmp<<endl;
  }
  if(n%2) ans.push_back(s.front());
  reverse(tmp.begin(),tmp.end());
  ans+=tmp;
  printf("%s\n",ans.c_str());
  return 0;
}