#include <bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  string s;
  cin>>s;

  int op=0;
  for(char c:s){
    if(c=='(') op++;
    else op--;
  }
  if(op!=0) drop(-1);

  int len=0,ans=0,flg=0;
  for(char c:s){
    if(op==0){
      if(c==')') flg=1;
      else flg=0;
    }

    if(c=='(') op++;
    else op--;

    len++;
    if(op==0){
      ans+=len*flg;
      len=0;
    }
  }
  cout<<ans<<endl;
  return 0;
}