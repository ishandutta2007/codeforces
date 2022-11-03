#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,t,i,j,k=-1;
  string s;
  cin >> n >> t >> s;
  for(i=0;i<n;i++){
    if(s[i]=='.') {
      k=i++;
      break;
    }
  }
  if(~k){
    while(i<n&&s[i]<'5') i++;
    if(i!=n){
      for(j=1;j<t;j++){
	if(s[i-j]=='4') continue;
	break;
      }
      if(i-j==k){
	s=s.substr(0,k);
	for(i=s.size()-1;i>=0;i--){
	  if(s[i]=='9'){
	    s[i]='0';
	    if(i==0) s="1"+s;
	  }else{
	    s[i]++;
	    break;
	  }
	}
      }else{
	s=s.substr(0,i-j+1);
	for(i=s.size()-1;i>=0;i--){
	  if(s[i]=='9') {
	    s[i]='0';
	  }else{
	    s[i]++;
	    break;
	  }
	}
      }
    }
  }
  cout << s << endl;
  return 0;
}