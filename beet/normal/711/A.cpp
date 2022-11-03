#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int i,j,k;
  string s[n];
  bool f=false;
  for(i=0;i<n;i++) {
    cin>>s[i];
    if(!f){
      if(s[i][0]=='O'&&s[i][1]=='O'){
	s[i][0]='+';s[i][1]='+';
	f=true;
      }else if(s[i][3]=='O'&&s[i][4]=='O'){
	s[i][3]='+';s[i][4]='+';
	f=true;
      }
    }
  }
  if(f){
    cout << "YES" << endl;
    for(i=0;i<n;i++) cout << s[i] << endl;
  }else cout << "NO" << endl;
  return 0;
}