#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string t,p;
  cin>>t>>p;
  int n=t.length(),q=p.length();
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  reverse(a,a+n);
  int l=0,r=n;
  while(l+1<r){
    int b[n];
    memset(b,0,sizeof(b));
    int m=(l+r)/2;
    for(int i=0;i<m;i++) b[a[i]-1]=1;
    int pos=0;
    for(int i=0;i<n;i++){
      if(b[i]&&pos<q&&t[i]==p[pos]) pos++; 
    }
    if(pos==q) r=m;
    else l=m;
  }
  cout<<n-r<<endl;
  return 0;
}