#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  string s;
  cin>>s;

  if(s==string(s.size(),'a')){
    s.back()='z';
    drop(s);
  }

  int state=0;
  for(char c:s){
    if(state==0){
      if(c=='a') cout<<c;
      else cout<<char(c-1),state=1;
    }else if(state==1){
      if(c=='a') cout<<c,state=2;
      else cout<<char(c-1);
    }else if(state==2){
      cout<<c;
    }
  }
  cout<<newl;
  return 0;
}