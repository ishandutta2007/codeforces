#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  Int n,m;
  cin>>n>>m;
  Int a=1;
  for(Int i=0;i<min(n,(Int)31);i++) a<<=1;
  cout<<m%a<<endl;
  return 0;
}