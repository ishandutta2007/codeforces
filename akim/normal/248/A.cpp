#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
 int n,i,lo=0,lz=0,ro=0,rz=0,l,r;
 cin>>n;
 for(i=1;i<=n;i++)
 {
  cin>>l>>r;
  if(l){lz++;}else{lo++;}
  if(r){rz++;}else{ro++;}
 }
 cout<<min(min(lo+ro,lo+rz),min(lz+ro,lz+rz));
 return(0);
}