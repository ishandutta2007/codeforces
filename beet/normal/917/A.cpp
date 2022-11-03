#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
bool dp[5555][5555];
signed main(){
  memset(dp,0,sizeof(dp));
  string s;
  cin>>s;
  Int n=s.size();
  string t,u=s;
  for(Int i=0;i<n;i++){
    if(s[n-(i+1)]=='(') t+=')';
    else t+='(';
  }
  for(Int i=0;i<n;i++)
    if(s[i]=='?') s[i]='(';

  //cout<<s<<" "<<t<<endl;

  for(Int i=0;i<n;i++){
    Int o=0;
    for(Int j=i;j<n;j++){
      if(o>=0){
	if(s[j]=='(') o++;
	if(s[j]==')') o--;
      }
      if(o<0) dp[i][j+1]=1;
    }
  }
  for(Int i=0;i<n;i++){
    Int o=0;
    for(Int j=i;j<n;j++){
      if(o>=0){
	if(t[j]=='(') o++;
	if(t[j]==')') o--;
      }
      if(o<0) dp[n-(j+1)][n-(i+1)+1]=1;
    }
  }

  Int ans=0;
  for(Int i=0;i<n;i++)
    for(Int j=i+1;j<=n;j++)
      if((j-i)%2==0 && !dp[i][j]) ans++;

  if(0){
    for(Int i=0;i<n;i++)
      for(Int j=i+1;j<=n;j++)
	if((j-i)%2==0 && !dp[i][j])
	  cout<<i<<" "<<j<<":"<<u.substr(i,j-i)<<endl;
  }
  
  cout<<ans<<endl;
  return 0;
}