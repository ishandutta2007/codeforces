#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  string s[n],t[n];
  for(int i=0;i<n;i++) cin>>s[i];
  for(int i=1;i<n;i++){
    string t=s[i]+s[i];
    if(t.find(s[0])==string::npos){
      cout<<-1<<endl;
      return 0;
    }
  }
  int l=s[0].length();
  int ans=1LL<<55LL;
  for(int i=0;i<l;i++){
    int tmp=i;
    //cout<<s[0];
    for(int j=1;j<n;j++){
      t[j]=s[j];
      while(s[0]!=t[j]){
	//cout<<s[0]<<" "<<s[j]<<endl;
	t[j]+=t[j][0];
	t[j].erase(t[j].begin());
	tmp++;
      }
      //cout<<" "<<tmp;
    }
    //cout<<" "<<tmp<<endl;
    ans=min(ans,tmp);
    s[0]+=s[0][0];
    s[0].erase(s[0].begin());
  }
  cout<<ans<<endl;
  return 0;
}