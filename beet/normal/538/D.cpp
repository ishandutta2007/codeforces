#include<bits/stdc++.h>
using namespace std;
#define int long long
int mv[111][111];
int ok[111][111];
void bye(){
  cout<<"NO"<<endl;
  exit(0);
}
signed main(){
  int n;
  cin>>n;
  string s[n];
  for(int i=0;i<n;i++) cin>>s[i];
  memset(mv,-1,sizeof(mv));    
  memset(ok,0,sizeof(ok));    
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(s[i][j]!='o') continue;
      for(int k=0;k<n;k++){
	for(int l=0;l<n;l++){
	  if(s[k][l]!='.') continue;
	  mv[n-1+(k-i)][n-1+(l-j)]=0;
	}
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(s[i][j]!='o') continue;
      for(int k=0;k<n;k++){
	for(int l=0;l<n;l++){
	  if(s[k][l]=='.') continue;
	  if(mv[n-1+(k-i)][n-1+(l-j)]!=0)
	    mv[n-1+(k-i)][n-1+(l-j)]=1,ok[k][l]=1;
	}
      }
    }
  }
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(s[i][j]=='x'&&!ok[i][j]) bye();
  
  cout<<"YES"<<endl;
  for(int i=0;i<n*2-1;i++){
    for(int j=0;j<n*2-1;j++){
      if(i==n-1&&j==n-1) cout<<"o";
      else if(mv[i][j]>0) cout<<"x";
      else cout<<".";
    }
    cout<<endl;
  }
  return 0;
}