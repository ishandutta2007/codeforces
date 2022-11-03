#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isprime(int n){
  if(n<2) return 0;
  for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
  return 1;
}
bool ispalin(int n){
  string s=to_string(n);
  string t=s;
  reverse(t.begin(),t.end());
  return t[0]!='0'&&t==s;
}
signed main(){
  int n=1400000;
  int x=0,y=0;
  int ans=-1;
  int p,q;
  cin>>p>>q;
  for(int i=1;i<n;i++){
    if(isprime(i)) x++;
    if(ispalin(i)) y++;
    if(x*q<=y*p) ans=i;
    //if(i<100||i%100000==0) cout<<i<<" "<<x<<":"<<y<<"-"<<(double)x/y<<endl;
  }
  if(ans<0) cout<<"Palindromic tree is better than splay tree"<<endl;
  else cout<<ans<<endl;
  return 0;
}