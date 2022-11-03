#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n,l;
  cin>>n>>l;
  vector<int> a(n),b(n),c,d;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) cin>>b[i];
  bool f=0;
  for(int i=0;i<n-1;i++){
    c.push_back(a[i+1]-a[i]);
    d.push_back(b[i+1]-b[i]);
  }
  c.push_back(l+a[0]-a[n-1]);
  d.push_back(l+b[0]-b[n-1]);
  for(int i=0;i<n;i++){
    bool ff=1;
    for(int j=0;j<n;j++) ff&=c[j]==d[(i+j)%n];    
    f|=ff;
  }
  cout<<(f?"YES":"NO")<<endl;
  return 0;
}