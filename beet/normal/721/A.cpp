#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,j;
  string s;
  cin>>n>>s;
  vector<int> v;
  for(i=0;i<n;i++){
    if(s[i]=='W') continue;
    j=i;
    while(i<n&&s[i]=='B') i++;
    v.push_back(i-j);
  }
  cout << v.size() << endl;
  for(i=0;i<v.size();i++) cout << v[i] << (i==v.size()-1?'\n':' ');
  return 0;
}