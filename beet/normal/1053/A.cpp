#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n,m,k;
  cin>>n>>m>>k;
  Int x=n*m,y=k;
  Int z=__gcd(x,y);
  x/=z;y/=z;
  if(y>2){
    cout<<"NO"<<endl;
    return 0;
  }
  if(y==1){    
    Int p=n/__gcd(n,k),q=2*x/p;
    if(q>m) p*=2,q/=2;
    cout<<"YES"<<endl;
    cout<<0<<" "<<0<<endl;
    cout<<p<<" "<<0<<endl;
    cout<<0<<" "<<q<<endl;
    return 0;
  }
  //cout<<x<<" "<<y<<" "<<z<<endl;
  Int p=n/__gcd(n,k/2),q=x/p;
  cout<<"YES"<<endl;
  cout<<0<<" "<<0<<endl;
  cout<<p<<" "<<0<<endl;
  cout<<0<<" "<<q<<endl;
  return 0;
}