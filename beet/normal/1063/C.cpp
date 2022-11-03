#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
const int MAX = 1e9;
int ask(int x,int y){
  assert(0<=x&&x<=MAX);
  assert(0<=y&&y<=MAX);
  
  cout<<x<<" "<<y<<endl;
  string s;
  cin>>s;
  return s=="black"s;
}

signed main(){
  int n;
  cin>>n;

  int b=ask(0,0);
  if(n==1){
    cout<<"0 1 1 0"<<endl;
    return 0;
  }
  
  int t=ask(0,2);

  int x1=0,y1=(b==t?3:1);
  
  int l=0,r=1<<29;
  for(int i=2;i<n;i++){
    int m=(l+r)>>1;
    int k=ask(m,0);
    if(b==k) l=m;
    else r=m;
  }
  
  int x2=l+1,y2=0;
  
  assert(0<=x1&&x1<=MAX);
  assert(0<=y1&&y1<=MAX);
  assert(0<=x2&&x2<=MAX);
  assert(0<=y2&&y2<=MAX);
  
  cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
  return 0;
}