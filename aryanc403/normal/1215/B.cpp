#include <iostream>
using namespace std;
int main() {
  long long n,s=0,t=0;cin>>n;
  for (int i=0,_;i<n;i++,s+=t){cin>>_;t=_>0?t+1:i-t;}
  cout<<(n*(n+1)/2-s)<<' '<<s;
}