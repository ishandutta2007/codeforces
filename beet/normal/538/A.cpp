#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string cf="CODEFORCES";
  string s;
  cin>>s;
  bool f=0;
  for(int i=0;i<(int)s.size()+1;i++){
    for(int j=i;j<(int)s.size()+1;j++){
      string x=s.substr(0,i)+s.substr(j,s.size()-j);
      //cout<<x<<endl;
      if(x==s) continue;
      f|=cf==x;
    }
  }
  cout<<(f?"YES":"NO")<<endl;
  return 0;
}