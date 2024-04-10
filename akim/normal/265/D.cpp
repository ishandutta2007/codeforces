#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
int x[100100][2]={0};
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int i,f;
 for(i=2;i<100100;i++)
 if(x[i][0]==0)
 {
  for(f=i;f<100100;f+=i)
  {
   x[f][0]=i;
  }
 }
 int n,p,r,q=1,ma;
 cin>>n;
 for(i=0;i<n;i++)
 {
  cin>>p;ma=1;
  r=p;
  while(r>1)
  {
   ma=max(x[x[r][0]][1]+1,ma);
   r/=x[r][0];
  }
  r=p;
  while(r>1)
  {
   x[x[r][0]][1]=ma;
   r/=x[r][0];
  }
  q=max(ma,q);
 }
 cout<<q;
}