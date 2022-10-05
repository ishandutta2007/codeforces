#include<bits/stdc++.h>
using namespace std;
namespace Acc{
 const int N=1e3+9;
 using db=long double;
 const db eps=1e-9;
 db C(int n,int m){
  db z=1;
  for(int i=0;i<m;++i)z*=(n-i)*1./(i+1);
  return z;
 }
 int n;
 db cal(int x){
  return (C(x,3)+C(x,2)*C(n-x,1)+C(x,1)*C(n-x,2)/2)/C(n,3);
 }
 void work(){
  int l=0,r,md,ans=-1;
  db p;
  for(cin>>n>>p,r=n;l<=r;)if(cal(md=l+r>>1)>=p-eps)r=md-1,ans=md;else l=md+1;
  assert(~ans),cout<<ans<<'\n';
 }
}
int main(){
 ios::sync_with_stdio(0),cin.tie(0);
 return Acc::work(),0;
}