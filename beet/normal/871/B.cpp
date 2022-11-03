#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  int n;
  cin>>n;
  int pb[n];
  for(int j=0;j<n;j++){
    cout<<"? "<<0<<" "<<j<<endl;
    cin>>pb[j];
  }
  int bp[n];
  bp[0]=pb[0];
  for(int i=1;i<n;i++){
    cout<<"? "<<i<<" "<<0<<endl;
    cin>>bp[i];
  }
  int cnt=0,ans[n];
  for(int i=0;i<n;i++){
    int tmp[n],rev[n];
    memset(tmp,-1,sizeof(tmp));
    memset(rev,-1,sizeof(rev));
    tmp[0]=i;
    for(int j=0;j<n;j++){
      rev[j]=tmp[0]^pb[j];
    }
    if((rev[0]^bp[0])!=tmp[0]) continue;
    for(int j=0;j<n;j++){
      tmp[j]=rev[0]^bp[j];
    }
    bool f=1;
    for(int j=0;j<n;j++){
      if(tmp[j]<0||rev[j]<0||tmp[j]>=n||rev[j]>=n){
	f=0;
	continue;
      }
      f&=rev[tmp[j]]==j;
    }
    if(f){
      if(!cnt){
	for(int j=0;j<n;j++) ans[j]=tmp[j];
      }
      cnt++;
    }
  }
  cout<<"!"<<endl;
  cout<<cnt<<endl;
  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
  return 0;
}