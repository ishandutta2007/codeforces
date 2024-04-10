#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
long long x[100100],v[100100];
int pc[100100],pc1[100100],c[100100];
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int i,f,n,m;
 for(i=0;i<100100;i++){pc1[i]=-1;}
 long long a,b,ma,cma,mb,cmb;
 cin>>n>>m;
 for(i=0;i<n;i++){cin>>v[i];}
 for(i=0;i<n;i++){cin>>c[i];pc[i]=pc1[c[i]];pc1[c[i]]=i;}
 for(;m>0;m--)
 {
  cin>>a>>b;
  ma=0;cma=0;mb=0;cmb=0;
  for(i=0;i<n;i++)
  {
   if(pc[i]!=-1)
   {
    if(cma!=c[i]){x[i]=max(ma+v[i]*b,x[pc[i]]+v[i]*a);}
             else{x[i]=max(mb+v[i]*b,x[pc[i]]+v[i]*a);}
   }else{x[i]=ma+v[i]*b;}
   if(pc[i]!=-1&&x[i]<x[pc[i]]){x[i]=x[pc[i]];}
   if(x[i]>ma)
   {
    if(cma!=c[i])
    {
     mb=ma;
     cmb=cma;
    }
    ma=x[i];
    cma=c[i];
   }else
   if(x[i]>mb&&c[i]!=cma)
   {
    mb=x[i];
    cmb=c[i];
   }
  }
  cout<<ma<<"\n";
 }
}