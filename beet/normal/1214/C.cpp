#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE

Int check(string s){
  Int n=s.size();
  Int op=0;
  for(Int i=0;i<n;i++){
    if(s[i]=='(') op++;
    if(s[i]==')') op--;
    if(op<0) return 0;
  }
  return 1;
}

signed main(){
  Int n;
  cin>>n;
  string s;
  cin>>s;

  if(n&1) drop("No");

  Int cnt=0;
  for(char c:s) if(c=='(') cnt++;
  if(cnt*2!=n) drop("No");

  if(check(s)) drop("Yes");

  for(Int i=0;i<n;i++){
    if(s[i]!=')') continue;
    string t=s;
    t.erase(t.begin()+i);
    t=t+')';
    if(check(t)) drop("Yes");
    break;
  }

  for(Int i=n-1;i>=0;i--){
    if(s[i]!='(') continue;
    string t=s;
    t.erase(t.begin()+i);
    t='('+t;
    if(check(t)) drop("Yes");
    break;
  }

  drop("No");
  return 0;
}