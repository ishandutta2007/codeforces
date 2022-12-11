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
int x[100100]={0};
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int k1=0,k2=0,ko=0,n,m,i;
 scanf("%d%d",&n,&m);
 for(i=0;i<m;i++){int u,v;scanf("%d%d",&u,&v);x[u]++;x[v]++;}
 for(i=1;i<=n;i++)
 {
  if(x[i]==1){k1++;}else
  if(x[i]==2){k2++;}else
   ko++;
 }
 if(ko==1&&k2==0){printf("star topology");return(0);}
 if(ko==0&&k1==0){printf("ring topology");return(0);}
 if(k1==2&&ko==0){printf("bus topology");return(0);}
 printf("unknown topology");
}