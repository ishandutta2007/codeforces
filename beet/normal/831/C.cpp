#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int k,n;
  cin>>k>>n;
  int a[k],b[n];
  for(int i=0;i<k;i++) cin>>a[i];
  for(int i=0;i<n;i++) cin>>b[i];
  int s=0;
  set<int> si;
  for(int i=0;i<k;i++){
    s+=a[i];
    si.insert(s);
  }
  sort(b,b+n);
  int ans=0;
  for(int u:si){
    bool flg=1;
    int off=u-b[0];
    for(int i=0;i<n;i++)
      flg&=si.count(b[i]+off);
    //cout<<off<<" "<<flg<<endl;
    if(flg) ans++;
  }
  cout<<ans<<endl;
  return 0;
}