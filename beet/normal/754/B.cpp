#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int h=4,w=4;
  string s[h];
  for(int i=0;i<h;i++) cin>>s[i];
  bool f=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]!='.') continue;
      s[i][j]='x';
      for(int k=0;k<4;k++){
	f|=(s[k][0]=='x'&&s[k][1]=='x'&&s[k][2]=='x');
	f|=(s[k][1]=='x'&&s[k][2]=='x'&&s[k][3]=='x');
	f|=(s[0][k]=='x'&&s[1][k]=='x'&&s[2][k]=='x');
	f|=(s[1][k]=='x'&&s[2][k]=='x'&&s[3][k]=='x');
      }
      f|=(s[0][0]=='x'&&s[1][1]=='x'&&s[2][2]=='x');
      f|=(s[1][1]=='x'&&s[2][2]=='x'&&s[3][3]=='x');
      f|=(s[0][1]=='x'&&s[1][2]=='x'&&s[2][3]=='x');
      f|=(s[1][0]=='x'&&s[2][1]=='x'&&s[3][2]=='x');
      
      f|=(s[0][2]=='x'&&s[1][1]=='x'&&s[2][0]=='x');
      f|=(s[1][2]=='x'&&s[2][1]=='x'&&s[3][0]=='x');
      f|=(s[0][3]=='x'&&s[1][2]=='x'&&s[2][1]=='x');
      f|=(s[1][3]=='x'&&s[2][2]=='x'&&s[3][1]=='x');
      s[i][j]='.';
    }
  }
  cout<<(f?"YES":"NO")<<endl;
  return 0;
}