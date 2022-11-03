#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  bool f=1;
  string s;
  cin>>s;
  char c='a'-1;
  for(int i=0;i<(int)s.size();i++){
    if(s[i]<=c) continue;
    if(s[i]==c+1) c=s[i];
    else f=0;
  }
  cout<<(f?"YES":"NO")<<endl;
  return 0;
}