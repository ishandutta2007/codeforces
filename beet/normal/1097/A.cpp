#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  string s;
  cin>>s;
  vector<string> cs(5);  
  for(int i=0;i<5;i++) cin>>cs[i];
  
  auto YES=[](){cout<<"YES"<<endl;exit(0);};
  for(string c:cs)
    if(s[0]==c[0]||s[1]==c[1]) YES();

  cout<<"NO"<<endl;
  return 0;
}