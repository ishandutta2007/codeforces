#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,k;
  cin>>n>>k;
  if(n/2>k){
    cout<<-1<<endl;
    return 0;
  }
  if(n==1){
    if(k==0) cout<<1<<endl;
    else cout<<-1<<endl;
    return 0;
  }
  set<int> s;
  if(n/2==k){
    int a=1;
    for(int i=0;i<n/2;i++){
      while(s.count(a)) a++;
      int b=a+1;
      while(s.count(b)||__gcd(a,b)!=1LL) b++;
      s.insert(a);
      s.insert(b);
      if(i) cout<<" "<<a<<" "<<b;
      else cout<<a<<" "<<b;
    }
    while(s.count(a)) a++;
    if(n%2&&n>1) cout<<" ";
    if(n%2) cout<<a<<endl;
    else cout<<endl;
    return 0;
  }
  int x=k-(n/2-1);
  cout<<x<<" "<<x*2;
  s.insert(x);
  s.insert(x*2);
  int a=1;
  for(int i=0;i<n/2-1;i++){
    while(s.count(a)) a++;
    int b=a+1;
    while(s.count(b)||__gcd(a,b)!=1LL) b++;
    s.insert(a);
    s.insert(b);
    cout<<" "<<a<<" "<<b;
  }
  while(s.count(a)) a++;
  if(n%2) cout<<" "<<a<<endl;
  else cout<<endl;
  return 0;
}