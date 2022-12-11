#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
int x[100]={0};
void qsort(int l,int r)
{
 int i=l,f=r,z=x[(l+r)/2];
 while(i<f)
 {
  while(x[i]>z){i++;}
  while(x[f]<z){f--;}
  if(i<=f){
           swap(x[i],x[f]);
           i++;f--;
          }
 }
 if(l<f){qsort(l,f);}
 if(i<r){qsort(i,r);}
}
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,m,k,i;
 cin>>n>>m>>k;
 for(i=0;i<n;i++){cin>>x[i];}
 qsort(0,n-1);
 i=0;
 while(m>k&&i<n){k+=x[i]-1;i++;}
 if(m<=k){cout<<i;}else{cout<<"-1";}
}