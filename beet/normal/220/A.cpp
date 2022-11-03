#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  int a[n],b[n];
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) b[i]=a[i];
  sort(b,b+n);
  int f=0;
  for(int i=0;i<n;i++) f+=a[i]!=b[i];
  cout<<(f<=2?"YES":"NO")<<endl; 
  return 0;
}