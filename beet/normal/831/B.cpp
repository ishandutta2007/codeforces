#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string s1,s2,s3;
  cin>>s1>>s2>>s3;
  map<char,char> m;
  for(int i=0;i<26;i++){
    m[tolower(s1[i])]=tolower(s2[i]);
    m[toupper(s1[i])]=toupper(s2[i]);
  }
  for(int i=0;i<10;i++) m['0'+i]='0'+i;
  for(int i=0;i<(int)s3.size();i++)
    cout<<m[s3[i]];
  cout<<endl;
  return 0;
}