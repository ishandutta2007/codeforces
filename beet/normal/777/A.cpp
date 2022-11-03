#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n,x;
  cin>>n>>x;
  n%=6;
  if(n==0){
    cout<<x<<endl;
  }
  if(n==1){
    if(x==0) cout<<1<<endl;
    if(x==1) cout<<0<<endl;
    if(x==2) cout<<2<<endl;
  }
  if(n==2){
    if(x==0) cout<<1<<endl;
    if(x==1) cout<<2<<endl;
    if(x==2) cout<<0<<endl;
  }
  if(n==3){
    if(x==0) cout<<2<<endl;
    if(x==1) cout<<1<<endl;
    if(x==2) cout<<0<<endl;
  }
  if(n==4){
    if(x==0) cout<<2<<endl;
    if(x==1) cout<<0<<endl;
    if(x==2) cout<<1<<endl;
  }
  if(n==5){
    if(x==0) cout<<0<<endl;
    if(x==1) cout<<2<<endl;
    if(x==2) cout<<1<<endl;
  }
  return 0;
}