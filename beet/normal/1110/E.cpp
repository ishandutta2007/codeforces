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
  Int n;
  cin>>n;
  vector<Int> c(n),t(n);
  for(Int i=0;i<n;i++) cin>>c[i];
  for(Int i=0;i<n;i++) cin>>t[i];

  if(c[0]!=t[0]){
    cout<<"No"<<endl;
    return 0;
  }
  
  vector<Int> a(n-1),b(n-1);
  for(Int i=0;i+1<n;i++){
    a[i]=c[i+1]-c[i];
    b[i]=t[i+1]-t[i];
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  
  for(Int i=0;i+1<n;i++){
    if(a[i]!=b[i]){
      cout<<"No"<<endl;
      return 0;
    }
  }
  
  cout<<"Yes"<<endl;
  return 0;
}