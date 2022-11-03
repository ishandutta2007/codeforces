#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


vector<Int> zalgorithm(const string &s){
  Int n=s.size();
  vector<Int> a(n,0);
  a[0]=n;
  Int i=1,j=0;
  while(i<n){
    while(i+j<n&&s[j]==s[i+j]) j++;
    a[i]=j;
    if(j==0){
      i++;
      continue;
    }
    Int k=1;
    while(i+k<n&&k+a[k]<j) a[i+k]=a[k],k++;
    i+=k;
    j-=k;
  }
  return a;
}

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  string s,t;
  cin>>s>>t;
  Int n=s.size(),m=t.size();  
  if(n<m){
    cout<<s<<endl;
    return 0;
  }
  auto z=zalgorithm(t);
  Int len=0;
  for(Int i=1;i<m;i++){
    if(z[i]==m-i) chmax(len,z[i]);
  }
  //cout<<len<<endl;

  Int cnt0=0,cnt1=0;
  for(char c:s){
    if(c=='0') cnt0++;
    if(c=='1') cnt1++;
  }

  Int num0=0,num1=0;
  for(char c:t){
    if(c=='0') num0++;
    if(c=='1') num1++;
  }
  
  if(cnt0<num0||cnt1<num1){    
    cout<<s<<endl;
    return 0;
  }
  
  string ans=t;
  cnt0-=num0;
  cnt1-=num1;
  
  Int add0=0,add1=0;
  for(Int i=len;i<m;i++){
    if(t[i]=='0') add0++;
    if(t[i]=='1') add1++;
  }
  
  while(add0<=cnt0&&add1<=cnt1){    
    for(Int i=len;i<m;i++) ans.push_back(t[i]);    
    cnt0-=add0;
    cnt1-=add1;
  }

  for(Int i=0;i<cnt0;i++) ans.push_back('0');
  for(Int i=0;i<cnt1;i++) ans.push_back('1');  

  cout<<ans<<endl;
  return 0;
}