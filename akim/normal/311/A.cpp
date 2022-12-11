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
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,k,i;
 scanf("%d%d",&n,&k);
 if((n*(n-1))/2<=k){printf("no solution");return(0);}
 printf("0 -1000000000\n");
 int x=0,y=-1000000000;
 for(i=1;i<n;i++)
 {x++;y+=2010;
  printf("%d %d\n",x,y);
 }
}