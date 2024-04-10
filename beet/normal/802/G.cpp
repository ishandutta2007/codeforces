#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string base="heidi";
  string s;
  cin>>s;
  int p=0;
  for(int i=0;i<(int)s.size();i++){
    if(s[i]==base[p]) p++;
    if(p==5) break;
  }
  cout<<(p==5?"YES":"NO")<<endl;
  return 0;
}