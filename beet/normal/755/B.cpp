#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n,m;
  cin>>n>>m;
  set<string> ss[2],c;
  string s;
  for(int i=0;i<n;i++){
    cin>>s;
    ss[0].insert(s);
  }
  for(int i=0;i<m;i++){
    cin>>s;
    ss[1].insert(s);
  }
  for(auto i:ss[0]) if(ss[1].count(i)) c.insert(i);
  int x=ss[0].size()-c.size(),y=ss[1].size()-c.size(),z=c.size();
  x+=z-z/2;
  y+=z/2;
  if(x>y) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}