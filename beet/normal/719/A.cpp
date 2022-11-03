#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int a[n],i;
  for(i=0;i<n;i++) cin>>a[i];
  if(n==1) {
    if(a[0]==0) cout << "UP" << endl;
    else if(a[0]==15) cout << "DOWN" << endl;
    else cout << -1 << endl;
  }else{
    if(a[n-2]==14&&a[n-1]==15) cout << "DOWN" << endl;
    else if(a[n-2]==1&&a[n-1]==0) cout << "UP" << endl;
    else if(a[n-2]<a[n-1]) cout << "UP" << endl;
    else cout << "DOWN" << endl;
  }
  return 0;
}