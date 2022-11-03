#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,m,k,x,y;
  ll a1=0,a2=0,a3=0;
  cin>>n>>m>>k>>x>>y;
  if(n==1){
    a1+=k/m;
    a2+=k/m;
    a3+=k/m;
    k%=m;
    if(k) a1++;
    if(y<=k) a3++;
  }else if(n==2){
    a1+=k/(m*2);
    a2+=k/(m*2);
    a3+=k/(m*2);
    k%=m*2;
    if(k) a1++;
    if((x-1)*m+y<=k) a3++;
  }else{
    a1+=k/(2*m*(n-1))*2;
    a2+=k/(2*m*(n-1));
    if(x==1||x==n) a3+=k/(2*m*(n-1));
    else a3+=k/(2*m*(n-1))*2;
    k%=(2*m*(n-1));
    if(m<=k) a1++;
    if(m*n<k) a1++;
    if(!a1) a1++;
    if(m*n<=k) a2++;
    if(x==1){
      if(y<=k) a3++;
    }else if(x==n){
      if(m*(n-1)+y<=k) a3++;
    }else{
      if(m*(x-1)+y<=k) a3++;
      if(((n-1)+(n-x))*m+y<=k) a3++;
    }
  }
  cout<<a1<<" "<<a2<<" "<<a3<<endl;
  return 0;
}