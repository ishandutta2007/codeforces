#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  int s[n];
  for(int i=0;i<n;i++) cin>>s[i];
  int ans=s[0]^s[1];
  stack<int> st;
  for(int i=0;i<n;i++){
    while(!st.empty()){
      if(st.top()<s[i]) st.pop();
      else break;
    }
    if(!st.empty()) ans=max(ans,st.top()^s[i]);
    st.push(s[i]);
  }
  while(!st.empty()) st.pop();
  reverse(s,s+n);
  for(int i=0;i<n;i++){
    while(!st.empty()){
      if(st.top()<s[i]) st.pop();
      else break;
    }
    if(!st.empty()) ans=max(ans,st.top()^s[i]);
    st.push(s[i]);
  }
  cout<<ans<<endl;
  return 0;
}