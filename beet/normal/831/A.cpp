#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  int s=0;
  for(int i=0;i<n-1;i++){
    if(s==0){
      if(a[i]==a[i+1]) s=1;
      else if(a[i]>a[i+1]) s=2;
    }else if(s==1){
      if(a[i]<a[i+1]){
	cout<<"NO"<<endl;
	return 0;
      }
      if(a[i]>a[i+1]) s=2;
    }else if(s==2){
      if(a[i]<=a[i+1]){
	cout<<"NO"<<endl;
	return 0;
      }
    }
  }
  cout<<"YES"<<endl;
  return 0;
}