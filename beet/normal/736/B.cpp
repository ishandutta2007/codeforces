#include<bits/stdc++.h>
using namespace std;
using Int = long long;
int isprime(int x){
  for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
  return 1;
}
signed main(){
  int n;
  cin>>n;
  if(isprime(n)){
    cout<<1<<endl;
    return 0;
  }
  if(n%2==0){
    cout<<2<<endl;
    return 0;
  }
  if(isprime(n-2)){
    cout<<2<<endl;
    return 0;
  }
  cout<<3<<endl;
  return 0;
}