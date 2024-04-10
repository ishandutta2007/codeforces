#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,k;
  cin>>n>>k;
  int a[n],b[n];
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) cin>>b[i];
  int ans=0;
  priority_queue<int> q;
  for(int i=0;i<n;i++){
    q.push(a[i]-b[i]);
    ans+=a[i];
  }
  for(int i=0;i<n-k;i++){
    int p=q.top();q.pop();
    if(p<=0) break;
    ans-=p;
  }
  cout<<ans<<endl;
  return 0;
}