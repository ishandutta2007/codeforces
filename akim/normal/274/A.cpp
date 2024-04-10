#include <iostream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
int x[100100]={0};
bool y[100100]={0};
void qsort(int l,int r)
{
 int i=l,f=r,p=x[(l+r)/2];
 while(i<f)
 {
  while(x[i]<p){i++;}
  while(x[f]>p){f--;}
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
 int n,k,i;
 scanf("%d%d",&n,&k);
 for(i=0;i<n;i++){scanf("%d",&x[i]);}
 qsort(0,n-1);
 int l=0,q=n;
 for(i=0;i<n;i++)
 {
  if(x[i]%k==0)
  {
   while(x[l]<x[i]/k){l++;}
   if(x[l]==x[i]/k&&y[l]==1){q--;}else{y[i]=1;}
  }else{y[i]=1;}
 }
 printf("%d",q);
}