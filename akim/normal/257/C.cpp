#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define pi M_PI
double z[100100];
void qsort(int l,int r)
{
 int i=l,f=r;
 double q=z[(l+r)/2];
 while(i<f)
 {
  while(z[i]<q){i++;}
  while(z[f]>q){f--;}
  if(i<=f){
           swap(z[i],z[f]);
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
 int n,i,x,y;
 cin>>n;
 for(i=0;i<n;i++)
 {
  cin>>x>>y;
  double db=sqrt(x*x+y*y),ax,ay;
  if(x>0&&y>=0){ax=1000;ay=0;z[i]=0;}
  if(x<=0&&y>0){ax=0;ay=1000;z[i]=90;}
  if(x<0&&y<=0){ax=-1000;ay=0;z[i]=180;}
  if(x>=0&&y<0){ax=0;ay=-1000;z[i]=270;}
  z[i]+=(acos(((ax*x)+(ay*y))/(db*1000))*180)/pi;
//  cout<<z[i]<<endl;
 }
 qsort(0,n-1);
 z[n]=z[0]+360;
 double nb=0;
 for(i=0;i<n;i++){if(z[i+1]-z[i]>nb){nb=z[i+1]-z[i];}}
 nb=360-nb;
 cout.precision(10);
 cout<<nb;
}