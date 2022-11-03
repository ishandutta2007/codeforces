#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  vector<int> b=a;
  sort(b.begin(),b.end());
  b.erase(unique(b.begin(),b.end()),b.end());
  if(a.size()!=b.size()){
    cout<<-1<<endl;
    return 0;
  }
  map<int,int> s,t;
  for(int i=0;i<n;i++) s[a[i]]=i,t[b[i]]=i;
  auto c=a;
  for(int i=0;i<n;i++)
    c[i]=b[(t[a[i]]+1)%n];
  
  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<c[i];
  }
  cout<<endl;
  return 0;
}