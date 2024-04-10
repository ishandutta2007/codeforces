#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  Int n,a,b;
  cin>>n>>a>>b;
  for(Int i=0;i*a<=n;i++){
    Int j=n-(i*a);
    if(j%b) continue;
    j/=b;
    Int p=0,f=0;
    for(Int k=0;k<i;k++){
      if(f++) cout<<" ";
      cout<<p+a;
      for(Int l=0;l<a-1;l++){
	if(f++) cout<<" ";
	cout<<++p;
      }
      p++;
    }
    for(Int k=0;k<j;k++){
      if(f++) cout<<" ";
      cout<<p+b;
      for(Int l=0;l<b-1;l++){
	if(f++) cout<<" ";
	cout<<++p;
      }
      p++;
    }
    cout<<endl;
    return 0;
  }
  cout<<-1<<endl;
  return 0;
}