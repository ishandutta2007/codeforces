#include <algorithm>
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
int x[10100]={0};
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,m,i,f,ma=1,ma2=1;
 scanf("%d%d",&n,&m);
 for(i=1;i<n;i++){x[i]=1;}
 for(i=0;i<m;i++)
 {
  for(f=1;f<=n;f++)
  {
   printf("%d ",n-min(n-f-x[f],ma));
   x[f]+=x[n-min(n-f-x[f],ma)];
   ma2=max(ma2,x[f]);
//   printf("%d ",x[f]);
  }printf("\n");
  ma=ma2;
 }
}