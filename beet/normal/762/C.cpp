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

//INSERT ABOVE HERE
signed main(){
  string a,b;
  cin>>a>>b;

  int na=a.size(),nb=b.size();  
  vector<int> pre(nb,na),suf(nb,-1);
  
  int len=0;
  {
    int j=0;
    for(int i=0;i<nb;i++){
      while(j<na&&a[j]!=b[i]) j++;
      if(j<na){
        pre[i]=j++;
        chmax(len,i+1);
      }
    }
  }
  {
    int j=na-1;
    for(int i=nb-1;i>=0;i--){
      while(j>=0&&a[j]!=b[i]) j--;
      if(j>=0){       
        suf[i]=j--;
        chmax(len,nb-i);
      }
    }
  }
  
  for(int i=0,j=i+1;i<nb;i++){
    while(i>=j) j++;
    while(j<nb&&pre[i]>=suf[j]) j++;
    if(pre[i]==na||j==nb) break;
    chmax(len,(i+1)+(nb-j));
  }
  
  if(len==0){
    cout<<"-"<<endl;
    return 0;
  }
  
  if(pre[len-1]<na){
    cout<<b.substr(0,len)<<endl;
    return 0;
  }  

  if(suf[nb-len]>=0){
    cout<<b.substr(nb-len,len)<<endl;
    return 0;
  }
  
  for(int i=0,j=i+1;i<nb;i++){
    while(i>=j) j++;
    while(j<nb&&pre[i]>=suf[j]) j++;
    if(pre[i]==na||j==nb) break;
    if(len==(i+1)+(nb-j)){
      cout<<b.substr(0,i+1)+b.substr(j,nb-j)<<endl;
      return 0;
    }
  }
  return 0;
}