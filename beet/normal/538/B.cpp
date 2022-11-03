#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string s;
  cin>>s;
  int k=0;
  reverse(s.begin(),s.end());
  int cnt[10]={};
  for(int i=0;i<(int)s.size();i++){
    k=max(k,(int)s[i]-'0');
    cnt[i]=(int)s[i]-'0';
  }
  cout<<k<<endl;
  for(int i=0;i<k;i++){
    string t;
    for(int j=0;j<10;j++)
      if(cnt[j]) t+="1",cnt[j]--;
      else t+="0";
    while(t.back()=='0') t.pop_back();
    reverse(t.begin(),t.end());
    if(i) cout<<" ";
    cout<<t;
  }
  cout<<endl;
  return 0;
}