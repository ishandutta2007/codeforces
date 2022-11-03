#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n;
  cin>>n;
  int a[n],s[n+1];
  s[0]=0;
  for(int i=0;i<n;i++) cin>>a[i],s[i+1]=s[i]+a[i];
  if(s[n]){
    cout<<"YES"<<endl<<1<<endl<<1<<" "<<n<<endl;
    return 0;
  }
  bool dp[n+1];
  int pre[n+1];
  memset(dp,0,sizeof(dp));
  memset(pre,-1,sizeof(pre));
  dp[0]=1;
  for(int i=0;i<n;i++)
    for(int j=i+1;j<=n;j++)
      if(dp[i]&&(s[j]-s[i])) dp[j]=1,pre[j]=i;
  if(dp[n]){
    vector<int> v;
    int i=n;
    while(~i){
      v.push_back(i);
      i=pre[i];
    }
    cout<<"YES"<<endl;
    reverse(v.begin(),v.end());
    cout<<v.size()-1<<endl;
    for(int j=0;j<(int)v.size()-1;j++){
      cout<<v[j]+1<<" "<<v[j+1]<<endl;
    }
  }else cout<<"NO"<<endl;
  return 0;
}