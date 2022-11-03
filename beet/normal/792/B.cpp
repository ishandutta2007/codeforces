#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,k;
  cin>>n>>k;
  int a[k];
  for(int i=0;i<k;i++) cin>>a[i];
  vector<int> v(n);
  for(int i=0;i<n;i++) v[i]=i+1;
  int p=0;
  for(int i=0;i<k;i++){
    (p+=a[i])%=v.size();
    if(i) cout<<" ";
    cout<<v[p];
    v.erase(v.begin()+p);
  }
  cout<<endl;
  return 0;
}